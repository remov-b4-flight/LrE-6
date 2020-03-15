/**
 * @file	ssd1306_fonts.c
 * @brief	SSD1306 OLED library font data.
 * @author	modified by jenoki
 * @copyright	MIT License for STM-SSD1306 Library
 * @copyright	MIT License for OLED_SSD106 Library
 * @note	Font data are taken from OLED_1306 Library,
 * That was modified for use with STM32-SSD1306 Library.
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 *
 * https://github.com/afiskon/stm32-ssd1306
 * -----------------------------------------------
 * Font data taken from OLED_SSD1306 library by askn https://twtter.com/askn37
 */
#ifndef SSD1306_FONTS_H
#define	SSD1306_FONTS_H
#include "ssd1306_fonts.h"
const uint8_t Font8x16[] ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 20 ' '
	0x00,0x00,0x3c,0xfe,0xfe,0x3c,0x00,0x00, 0x00,0x00,0x00,0x0d,0x0d,0x00,0x00,0x00,	// 21 '!'
	0x00,0x0e,0x1e,0x00,0x00,0x1e,0x0e,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 22 '"'
	0x30,0xfe,0xfe,0x30,0xfe,0xfe,0x30,0x00, 0x03,0x1f,0x1f,0x03,0x1f,0x1f,0x03,0x00,	// 23 '#'
	0x38,0x7c,0x44,0xff,0xff,0x44,0xcc,0x88, 0x06,0x0e,0x08,0x3f,0x3f,0x08,0x0f,0x07,	// 24 '$'
	0x1c,0x14,0x9c,0xe0,0x78,0x1c,0x04,0x00, 0x08,0x0e,0x07,0x01,0x0e,0x0a,0x0e,0x00,	// 25 '%'
	0x80,0xdc,0x7e,0xe2,0xbe,0xdc,0x40,0x00, 0x07,0x0f,0x08,0x09,0x07,0x0f,0x08,0x00,	// 26 '&'
	0x00,0x00,0x10,0x1e,0x0e,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 27 '''
	0x00,0x00,0xf8,0xfe,0x07,0x01,0x00,0x00, 0x00,0x00,0x03,0x0f,0x1c,0x10,0x00,0x00,	// 28 '('
	0x00,0x00,0x01,0x07,0xfe,0xf8,0x00,0x00, 0x00,0x00,0x10,0x1c,0x0f,0x03,0x00,0x00,	// 29 ')'
	0x80,0xa0,0xe0,0xc0,0xc0,0xe0,0xa0,0x80, 0x00,0x02,0x03,0x01,0x01,0x03,0x02,0x00,	// 2a '*'
	0x00,0x80,0x80,0xe0,0xe0,0x80,0x80,0x00, 0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00,	// 2b '+'
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 0x00,0x00,0x20,0x3c,0x1c,0x00,0x00,0x00,	// 2c ','
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 2d '-'
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 0x00,0x00,0x0c,0x0c,0x00,0x00,0x00,0x00,	// 2e '.'
	0x00,0x00,0xc0,0xf0,0x3c,0x0e,0x02,0x00, 0x0c,0x0f,0x03,0x00,0x00,0x00,0x00,0x00,	// 2f '/'

	0xf8,0xfc,0x86,0xf2,0x3e,0xfc,0xf8,0x00, 0x03,0x07,0x0f,0x09,0x0c,0x07,0x03,0x00,	// 30 '0'
	0x00,0x08,0x0c,0xfe,0xfe,0x00,0x00,0x00, 0x00,0x08,0x08,0x0f,0x0f,0x08,0x08,0x00,	// 31 '1'
	0x18,0x1c,0x06,0x82,0xc6,0x7c,0x38,0x00, 0x0c,0x0e,0x0b,0x09,0x08,0x0c,0x0c,0x00,	// 32 '2'
	0x06,0x02,0x32,0x3a,0x6e,0xc6,0x80,0x00, 0x02,0x06,0x0c,0x08,0x0c,0x07,0x03,0x00,	// 33 '3'
	0x80,0xe0,0x78,0x1e,0xfe,0xfe,0x00,0x00, 0x01,0x01,0x01,0x09,0x0f,0x0f,0x09,0x00,	// 34 '4'
	0x3e,0x3e,0x12,0x12,0x32,0xe2,0xc2,0x00, 0x02,0x06,0x0c,0x08,0x0c,0x07,0x03,0x00,	// 35 '5'
	0xf8,0xfc,0x66,0x22,0x66,0xc4,0x80,0x00, 0x03,0x07,0x0c,0x08,0x0c,0x07,0x03,0x00,	// 36 '6'
	0x06,0x06,0x02,0xc2,0xf2,0x3e,0x0e,0x00, 0x00,0x00,0x0f,0x0f,0x00,0x00,0x00,0x00,	// 37 '7'
	0x18,0xbc,0xe6,0x42,0xe6,0xbc,0x18,0x00, 0x03,0x07,0x0c,0x08,0x0c,0x07,0x03,0x00,	// 38 '8'
	0x38,0x7c,0xc6,0x82,0xc6,0xfc,0xf8,0x00, 0x00,0x04,0x0c,0x08,0x0c,0x07,0x03,0x00,	// 39 '9'
	0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00, 0x00,0x00,0x00,0x0c,0x0c,0x00,0x00,0x00,	// 3a ':'
	0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00, 0x00,0x20,0x30,0x1c,0x0c,0x00,0x00,0x00,	// 3b ';'
	0x00,0x80,0xc0,0x60,0x30,0x18,0x08,0x00, 0x00,0x00,0x01,0x03,0x06,0x0c,0x08,0x00,	// 3c '<'
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00, 0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,	// 3d '='
	0x00,0x08,0x18,0x30,0x60,0xc0,0x80,0x00, 0x00,0x08,0x0c,0x06,0x03,0x01,0x00,0x00,	// 3e '>'
	0x08,0x0c,0x06,0x82,0xc2,0x66,0x3c,0x18, 0x00,0x00,0x00,0x0d,0x0d,0x00,0x00,0x00,	// 3f '?'

	0xf0,0xf8,0x08,0xc8,0xc8,0xf8,0xf0,0x00, 0x07,0x0f,0x08,0x0b,0x0b,0x0b,0x01,0x00,	// 40 '@'
	0xf0,0xf8,0x1c,0x0e,0x1c,0xf8,0xf0,0x00, 0x0f,0x0f,0x01,0x01,0x01,0x0f,0x0f,0x00,	// 41 'A'
	0x02,0xfe,0xfe,0x22,0x22,0xfe,0xdc,0x00, 0x08,0x0f,0x0f,0x08,0x08,0x0f,0x07,0x00,	// 42 'B'
	0xfc,0xfe,0x02,0x02,0x02,0x0e,0x0c,0x00, 0x07,0x0f,0x08,0x08,0x08,0x0e,0x06,0x00,	// 43 'C'
	0x02,0xfe,0xfe,0x02,0x06,0xfc,0xf8,0x00, 0x08,0x0f,0x0f,0x08,0x0c,0x07,0x03,0x00,	// 44 'D'
	0x02,0xfe,0xfe,0x42,0xe2,0x06,0x0e,0x00, 0x08,0x0f,0x0f,0x08,0x08,0x0c,0x0e,0x00,	// 45 'E'
	0x02,0xfe,0xfe,0x42,0xe2,0x06,0x0e,0x00, 0x08,0x0f,0x0f,0x08,0x00,0x00,0x00,0x00,	// 46 'F'
	0xfc,0xfe,0x02,0x02,0x82,0x9e,0x9c,0x00, 0x07,0x0f,0x08,0x08,0x0c,0x07,0x0f,0x00,	// 47 'G'
	0xfe,0xfe,0x40,0x40,0x40,0xfe,0xfe,0x00, 0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x00,	// 48 'H'
	0x00,0x00,0x02,0xfe,0xfe,0x02,0x00,0x00, 0x00,0x00,0x08,0x0f,0x0f,0x08,0x00,0x00,	// 49 'I'
	0x00,0x00,0x00,0x02,0xfe,0xfe,0x02,0x00, 0x06,0x0e,0x08,0x08,0x0f,0x07,0x00,0x00,	// 4a 'J'
	0x02,0xfe,0xfe,0xe0,0xf8,0x1e,0x06,0x00, 0x08,0x0f,0x0f,0x00,0x03,0x0f,0x0c,0x00,	// 4b 'K'
	0x02,0xfe,0xfe,0x02,0x00,0x00,0x00,0x00, 0x08,0x0f,0x0f,0x08,0x08,0x0c,0x0e,0x00,	// 4c 'L'
	0xfe,0xfc,0x38,0xf0,0x38,0xfc,0xfe,0x00, 0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x00,	// 4d 'M'
	0xfe,0xfe,0x78,0xe0,0x80,0xfe,0xfe,0x00, 0x0f,0x0f,0x00,0x00,0x03,0x0f,0x0f,0x00,	// 4e 'N'
	0xfc,0xfe,0x02,0x02,0x02,0xfe,0xfc,0x00, 0x07,0x0f,0x08,0x08,0x08,0x0f,0x07,0x00,	// 4f 'O'

	0x02,0xfe,0xfe,0x82,0x82,0xfe,0x7c,0x00, 0x08,0x0f,0x0f,0x08,0x00,0x00,0x00,0x00,	// 50 'P'
	0xfc,0xfe,0x02,0x02,0x02,0xfe,0xfc,0x00, 0x07,0x0f,0x0c,0x0e,0x1e,0x3f,0x37,0x00,	// 51 'Q'
	0x02,0xfe,0xfe,0x82,0xc2,0x7e,0x3c,0x00, 0x08,0x0f,0x0f,0x00,0x01,0x0f,0x0e,0x00,	// 52 'R'
	0x1c,0x3e,0x62,0x42,0xc2,0x8e,0x0c,0x00, 0x06,0x0e,0x08,0x08,0x08,0x0f,0x07,0x00,	// 53 'S'
	0x00,0x06,0x02,0xfe,0xfe,0x02,0x06,0x00, 0x00,0x00,0x08,0x0f,0x0f,0x08,0x00,0x00,	// 54 'T'
	0xfe,0xfe,0x00,0x00,0x00,0xfe,0xfe,0x00, 0x07,0x0f,0x08,0x08,0x08,0x0f,0x07,0x00,	// 55 'U'
	0xfe,0xfe,0x00,0x00,0x00,0xfe,0xfe,0x00, 0x01,0x03,0x06,0x0e,0x06,0x03,0x01,0x00,	// 56 'V'
	0xfe,0xfe,0x00,0xe0,0xe0,0x00,0xfe,0xfe, 0x03,0x0f,0x0e,0x03,0x03,0x0e,0x0f,0x03,	// 57 'W'
	0x06,0x1e,0xf8,0xe0,0xf8,0x1e,0x06,0x00, 0x0c,0x0f,0x03,0x00,0x03,0x0f,0x0c,0x00,	// 58 'X'
	0x00,0x3e,0x7e,0xc0,0xc0,0x7e,0x3e,0x00, 0x00,0x00,0x08,0x0f,0x0f,0x08,0x00,0x00,	// 59 'Y'
	0x0e,0x06,0x82,0xe2,0x3a,0x1e,0x06,0x00, 0x0c,0x0f,0x0b,0x08,0x08,0x0c,0x0e,0x00,	// 5a 'Z'
	0x00,0x00,0xfe,0xfe,0x02,0x02,0x00,0x00, 0x00,0x00,0x0f,0x0f,0x08,0x08,0x00,0x00,	// 5b '['
	0x06,0x1e,0x78,0xe0,0x80,0x00,0x00,0x00, 0x00,0x00,0x00,0x01,0x07,0x0e,0x08,0x00,	// 5c '\'
	0x00,0x00,0x02,0x02,0xfe,0xfe,0x00,0x00, 0x00,0x00,0x08,0x08,0x0f,0x0f,0x00,0x00,	// 5d ']'
	0x10,0x18,0x0c,0x06,0x0c,0x18,0x10,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 5e '^'
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,	// 5f '_'

	0x00,0x00,0x0e,0x1e,0x10,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 60 '`'
	0x00,0xa0,0xa0,0xa0,0xe0,0xc0,0x00,0x00, 0x07,0x0f,0x08,0x08,0x07,0x0f,0x08,0x00,	// 61 'a'
	0x02,0xfe,0xfe,0x20,0x20,0xe0,0xc0,0x00, 0x08,0x0f,0x07,0x08,0x08,0x0f,0x07,0x00,	// 62 'b'
	0xc0,0xe0,0x20,0x20,0x20,0x60,0x40,0x00, 0x07,0x0f,0x08,0x08,0x08,0x0c,0x04,0x00,	// 63 'c'
	0xc0,0xe0,0x20,0x22,0xfe,0xfe,0x00,0x00, 0x07,0x0f,0x08,0x08,0x07,0x0f,0x08,0x00,	// 64 'd'
	0xc0,0xe0,0x20,0x20,0x20,0xe0,0xc0,0x00, 0x07,0x0f,0x09,0x09,0x09,0x0d,0x04,0x00,	// 65 'e'
	0x20,0xfc,0xfe,0x22,0x02,0x0e,0x0c,0x00, 0x08,0x0f,0x0f,0x08,0x00,0x00,0x00,0x00,	// 66 'f'
	0xc0,0xe0,0x20,0x20,0xc0,0xe0,0x20,0x00, 0x47,0xcf,0x88,0x88,0xff,0x7f,0x00,0x00,	// 67 'g'
	0x02,0xfe,0xfe,0x20,0x20,0xe0,0xc0,0x00, 0x08,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x00,	// 68 'h'
	0x00,0x00,0x20,0xec,0xec,0x00,0x00,0x00, 0x00,0x00,0x08,0x0f,0x0f,0x08,0x00,0x00,	// 69 'i'
	0x00,0x00,0x00,0x20,0xec,0xec,0x00,0x00, 0x60,0xe0,0x80,0x80,0xff,0x7f,0x00,0x00,	// 6a 'j'
	0x02,0xfe,0xfe,0x00,0x80,0xe0,0x60,0x00, 0x08,0x0f,0x0f,0x01,0x03,0x0e,0x0c,0x00,	// 6b 'k'
	0x00,0x00,0x02,0xfe,0xfe,0x00,0x00,0x00, 0x00,0x00,0x08,0x0f,0x0f,0x08,0x00,0x00,	// 6c 'l'
	0xe0,0xe0,0x60,0xc0,0x60,0xe0,0xc0,0x00, 0x0f,0x0f,0x00,0x03,0x00,0x0f,0x0f,0x00,	// 6d 'm'
	0x20,0xe0,0xc0,0x20,0x20,0xe0,0xc0,0x00, 0x00,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x00,	// 6e 'n'
	0xc0,0xe0,0x20,0x20,0x20,0xe0,0xc0,0x00, 0x07,0x0f,0x08,0x08,0x08,0x0f,0x07,0x00,	// 6f 'o'

	0x20,0xe0,0xc0,0x20,0x20,0xe0,0xc0,0x00, 0x80,0xff,0xff,0x88,0x08,0x0f,0x07,0x00,	// 70 'p'
	0xc0,0xe0,0x20,0x20,0xc0,0xe0,0x20,0x00, 0x07,0x0f,0x08,0x88,0xff,0xff,0x80,0x00,	// 71 'q'
	0x20,0xe0,0xc0,0x60,0x20,0xe0,0xc0,0x00, 0x08,0x0f,0x0f,0x08,0x00,0x00,0x00,0x00,	// 72 'r'
	0xc0,0xe0,0x20,0x20,0x20,0x60,0x40,0x00, 0x04,0x0d,0x09,0x09,0x09,0x0f,0x06,0x00,	// 73 's'
	0x20,0x20,0xfc,0xfe,0x20,0x20,0x00,0x00, 0x00,0x00,0x07,0x0f,0x08,0x0c,0x04,0x00,	// 74 't'
	0xe0,0xe0,0x00,0x00,0x00,0xe0,0xe0,0x00, 0x07,0x0f,0x08,0x08,0x08,0x07,0x0f,0x08,	// 75 'u'
	0xe0,0xe0,0x00,0x00,0x00,0xe0,0xe0,0x00, 0x01,0x03,0x07,0x0e,0x07,0x03,0x01,0x00,	// 76 'v'
	0xe0,0xe0,0x00,0x80,0x00,0xe0,0xe0,0x00, 0x07,0x0f,0x0c,0x07,0x0c,0x0f,0x07,0x00,	// 77 'w'
	0x60,0xe0,0xc0,0x80,0xc0,0xe0,0x60,0x00, 0x0c,0x0e,0x07,0x03,0x07,0x0e,0x0c,0x00,	// 78 'x'
	0xe0,0xe0,0x00,0x00,0x00,0xe0,0xe0,0x00, 0x07,0x4f,0x48,0x48,0x48,0x7f,0x3f,0x00,	// 79 'y'
	0x60,0x60,0x20,0x20,0xa0,0xe0,0x60,0x00, 0x0c,0x0e,0x0b,0x09,0x09,0x0c,0x0c,0x00,	// 7a 'z'
	0x40,0x40,0xe0,0xbe,0x1f,0x01,0x01,0x00, 0x00,0x00,0x00,0x0f,0x1f,0x10,0x10,0x00,	// 7b '{'
	0x00,0x00,0x00,0x3e,0x3e,0x00,0x00,0x00, 0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,	// 7c '|'
	0x00,0x01,0x01,0x1f,0xbe,0xe0,0x40,0x40, 0x00,0x10,0x10,0x1f,0x0f,0x00,0x00,0x00,	// 7d '}'
	0x08,0x0c,0x04,0x0c,0x08,0x0c,0x04,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	// 7e '~'
	0x70,0xf8,0xf8,0xe0,0xf8,0xf8,0x70,0x00, 0x00,0x01,0x07,0x1f,0x07,0x01,0x00,0x00	// 7f
#if 0
	0xe0,0xe0,0xe0,0xe0,0xfc,0xf8,0xe0,0x00, 0x00,0x00,0x00,0x00,0x07,0x03,0x00,0x00	// 80 ->
	0x00,0xe0,0xf8,0xfc,0xe0,0xe0,0xe0,0xe0, 0x00,0x00,0x07,0x03,0x00,0x00,0x00,0x00	// 81 <-
	0x60,0x70,0xf8,0xfc,0xf8,0x70,0x60,0x00, 0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x00	// 82 ^
	0x00,0x00,0xfc,0xfc,0xfc,0x00,0x00,0x00, 0x01,0x03,0x07,0x0f,0x07,0x03,0x01,0x00	// 83 v
#endif
};
#endif
