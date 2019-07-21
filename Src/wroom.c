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

uint8_t wroom_tx_buffer[WROOM_TX_BUFSIZE];
uint8_t wroom_rx_buffer[WROOM_RX_BUFSIZE];
uint16_t	rx_length;
uint8_t wroom_boot_state;
bool	wroom_isPassThru;

void WROOM_Initialize(){
	wroom_boot_state = WROOM_RESET;
	wroom_isPassThru = false;
	isWROOMDataExists = false;
}

void WROOM_Reset(bool flag){
	HAL_GPIO_WritePin(WL_RST_GPIO_Port,WL_RST_Pin,(flag)? GPIO_PIN_RESET:GPIO_PIN_SET);
}

//when goes to next stage call this func.
void WROOM_Set_boot_state(uint8_t state){
	if(state == WROOM_INIT){
		strcpy((char*)wroom_tx_buffer, AT_INIT);
		rx_length = AT_ATE0_RXLEN+7;
	}else if (state == SET_STA) {
		strcpy((char*)wroom_tx_buffer, AT_MODE);
		rx_length = AT_OK_RXLEN;
	} else if(state == CON_AP) {
		sprintf((char*)wroom_tx_buffer,AT_CONNAP, SSID, PASSWD);
		rx_length = AT_OK_RXLEN;
	} else if(state == CON_IP) {
		sprintf((char*)wroom_tx_buffer,AT_CNHOST, LrHOST, SEND_PORT);
		rx_length = AT_OK_RXLEN;
	} else if(state == SET_PASSTHRU) {
		strcpy((char*)wroom_tx_buffer, AT_PATHR);
	} else if(state == SET_SEND){
		strcpy((char*)wroom_tx_buffer, AT_SEND);
	} else if(state == PASSTHRU){
		wroom_isPassThru = true;
		return;	//Do Nothing
	} else {//some error
		return;
	}
	HAL_UART_Receive_DMA(&huart1, wroom_rx_buffer, rx_length);

	uint16_t tx_length = strlen((char*)wroom_tx_buffer);
	HAL_UART_Transmit_DMA(&huart1, wroom_tx_buffer, tx_length);

	wroom_boot_state = state;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart){
	isWROOMDataExists = true;
}

void WROOM_Dispatch(){
#if 0
	uint8_t *endp = (uint8_t *)strchr((char*)wroom_rx_buffer,CR);
	if (endp != NULL) *endp = NUL;
#endif
	if( wroom_isPassThru == false ){//in WROOM boot-up mode
		if( strstr((char*)wroom_rx_buffer,AT_RESP_OK) ){
			switch(wroom_boot_state){
				case WROOM_INIT:
					LCD_Locate(0,0);
					LCD_Print("WRM Con.");
					LCD_SetBackLight(LCD_BL_ON);
					Start_LCDTimer(LCD_TIMER_UPDATE);
					WROOM_Set_boot_state(SET_STA);
					break;
				case SET_STA:
					LCD_Locate(0,0);
					LCD_Print("SET STA.");
					LCD_SetBackLight(LCD_BL_ON);
					Start_LCDTimer(LCD_TIMER_UPDATE);
					WROOM_Set_boot_state(CON_AP);
					break;
				case CON_AP:
					LCD_Locate(0,0);
					LCD_Print("AP Conn.");
					LCD_SetBackLight(LCD_BL_ON);
					Start_LCDTimer(LCD_TIMER_UPDATE);
					WROOM_Set_boot_state(CON_IP);
					break;
				case CON_IP:
					LCD_Locate(0,0);
					LCD_Print("TCP Con.");
					LCD_SetBackLight(LCD_BL_ON);
					Start_LCDTimer(LCD_TIMER_UPDATE);
					WROOM_Set_boot_state(SET_PASSTHRU);
					break;
				case SET_PASSTHRU:
					LCD_Locate(0,0);
					LCD_Print("PASSTHRU");
					LCD_SetBackLight(LCD_BL_ON);
					Start_LCDTimer(LCD_TIMER_UPDATE);
					WROOM_Set_boot_state(SET_SEND);
					break;
				default:
					break;
			}
		}else if ( wroom_boot_state==SET_SEND && strcmp((char*)wroom_rx_buffer,AT_RESP_PASSTHRU) ){
			WROOM_Set_boot_state(PASSTHRU);
		}else{
			HAL_UART_Receive_DMA(&huart1, wroom_rx_buffer, rx_length);
		}// any else , do nothing.
	}else{ //in WROOM Pass-through mode

	}
}


void WROOM_GPIO_Initialize(){
	HAL_UART_Transmit_DMA(&huart1, (uint8_t *)AT_GPIO5CFG, AT_GPIO5CFGLEN);
	HAL_Delay(100);
	HAL_UART_Transmit_DMA(&huart1, (uint8_t *)AT_GPIO5DIR, 19);
}

//Set LED on WROOM GPIO5
void WROOM_SetLED(bool flag){
	strcpy((char*)wroom_tx_buffer, AT_GPIO5WRITE);
	if (flag) {
		wroom_tx_buffer[(AT_GPIO5WRTLEN -3)] = '0';
	}
	HAL_UART_Transmit_DMA(&huart1, wroom_tx_buffer, AT_GPIO5WRTLEN);
}
