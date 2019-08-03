/*
 * wroom.h
 *
 *  Created on: 2019/03/14
 *      Author: jenoki
 */

#ifndef WROOM_H_
#define WROOM_H_

#include "ap.h"

#define WROOM_TX_BUFSIZE 64
#define WROOM_AT_BUFSIZE 64
#define WROOM_RX_BUFSIZE 64

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
#define AT_MULTI	"AT+CIPMUX=1\x0D\x0A"
#define AT_CONNAP	"AT+CWJAP_CUR=\"%s\",\"%s\"\x0D\x0A"
#define AT_CNHOST	"AT+CIPSTART=%d,\"TCP\",\"%s\",%d\x0D\x0A"
#define	AT_SERVER	"AT+CIPSERVER=1,%d\x0D\x0A"
#define AT_SEND		"AT+CIPSEND=%d,%d\x0D\x0A"
#define AT_PING		"AT+PING=\"%s\""

#define	AT_RX_IPD		"+IPD,"
#define AT_RESP_OK		"OK"
#define AT_OK_RXLEN		4	//include CRLF
#define AT_RESP_ERROR	"ERROR\x0D\x0A"
#define AT_PROMPT		">\x0D\x0A"
#define AT_PROMPT_RXLEN	3	//'>' + CRLF
#define AT_INIT_RXLEN	13	//include CRLF
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
void WROOM_SetState(uint8_t state);
void WROOM_Reset(bool flag);
void WROOM_Dispatch();

#endif /* WROOM_H_ */
