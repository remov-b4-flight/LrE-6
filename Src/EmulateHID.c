/*
 * @file	EmulateHID.c
 * @brief	functions used in HID keyboard build.
 *  Created on: 2019/12/24
 *      Author: jenoki
 */
//
#include <stdbool.h>
#include "main.h"
#include "usbd_hid.h"
#include "led.h"
#include "i2c-lcd.h"
#include "usbd_hid.h"
#include "bitcount.h"
#include "key_define.h"
#include "EmulateHID.h"

//
extern	bool	isKeyPressed;
extern	int32_t	LCD_Timer_Count;
extern	bool	LCD_Off_Flag;
extern	bool	LCD_Timer_Enable;
extern	bool	isLCDflash;
extern	USBD_HandleTypeDef	hUsbDeviceFS;
extern	KEYSCAN	Key_Stat;
extern	char LCD_Buffer[LCD_LINE][LCD_LINEBUF_SIZE];

extern	HID_DEFINE keytable[];
KEY_MODIFIER modifiers[KEY_COUNT];
KEYBOARD_INPUT_REPORT	In_Report;

inline void LCD_Print(){
	isLCDflash = true;
}

/**
 *	@brief	Generate HID packet and Send to host by User interaction.
 */
bool EmulateKeyboard(void) {
    uint32_t rkey;
    uint8_t bitpos;
    bool isKeyReport;

    if (isKeyPressed) {
        bitpos = ntz32(Key_Stat.wd);
        rkey = (Key_Stat.wd & MOD_SW_BIT_MASK);
        if ( bitpos < KEY_COUNT + (2 * ROT_COUNT) ){
#if 0
        	if(modifiers[bitpos].element[0] != HID_NONM) SendModifiers(bitpos);
#endif

        	In_Report.modifier = keytable[bitpos].modifier;
            In_Report.keys[HID_RPT_KEY_IDX] = keytable[bitpos].keycode;
            if (keytable[bitpos].message != NULL) {
        		LCD_Locate(0,0);
            	LCD_Off_Flag = false;
        		LCD_Timer_Enable = true;
            	LCD_Timer_Count = LCD_TIMER_DEFAULT;
            	LCD_SetBackLight(LCD_BL_ON, LED_BL_STATIC);
                strcpy(LCD_Buffer[0], keytable[bitpos].message);
                memset(LCD_Buffer[1],SPACE,LCD_WIDTH);
            	LCD_Print();
            }
            LED_SetPulse(LED_IDX_ENC0,LED_COLOR_YELLOW,25);

            isKeyReport = true;
		}else if (rkey == 0) {// Keys are released
			In_Report.modifier = In_Report.keys[HID_RPT_KEY_IDX] = HID_NONE;
			isKeyReport = true;
        }else
        	isKeyReport = false;

        if (isKeyReport) {
        	USBD_HID_HandleTypeDef *hhid = hUsbDeviceFS.pClassData;
        	while ( hhid->state != HID_IDLE ){
        		Delay_us(100);
        	}
			USBD_HID_SendReport(&hUsbDeviceFS,(uint8_t *)&In_Report,sizeof(KEYBOARD_INPUT_REPORT) );
			isKeyReport = false;
        }

        /* Clear the switch pressed flag */
        isKeyPressed = false;
        return true;
    } else
        return false;
}

