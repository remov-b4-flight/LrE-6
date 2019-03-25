/*
 * wroom.h
 *
 *  Created on: 2019/03/14
 *      Author: jenoki
 */

#ifndef WROOM_H_
#define WROOM_H_
#include "main.h"
#define WROOM_TX_BUFSIZE 100
#define WROOM_RX_BUFSIZE 100

#define	SEND_PORT	58763

#define	DELM1	"="
#define DELM2	","
#define PASTRU_STOP	"+++"

#define AT_MODE		"AT+CWMODE=1\x0D\x0A"
#define AT_HOSTNAME "AT+CWHOSTNAME=" LrE6_PRODUCT "\x0D\x0A"
#define AT_CONNAP	"AT+CWJAP_CUR=\"%s\",\"%s\"\x0D\x0A"
#define AT_DHCP		"AT+CWDHCP_CUR=1,1\x0D\x0A"
#define AT_CNHOST	"AT+CIPSTART=TCP,\"%s\",\"%d\"\x0D\x0A"
#define AT_PATHR	"AT+CIPMODE=1\x0D\x0A"
#define AT_SEND		"AT+CIPSEND\x0D\x0A"

//wroom initialize state
enum {
	SET_STA = 0,	//Connect with WROOM
	CON_AP,			//Connect with AP
	CON_IP,			//Connect with port on host
	SET_PATHR,		//Set to pass thru
	SET_SEND,		//Set to send data
	PASSTHRU		//Entered pass thru
};

void WROOM_initialize(void);
void WROOM_set_boot_state(uint8_t state);


#endif /* WROOM_H_ */
