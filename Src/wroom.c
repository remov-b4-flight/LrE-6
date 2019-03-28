/*
 * wroom.c
 *
 *  Created on: 2019/03/20
 *      Author: jenoki
 */

#include <main.h>
extern UART_HandleTypeDef huart1;
extern bool		isWROOMDataExists;

uint8_t wroom_tx_buffer[WROOM_TX_BUFSIZE];
uint8_t wroom_rx_buffer[WROOM_RX_BUFSIZE];
uint8_t wroom_boot_state;
bool	wroom_isPassThru;

void WROOM_initialize(){
	wroom_boot_state = WROOM_RESET;
	wroom_isPassThru = false;
	isWROOMDataExists = false;
	huart1.Instance->CR1 |= UART_MASK_IDLE;	//Enable IDLEIE
	huart1.Instance->ICR |= UART_MASK_IDLE;
}

//when goes to next stage call this func.
void WROOM_set_boot_state(uint8_t	state){

	if (state == SET_STA) {
		strcpy((char*)wroom_tx_buffer, AT_MODE);
	} else if(state == CON_AP) {
		sprintf((char*)wroom_tx_buffer,AT_CONNAP, SSID, PASSWD);
	} else if(state == CON_IP) {
		sprintf((char*)wroom_tx_buffer,AT_CNHOST, LrHOST, SEND_PORT);
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
	uint16_t len = strlen((char*)wroom_tx_buffer);
	HAL_UART_Transmit_DMA(&huart1, wroom_tx_buffer, len);
	HAL_UART_Receive_DMA(&huart1, wroom_rx_buffer, WROOM_RX_BUFSIZE);
	wroom_boot_state = state;

}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart){
	isWROOMDataExists = true;
}

void WROOM_dispatch(UART_HandleTypeDef* huart){
	uint8_t *endp = (uint8_t *)strchr((char*)wroom_rx_buffer,CR);
	*endp = NUL;
	if( wroom_isPassThru == false ){//in WROOM boot-up mode
		if( strcmp((char*)wroom_rx_buffer,AT_RESP_OK) ){
			switch(wroom_boot_state){
				case SET_STA:
					WROOM_set_boot_state(CON_AP);
					break;
				case CON_AP:
					WROOM_set_boot_state(CON_IP);
					break;
				case CON_IP:
					WROOM_set_boot_state(SET_PASSTHRU);
					break;
				case SET_PASSTHRU:
					WROOM_set_boot_state(SET_SEND);
					break;
				default:
					break;
			}
		}else if ( wroom_boot_state==SET_SEND && strcmp((char*)wroom_rx_buffer,AT_RESP_PASSTHRU) ){
			WROOM_set_boot_state(PASSTHRU);
		}else if ( wroom_boot_state==WROOM_RESET && strcmp((char*)wroom_rx_buffer,AT_RESP_READY) ){
			WROOM_set_boot_state(SET_STA);
		}// any else , do nothing.
	}else{ //in WROOM Pass-through mode

	}
	isWROOMDataExists = false;
}
