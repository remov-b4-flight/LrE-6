/*
 * wroom.c
 *
 *  Created on: 2019/03/20
 *      Author: jenoki
 */

#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "wroom.h"
#include "i2c-lcd.h"

extern UART_HandleTypeDef huart1;
extern bool		isWROOMDataExists;

uint8_t wroom_at_buffer[WROOM_AT_BUFSIZE];
uint8_t wroom_tx_buffer[WROOM_TX_BUFSIZE];
uint8_t wroom_rx_buffer[WROOM_RX_BUFSIZE];
uint16_t	rx_length;
uint8_t wroom_state;
uint8_t	*pwroom_tx;

void WROOM_Initialize(){
	wroom_state = WROOM_RESET;
	isWROOMDataExists = false;
	pwroom_tx = wroom_at_buffer;
}

void WROOM_Reset(bool flag){
	HAL_GPIO_WritePin(WL_RST_GPIO_Port,WL_RST_Pin,(flag)? GPIO_PIN_RESET:GPIO_PIN_SET);
}

void WROOM_GPIO_Initialize(){
	HAL_UART_Transmit_DMA(&huart1, (uint8_t *)AT_GPIO5CFG, AT_GPIO5CFGLEN);
	HAL_Delay(100);
	HAL_UART_Transmit_DMA(&huart1, (uint8_t *)AT_GPIO5DIR, 19);
}

//when goes to next stage call this func.
void WROOM_SetState(uint8_t state){
	if(state == WROOM_INIT){
		strcpy((char*)wroom_at_buffer, AT_INIT);
		rx_length = AT_INIT_RXLEN+7;
	}else if (state == SET_STA) {
		strcpy((char*)wroom_at_buffer, AT_MODE);
		rx_length = AT_OK_RXLEN;
	} else if(state == SET_MUX) {
		strcpy((char*)wroom_at_buffer, AT_MULTI);
		rx_length = AT_OK_RXLEN;
	} else if(state == CON_AP) {
		sprintf((char*)wroom_at_buffer,AT_CONNAP, SSID, PASSWD);
		rx_length = AT_OK_RXLEN;
	} else if(state == CON_IP) {
		sprintf((char*)wroom_at_buffer,AT_CNHOST, AT_LINKID, LrHOST, SENDTO_PORT);
		rx_length = AT_OK_RXLEN;
	} else if(state == SET_SEND){
		uint8_t length = strlen((char *)wroom_at_buffer);
		sprintf((char *)wroom_at_buffer,AT_SEND, AT_LINKID, length);
		rx_length = AT_PROMPT_RXLEN;
	} else if(state == SEND_CONT){
		rx_length = AT_SENDOK_RXLEN;
		pwroom_tx = wroom_tx_buffer;
	} else {//some error
		return;
	}
	HAL_UART_Receive_DMA(&huart1, wroom_rx_buffer, rx_length);

	uint16_t tx_length = strlen((char*)pwroom_tx);
	HAL_UART_Transmit_DMA(&huart1, pwroom_tx, tx_length);

	pwroom_tx = wroom_at_buffer;
	wroom_state = state;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart){
	isWROOMDataExists = true;
}

void WROOM_Dispatch(){
	if( strstr((char*)wroom_rx_buffer,AT_RESP_OK) ){
		switch(wroom_state){
			case WROOM_INIT:
				LCD_Locate(0,0);
				LCD_Print("WRM Con.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(SET_STA);
				break;

			case SET_STA:
				LCD_Locate(0,0);
				LCD_Print("SET STA.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(SET_MUX);
				break;

			case SET_MUX:
				LCD_Locate(0,0);
				LCD_Print("SET MUX.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(CON_AP);
				break;

			case CON_AP:
				LCD_Locate(0,0);
				LCD_Print("AP Conn.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(CON_IP);
				break;

			case CON_IP:
				LCD_Locate(0,0);
				LCD_Print("TCP Con.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(SET_SVR);
				break;

			case SET_SVR:
				LCD_Locate(0,0);
				LCD_Print("SET SVR");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(IDLE);
				break;

			case SEND_CONT:	//STM32 got 'SEND OK'+CRLF
				LCD_Locate(0,0);
				LCD_Print("SENT.");
				LCD_SetBackLight(LCD_BL_ON);
				Start_LCDTimer(LCD_TIMER_UPDATE);
				WROOM_SetState(IDLE);

			default:
				break;
		}
	}else if(strstr((char *)wroom_rx_buffer,AT_RESP_ERROR)){
		LCD_Locate(0,0);
		LCD_Print("ERROR");
		LCD_SetBackLight(LCD_BL_ON);
		Start_LCDTimer(LCD_TIMER_UPDATE);
	}else if (strstr((char *)wroom_rx_buffer,AT_PROMPT) && wroom_state == SET_SEND){
		WROOM_SetState(SEND_CONT);
	}else if (strstr((char*)wroom_rx_buffer,AT_RX_IPD) && wroom_state == IDLE){
		//incoming IP
	}else if(strstr((char *)wroom_rx_buffer,AT_RX_CLOSED)){
		LCD_Locate(0,0);
		LCD_Print("DISCONN.");
		LCD_SetBackLight(LCD_BL_ON);
		Start_LCDTimer(LCD_TIMER_UPDATE);
		WROOM_SetState(SET_STA);
	}else if(strstr((char *)wroom_rx_buffer,AT_RX_CONNECT)){
		WROOM_SetState(wroom_state);
	}else{
		HAL_UART_Receive_DMA(&huart1, wroom_rx_buffer, rx_length);
	}// any else , do nothing.
}

void WROOM_Send(const char *string){
	strcpy((char *)wroom_tx_buffer,string);
	WROOM_SetState(SET_SEND);
}

//Set LED on WROOM GPIO5
void WROOM_SetLED(bool flag){
	strcpy((char*)wroom_at_buffer, AT_GPIO5WRITE);
	if (flag){
		wroom_at_buffer[(AT_GPIO5WRTLEN -3)] = '0';
	}
	HAL_UART_Transmit_DMA(&huart1, wroom_at_buffer, AT_GPIO5WRTLEN);
}
