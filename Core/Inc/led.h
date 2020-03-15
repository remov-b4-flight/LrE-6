/**
 * 	@file led.h
 *	@brief LED control functions.
 *	@copyright	GPLv3
 */

#ifndef _LED_H    /* Guard against multiple inclusion */
#define _LED_H

/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/* Exported constants --------------------------------------------------------*/
enum led_color {   //constants for expressing color.
	LED_COLOR_OFF = 0,
	LED_COLOR_RED,
	LED_COLOR_BLUE,
	LED_COLOR_GREEN,
	LED_COLOR_WHITE,
	LED_COLOR_YELLOW,
	LED_COLOR_MAGENTA,
	LED_COLOR_CYAN,
	LED_COLOR_ORANGE,
	LED_COLOR_GLAY,
	LED_COLOR_DARK,
};
#define COLOR_MAX 11

#define LED_COUNT		6
#define BITS_PER_LED    24  // (RGB) 3 * 8bit
#define TOTAL_BITS      (LED_COUNT * BITS_PER_LED)

//! @def LED intensity definition
#define LFFH	0xFF
#define LBRIGHT	0x80
#define LMAX	0x78
#define L43		0x58
#define LHLF	0x38
#define LQTR	0x20
#define LDRK	0x10
#define LMIN	0x08
#define LOFF	0x00

#define LED_TIMER_CONSTANT	0xFF
#define	LED_IDX_ENC0	0
#define LED_RESET_WIDTH	280	//in usec.

/* Exported types ------------------------------------------------------------*/
typedef union leddata_t {
	uint32_t	n;
	struct	rgbw_t {
		uint8_t	padding;
		uint8_t	b;
		uint8_t	r;
		uint8_t g;
	}	rgbw;
} LEDDATA;

/* Exported functions prototypes ---------------------------------------------*/
    void LED_Initialize();
    void LED_TestPattern();
    void LED_Set_Quick(uint8_t index, uint8_t color);
    void LED_Set(uint8_t index, uint8_t color);
    void LED_SetPulse(uint8_t index, uint8_t color,uint8_t pulse);
    void LED_SendPulse();

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _LED_H */

/* *****************************************************************************
 End of File
 */
