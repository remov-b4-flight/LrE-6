/*
 * @file	EmulateHID.h
 *
 *  Created on: 2019/12/24
 *      Author: jenoki
 */

#ifndef EMULATEHID_H_
#define EMULATEHID_H_

#define HID_DEFINE_COUNT	32
#define HID_RPT_KEY_IDX		1

/* Exported types ------------------------------------------------------------*/
typedef struct {
	uint8_t element[4];
} KEY_MODIFIER;

typedef struct {
	uint8_t modifier;
	uint8_t keycode;
	char	*message;
} HID_DEFINE;

//Moved From Harmony keyboard.h
typedef struct {
	uint8_t	modifier;
	uint8_t keys[4];
} KEYBOARD_INPUT_REPORT;

#endif /* EMULATEHID_H_ */
