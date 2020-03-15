/**
 * @file	ssd1306.c
 * @brief	SSD1306 OLED Library Source.
 * @author	totally modified by jenoki
 * @copyright	MIT License
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 *
 * https://github.com/afiskon/stm32-ssd1306
 *
 */
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "ssd1306.h"
extern char Msg_Buffer[MSG_LINES][MSG_WIDTH + 1];
extern uint8_t Font8x16[];

/**
 * @brief SSD1306 OLED frame buffer
 */
static uint8_t Frame_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / BITS_PER_PAGE];

/**
 * @brief Write SSD1306 command register
 * @param cmd	:	command to write
 */
static inline void SSD1306_WriteCommand(uint8_t cmd) {
	HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, SSD1306_CMD, 1, &cmd, 1, HAL_MAX_DELAY);
}

/**
 * @brief Write SSD1306 data register
 * @param buffer	:	pointer to data buffer
 * @param buff_size	:	write size
 */
static inline void SSD1306_WriteData(uint8_t* buffer, size_t buff_size) {
	HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, SSD1306_DATA, 1, buffer, buff_size, HAL_MAX_DELAY);
}

/**
 * @brief Initialize SSD1306 OLED module
 */
void SSD1306_Initialize(void) {

    SSD1306_WriteCommand(CMD_DISPLAY_OFF); //display off

    SSD1306_WriteCommand(CMD_SET_ADDRESS_MD); //Set Memory Addressing Mode
    SSD1306_WriteCommand(VAL_HORIZON_ADDRSS); // 00b,Horizontal Addressing Mode; 01b,Vertical Addressing Mode;
                                // 10b,Page Addressing Mode (RESET); 11b,Invalid

    SSD1306_WriteCommand(CMD_SET_PAGE0); //Set Page Start Address for Page Addressing Mode,0-7

#ifdef SSD1306_MIRROR_VERT
    SSD1306_WriteCommand(CMD_SET_NON_VMIRROR); // Mirror vertically
#else
    SSD1306_WriteCommand(CMD_SET_VMIRROR); //Set COM Output Scan Direction
#endif

    SSD1306_WriteCommand(0x00); //---set low column address
    SSD1306_WriteCommand(0x10); //---set high column address

    SSD1306_WriteCommand(CMD_SET_START_LINE); //--set start line address - CHECK

    SSD1306_WriteCommand(CMD_SET_CONTRAST); //--set contrast control register - CHECK
    SSD1306_WriteCommand(VAL_CONTRAST_MAX);

#ifdef SSD1306_MIRROR_HORIZ
    SSD1306_WriteCommand(CMD_NON_MIRROR); // Mirror horizontally
#else
    SSD1306_WriteCommand(CMD_MIRROR); //--set segment re-map 0 to 127 - CHECK
#endif

#ifdef SSD1306_INVERSE_COLOR
    SSD1306_WriteCommand(CMD_INVERT); //--set inverse color
#else
    SSD1306_WriteCommand(CMD_NON_INVERT); //--set normal color
#endif

    SSD1306_WriteCommand(CMD_SET_MPX_RATIO); //--set multiplex ratio(1 to 64) - CHECK
    SSD1306_WriteCommand(VAL_MPX_RATIO_32L); //

    SSD1306_WriteCommand(CMD_REFLECT_FBUF); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

    SSD1306_WriteCommand(CMD_SET_VOFFSET); //-set display offset - CHECK
    SSD1306_WriteCommand(0x00); //-not offset

    SSD1306_WriteCommand(CMD_SET_OSCDIV); //--set display clock divide ratio/oscillator frequency
    SSD1306_WriteCommand(VAL_OSC_FREQ_MAX); //--set divide ratio

    SSD1306_WriteCommand(CMD_SET_PRECHARGE); //--set pre-charge period
    SSD1306_WriteCommand(VAL_PRECHG_DEFAULT); //

    SSD1306_WriteCommand(CMD_SET_COMCONFIG); //--set com pins hardware configuration - CHECK
    SSD1306_WriteCommand(VAL_COM_CONFIG_32L);

    SSD1306_WriteCommand(CMD_SET_VCOMH); //--set vcomh
    SSD1306_WriteCommand(VAL_VCOMH_DEFAULT); //0x20,0.77xVcc

    SSD1306_WriteCommand(CMD_SET_CHARGE_PUMP); //--set DC-DC enable
    SSD1306_WriteCommand(VAL_CHG_PUMP_ENABLE); //
    SSD1306_WriteCommand(CMD_DISPLAY_ON); //--turn on SSD1306 panel

    // Clear frame buffer
    SSD1306_ClearBuffer();

    // Flush screen with frame buffer
    SSD1306_FlashScreen();

}

/**
 * @brief Clear all of frame buffer
 * @param color	:	Color to fill (White or Black)
 */
void SSD1306_ClearBuffer() {
    for(size_t i = 0; i < sizeof(Frame_Buffer); i++) {
        Frame_Buffer[i] = SCREEN_BLANK;
    }
}

/**
 * @brief Update SSD1306 OLED screen with frame buffer
 */
void SSD1306_FlashScreen(void) {
    SSD1306_WriteData(Frame_Buffer, FB_SIZE);
    SSD1306_WriteData(Frame_Buffer, FB_SIZE);
}

/**
 * @brief Set screen on/off
 * @param on	:	true = Set display ON, false = Set display off
 */
void SSD1306_SetScreen(bool on){
	uint8_t cmd = (on)? CMD_DISPLAY_ON : CMD_DISPLAY_OFF;
    SSD1306_WriteCommand(cmd);
}

/**
 * @brief Render Msg_Buffer contents to frame buffer
 * @pre Sets up string contents to Msg_Buffer
 */
void SSD1306_Render2Buffer(void){
	for (uint8_t line = 0; line < MSG_LINES; line ++){
		for (uint8_t column = 0; column < MSG_WIDTH; column++){
			char ch = Msg_Buffer[line][column];
			if (ch == '\0') continue;	//process next line.

			uint8_t cindex = ch - FONT_PRINTABLE_START;
			uint16_t fb_top = (column * FONT_WIDTH) + (line * SSD1306_WIDTH *2);
			uint16_t font_top = (cindex * BYTES_PER_CHAR_DATA);

			for (uint8_t c = 0; c < FONT_WIDTH; c++){
				Frame_Buffer[fb_top + c ] = Font8x16[font_top + c];
				Frame_Buffer[fb_top + c + SSD1306_WIDTH] = Font8x16[font_top + c + FONT_WIDTH];
			}//Frame Buffer column Loop
		}//Msg_Buffer column Loop
	}//Msg_Buffer line Loop
}
void SSD1306_RenderBanner(char *string, int x, int y ,uint8_t op){
	uint8_t	page = y / BITS_PER_PAGE;
	if (page == MAX_PAGE) {
		page = MAX_PAGE -1;
	}
	int l = strlen(string);
	if ( ((l * FONT_WIDTH) + x) > SSD1306_WIDTH ){
		x = SSD1306_WIDTH - (FONT_WIDTH * l);
		if (x < 0) {
			x = 0;
		}
	}
	for (uint8_t i = 0; (string[i] != '\0' && i < 16); i++){
		uint8_t cindex = string[i] - FONT_PRINTABLE_START;
		uint16_t fb_top = (page * SSD1306_WIDTH) + x ;
		uint16_t font_top = (cindex * BYTES_PER_CHAR_DATA);
		for (uint8_t c = 0; c < FONT_WIDTH ;c++){
			uint8_t f1 = Font8x16[font_top + c];
			uint8_t f2 = Font8x16[font_top + c + FONT_WIDTH];
			if (op == INP){
				Frame_Buffer[fb_top + c ] = f1;
				Frame_Buffer[fb_top + c + SSD1306_WIDTH] = f2;
			} else if (op == XOR){
				Frame_Buffer[fb_top + c ] ^= f1;
				Frame_Buffer[fb_top + c + SSD1306_WIDTH] ^= f2;
			}
		}//Frame Buffer column Loop
	}//String Loop
}

