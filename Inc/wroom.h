/*
 * wroom.h
 *
 *  Created on: 2019/03/14
 *      Author: jenoki
 */

#ifndef WROOM_H_
#define WROOM_H_

//Connection parameter
#define SSID "***REMOVED***"
#define PASSWD "***REMOVED***"
#define LrHOST "***REMOVED***"
//

#define WROOM_TX_BUFSIZE 100
#define WROOM_RX_BUFSIZE 100

#define	SEND_PORT	58763



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
#define AT_CNHOST	"AT+CIPSTART=TCP,\"%s\",\"%d\"\x0D\x0A"
#define AT_PATHR	"AT+CIPMODE=1\x0D\x0A"
#define AT_SEND		"AT+CIPSEND\x0D\x0A"

#define AT_GPIO5CFG		"AT+SYSIOSETCFG=5,1,0\x0D\x0A"
#define AT_GPIO5CFGLEN	22
#define AT_GPIO5DIR		"AT+SYSGPIODIR=5,1\x0D\x0A"
#define AT_GPIO5DIRLEN	19
#define AT_GPIO5WRITE	"AT+SYSGPIOWRITE=5,1\x0D\x0A"
#define AT_GPIO5WRTLEN	21

#define AT_RESP_OK	"OK"
#define AT_OK_RXLEN		4	//include CRLF
#define AT_ATE0_RXLEN	6	//include CRLF

#define AT_RESP_PASSTHRU ">"
//#define AT_RESP_READY	"ready"

//wroom initialize state
enum {
	WROOM_RESET = 0,
	WROOM_INIT,		//Initialize WROOM
	SET_STA,		//Connect with WROOM
	CON_AP,			//Connect with AP
	CON_IP,			//Connect with port on host
	SET_PASSTHRU,	//Set to pass thru
	SET_SEND,		//Set to send data
	PASSTHRU		//Entered pass thru
};

void WROOM_Initialize(void);
void WROOM_Set_boot_state(uint8_t state);
void WROOM_Reset(bool flag);
void WROOM_Dispatch();

#endif /* WROOM_H_ */
