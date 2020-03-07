/**
 * 	@file i2c-lcd.h
 *	@brief LCD control functions connected via I2C
 *	@copyright	GPLv3
 */

#ifndef I2C_LCD_H    /* Guard against multiple inclusion */
#define _I2C_LCD_H

/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/* Exported macro ------------------------------------------------------------*/
#define LCD_I2C_ADDR        0x7C    // write only
#define LCD_I2C_INST        0
#define LCD_I2C_DATA        0x40
#define LCD_I2C_CONTINUE    0x80
#define LCD_I2C_TAIL        0
#define LCD_I2C_WRITE       0

//LCD CMD/DATA Wait timings
#define LCD_CMD_WAIT_US		28
#define LCD_DAT_WAIT_US		28
#define LCD_CLR_WAIT_US		1100
#define LCD_PWRUP_WAIT_MS	45
#define LCD_FLW_WAIT_MS		220

#define	LCD_TRANSMIT_TO		250
/***************************** LCD Commands ************************************/
/* NORMAL instruction                                                          */

//**** CLEAR DISPLAY
#define LCD_CMD_CLEAR       0x01

//**** RETURN HOME
#define LCD_CMD_HOME        0x02
//**** ENTRY?MODE
#define LCD_CMD_ENTRY       0x04
//parameters
#define LCD_RMOVE           0x02
#define LCD_LMOVE           0x00
#define LCD_SHIFT           0x01

//**** DISPLAY ON
#define LCD_CMD_ONOFF       0x08
//parameters
#define LCD_DISPLAY_ON      0x04
#define LCD_CURSOR_ON       0x02
#define LCD_BLINK_ON        0x01

//**** CURSOR & DISPLAY SHIFT MODE SET
#define LCD_CURSOR_SHIFT    0x10
    
//**** SET FUNCTION
#define LCD_CMD_FUNC        0x20
//parameters
#define LCD_IF_8BIT         0x10
#define LCD_2LINE           0x08
#define LCD_1LINE           0x00
#define LCD_NORMAL_INST     0x00
#define LCD_EXT_INST        0x01

//**** SET CGRAM ADDRESS
#define LCD_CMD_CGADR       0x40
//**** SET DDRAM ADDRESS
#define LCD_CMD_DDADR       0x80

/*-----------------------------------------------------------------------------*/
/* EXTENDED instruction                                                        */

//**** SET LCD INTERNAL FREQ.
#define LCD_CMD_FREQ        0x10
//parameters    
#define LCD_BIAS            0x08   
#define LCD_CLK_183K        0x04
#define LCD_CLK_347K        0x07    
//**** SET LCD CONTRAST
#define LCD_CMD_CONTRAST    0x70    
//parameter
#define LCD_CONTRAST        0x01

//**** SET ICON
#define LCD_CMD_ICON        0x50
//parameter
#define LCD_BOOST           0x04
#define LCD_CONT_H          0x02

//**** FOLLOWER CONTROL
#define LCD_CMD_FOLLOWER    0x6C    //Follower on,Rab[2-0]=4

//
#define LCD_DD_PER_LINE     0x40
#define LCD_WIDTH           8
#define	LCD_LINE			2

//LED BackLight
#define LCD_BL_ON			true
#define LCD_BL_OFF			false
#define LED_BL_STATIC		0

//CGRAM constants
#define LCD_CGRAM_MAX		5
#define LCD_CGRAM_BYTES		8
#define	LCD_CGRAM_MASK		0x1F

enum {
	LCD_LINE0 = 0,
	LCD_LINE1 = 1,
};
#define SPACE				0x20
#define STRING_PAD			4

#define	LCD_LINEBUF_SIZE	(LCD_WIDTH + STRING_PAD)

/* Exported functions prototypes ---------------------------------------------*/
void LCD_Initialize();
void LCD_Clear();
void LCD_Home();
void LCD_SetDisplay(bool on, bool cursor, bool blink);
void LCD_Locate(uint8_t column, uint8_t line);
void LCD_Putchar(char c);
void LCD_SetBackLight(bool light, uint16_t cycle);
void LCD_SetCGRAM(uint8_t code, const uint8_t *pattern);
void LCD_SetDDADR(uint8_t address);
void LCD_Flash();
void LCD_Print_Quick(const char *str);

/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _I2C_LCD_H */

/* *****************************************************************************
 End of File
 */