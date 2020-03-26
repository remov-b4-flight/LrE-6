/**
 * 	@file i2c-lcd.c
 *	@brief LCD control functions connected via I2C
 *	@copyright	GPLv3
 */
/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>
#include "main.h"
#include "i2c-lcd.h"

/* Variables -----------------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim2;
char LCD_Buffer[LCD_LINE][LCD_LINEBUF_SIZE];
uint8_t i2cbuf[LCD_LINEBUF_SIZE * 2];
/* User code -----------------------------------------------------------------*/
/**
 * @brief	Initialize of LCD
 */
void LCD_Initialize(){
    uint8_t buf[2];
    
    memset(LCD_Buffer, SPACE, (LCD_LINEBUF_SIZE * 2) );

    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
    buf[1] = LCD_CMD_FUNC | LCD_IF_8BIT | LCD_2LINE | LCD_NORMAL_INST;
    HAL_I2C_Master_Transmit(&hi2c1,LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    //Go to Extended Instruction sets.
    buf[1] = LCD_CMD_FUNC | LCD_IF_8BIT | LCD_2LINE | LCD_EXT_INST;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_FREQ | LCD_CLK_347K;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_CONTRAST | LCD_CONTRAST;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_ICON | LCD_BOOST | LCD_CONT_H;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_FOLLOWER;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    HAL_Delay(LCD_FLW_WAIT_MS);
    
    //Revert to normal instruction sets
    buf[1] = LCD_CMD_FUNC | LCD_IF_8BIT | LCD_2LINE | LCD_NORMAL_INST;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_ONOFF | LCD_DISPLAY_ON;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);

    buf[1] = LCD_CMD_CLEAR;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR,buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CLR_WAIT_US);

}

/**
 *	@brief Clear LCD
 */
void LCD_Clear(){
    uint8_t buf[2];
    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
    buf[1] = LCD_CMD_CLEAR;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);
}

/**
 * 	@brief Locate cursor
 * 	@param	column
 * 	@param	line 0:upper 1:lower
 */
void LCD_Locate(uint8_t column,uint8_t line){
    uint8_t buf[2];
    uint8_t ddadr = (line * LCD_DD_PER_LINE) + column;
    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
    buf[1] = LCD_CMD_DDADR | ddadr;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);
}

void LCD_SetDisplay(bool on, bool cursor, bool blink){
    uint8_t buf[2];
    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
    buf[1] = LCD_CMD_ONOFF | (on)? LCD_DISPLAY_ON:0 | (cursor)? LCD_CURSOR_ON:0 | (blink)? LCD_BLINK_ON:0 ;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);
}

/**
 *	@brief Put character on LCD
 *	@param	c	character to print.
 */
void LCD_Putchar(char c){
    uint8_t buf[2];
    buf[0] = LCD_I2C_TAIL | LCD_I2C_DATA | LCD_I2C_WRITE;
    buf[1] = c;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
    Delay_us(LCD_DAT_WAIT_US);
}

/**
 * @brief Flash LCD screen.
 */
void LCD_Flash(){
	LCD_Locate(0, LCD_LINE0);
	LCD_Print_Quick(LCD_Buffer[LCD_LINE0]);
	LCD_Locate(0, LCD_LINE1);
	LCD_Print_Quick(LCD_Buffer[LCD_LINE1]);
}

/**
 * @brief Print LCD Message Immediately
 * @param str	string to print
 */
void LCD_Print_Quick(const char *str){
	const uint8_t len = LCD_WIDTH;
    const int8_t cmd= LCD_I2C_CONTINUE | LCD_I2C_DATA | LCD_I2C_WRITE;    // =0xC0;
    uint8_t *p = i2cbuf;

    for(uint8_t i = 0; i < (len-1); i++){
        *p++ = cmd;
        *p++ = str[i];
    }
    *p++ = LCD_I2C_TAIL | LCD_I2C_DATA | LCD_I2C_WRITE;    // =0x40;
    *p = str[len-1];

    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, i2cbuf, (len * 2), LCD_TRANSMIT_TO);
    Delay_us(LCD_DAT_WAIT_US);
}

/**
 *	@brief	Set LCD Back-light status wheather ON or OFF.
 *	@param	light	true:backlight on	false:off
 *	@param	cycle	LED pulse width.(LED_BL_STATIC = constant)
 */
void LCD_SetBackLight(bool light, uint16_t cycle){
	TIM_OC_InitTypeDef sConfigOC;
	sConfigOC.OCMode = TIM_OCMODE_PWM2;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

	if (light == true ){
		if (cycle == LED_BL_STATIC){
			sConfigOC.Pulse = 0;
		}else{
			sConfigOC.Pulse = cycle;
		}
	}else{
		sConfigOC.OCMode = TIM_OCMODE_FORCED_INACTIVE;
	}
	HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

/**
 *	@brief Set CGRAM content to use 'user defined' character
 *	@param code		character code set to CGRAM.
 *	@param *pattern	bitmap character pattern.
 */
void LCD_SetCGRAM(uint8_t code, const uint8_t *pattern){
	if(code <= LCD_CGRAM_MAX){
		uint8_t buf[LCD_CGRAM_BYTES * 2], *p = buf;
		uint8_t offset = code * 8;

		//Set CGRAM address
	    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
	    buf[1] = LCD_CMD_CGADR + offset;
	    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, 2, LCD_TRANSMIT_TO);
	    Delay_us(LCD_CMD_WAIT_US);

	    uint8_t cmd= LCD_I2C_CONTINUE | LCD_I2C_DATA | LCD_I2C_WRITE;    // =0xC0;

	    for(uint8_t i = 0; i < (LCD_CGRAM_BYTES-1); i++ ){
			*p++ = cmd;
			*p++ = pattern[i] & LCD_CGRAM_MASK;
		}
		*p++ = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
		*p++ = pattern[(LCD_CGRAM_BYTES-1)];

		HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, sizeof(buf), LCD_TRANSMIT_TO);
	    Delay_us(LCD_CMD_WAIT_US);

	}
}

/**
 *	@brief	Set DDRAM address to set location
 *	@param	address	Data Display RAM address to print character
 */
void LCD_SetDDADR(uint8_t address){
    uint8_t buf[2];

    buf[0] = LCD_I2C_TAIL | LCD_I2C_INST | LCD_I2C_WRITE;
    buf[1] = LCD_CMD_DDADR + address;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR, buf, 2, LCD_TRANSMIT_TO);
    Delay_us(LCD_CMD_WAIT_US);
}

/* ******************************************************* **** END OF FILE****/
