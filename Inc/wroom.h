/*
 * wroom.h
 *
 *  Created on: 2019/03/14
 *      Author: jenoki
 */

#ifndef WROOM_H_
#define WROOM_H_

#include "ap.h"

#define WROOM_TX_BUFSIZE 50
#define WROOM_AT_BUFSIZE 30
#define WROOM_RX_BUFSIZE 50

#define	SENDTO_PORT	58763
#define LITHEN_PORT	58764

#define	DELM1	"="
#define DELM2	","
#define PASSTHRU_STOP	"+++"
#define CR		0x0D
#define	LF		0x0A
#define	NUL		0x00

#define AT_INIT		"ATE0\x0D\x0A"
#define AT_MODE		"AT+CWMODE_CUR=1\x0D\x0A"
//#define AT_HOSTNAME "AT+CWHOSTNAME=" LrE6_PRODUCT "\x0D\x0A"
#define AT_CONNAP	"AT+CWJAP_CUR=\"%s\",\"%s\"\x0D\x0A"
#define AT_DHCP		"AT+CWDHCP_CUR=1,1\x0D\x0A"
#define AT_CNHOST	"AT+CIPSTART=%d,\"TCP\",\"%s\",%d\x0D\x0A"
#define AT_PATHR	"AT+CIPMODE=1\x0D\x0A"
#define AT_SEND		"AT+CIPSEND=%d,%d\x0D\x0A"
#define	AT_SERVER	"AT+CIPSERVER=1,%d\x0D\x0A"
#define AT_MULTI	"AT+CIPMUX=1"

#define AT_GPIO5CFG		"AT+SYSIOSETCFG=5,1,0\x0D\x0A"
#define AT_GPIO5CFGLEN	22
#define AT_GPIO5DIR		"AT+SYSGPIODIR=5,1\x0D\x0A"
#define AT_GPIO5DIRLEN	19
#define AT_GPIO5WRITE	"AT+SYSGPIOWRITE=5,1\x0D\x0A"
#define AT_GPIO5WRTLEN	21

#define	AT_RX_IPD		"+IPD,"
#define AT_RESP_OK		"OK"
#define AT_OK_RXLEN		4	//include CRLF
#define AT_RESP_ERROR	"ERROR\x0D\x0A"
#define AT_PROMPT		">\x0D\x0A"
#define AT_PROMPT_RXLEN	3	//'>' + CRLF
#define AT_INIT_RXLEN	6	//include CRLF
#define AT_SENDOK_RXLEN	9	//'SEND OK' + CRLF

#define AT_RX_CLOSED	"0,CLOSED"
#define AT_LINKID		0
#define AT_RX_CONNECT	"0,CONNECT"

//#define AT_RESP_READY	"ready"

//wroom initialize state
enum {
	WROOM_RESET = 0,
	WROOM_INIT,	//Initialize WROOM
	SET_STA,	//Connect with WROOM
	CON_AP,		//Connect with AP
	SET_MUX,	//Set Multiple connect mode
	CON_IP,		//Connect to port at remote host
	SET_SVR,	//Set up listen port
	IDLE,
	SET_SEND,
	SEND_CONT

};

void WROOM_Initialize(void);
void WROOM_Set_boot_state(uint8_t state);
void WROOM_Reset(bool flag);
void WROOM_Dispatch();

#endif /* WROOM_H_ */
