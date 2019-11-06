/**
 *	@file led.c
 *	@brief Array of Color LEDs control functions
 *	@copyright	GPLv3
*/
/* Includes ------------------------------------------------------------------*/
#include "led.h"

#include "main.h"
#include <string.h>

/* Variables -----------------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern bool	led_sendpulse;
uint32_t period;
uint8_t	LEDColor[LED_COUNT];
uint8_t	LEDPulse[TOTAL_BITS];	//Data formed PWM width send to LED
uint8_t	LEDTimer[LED_COUNT];

const LEDDATA LEDTable[COLOR_MAX] = {
	//			R		G		B
	{.rgbw = {.r=LOFF,.g=LOFF,.b=LOFF}},//COLOR_OFF,
	{.rgbw = {.r=LMAX,.g=LOFF,.b=LOFF}},//COLOR_RED,
	{.rgbw = {.r=LOFF,.g=LOFF,.b=LMAX}},//COLOR_BLUE,
	{.rgbw = {.r=LOFF,.g=LMAX,.b=LOFF}},//COLOR_GREEN,
	{.rgbw = {.r=LMAX,.g=LMAX,.b=LMAX}},//COLOR_WHITE,
	{.rgbw = {.r=LHLF,.g=LHLF,.b=LOFF}},//COLOR_YELLOW,
	{.rgbw = {.r=LHLF,.g=LOFF,.b=LHLF}},//COLOR_MAGENTA,
	{.rgbw = {.r=LOFF,.g=LHLF,.b=LHLF}},//COLOR_CYAN,
	{.rgbw = {.r=LMAX,.g=LHLF,.b=LOFF}},//COLOR_ORANGE,
	{.rgbw = {.r=LQTR,.g=LQTR,.b=LQTR}},//COLOR_GLAY,
};

/* User code ----------------------------------------------------------------*/
/**
 * @brief	Sets all LEDs to 'OFF'
 * @param	none
 */
void LED_Initialize(){
	memset(LEDColor,LED_COLOR_OFF,LED_COUNT);
	memset(LEDTimer,LED_TIMER_CONSTANT,LED_COUNT);

	SendPulse();
	return;
}
/**
 *	@brief	Sets decorative color pattern to LEDs.
 *	@param	none
 */
void LED_TestPattern(){
	LEDColor[0]=LED_COLOR_WHITE;
	LEDColor[1]=LED_COLOR_RED;
	LEDColor[2]=LED_COLOR_ORANGE;
	LEDColor[3]=LED_COLOR_YELLOW;
	LEDColor[4]=LED_COLOR_GREEN;
	LEDColor[5]=LED_COLOR_BLUE;
	SendPulse();
}

/**
 *	@brief	Flush LEDs immediately with LEDColor[]
 *	@param	uint8_t	index	index of LEDs.
 *	@param	uint8_t	color	color of LED.
 */
void LED_Set_Quick(uint8_t index,uint8_t color){
	LEDColor[index] = color;
	SendPulse();
}

/**
 *	@brief	Flush LEDs at loop in main()
 *	@param	uint8_t	index	index of LEDs.
 *	@param	uint8_t	color	color of LED
 * 	@attention	Difference of LED_Set() and LED_Set_Quick() is
 * 	Using LED_Set(), Real flash LED point is pended until return to main().
 * 	Using LED_Set_Quick() , It flashes LEDs immediately.
 */
inline void LED_Set(uint8_t index,uint8_t color){
	LEDColor[index] = color;
	led_sendpulse = true;
}

/**
 *	@brief	Make LED pulses.
 *	@param	uint8_t	index	index of LEDs.
 *	@param	uint8_t	color	color of LED.
 *	@param	uint8_t	pulse	duration of pulse in 4ms unit(i.e. pulse=25 => 100ms).
 */
inline void LED_SetPulse(uint8_t index,uint8_t color,uint8_t pulse){
	LEDColor[index] = color;
    LEDTimer[index] = pulse;	// 4ms unit (i.e. pulse=25 => 100ms)
	led_sendpulse = true;
}

/**
 *	@brief	make LEDPulse[] from LEDColor[]
 *	@pre	LEDColor[] contains LED color setting.
 */
void Color2Pulse(){
	uint8_t	pulse = 0;
	LEDDATA	leddata;

	for(uint8_t	led = 0; led < LED_COUNT; led++){
		uint8_t c = LEDColor[led];
		leddata.n = LEDTable[c].n;
		for (uint32_t mask = 0x80000000; mask > 0x80; mask >>= 1){
			LEDPulse[pulse++] = (leddata.n & mask)? PWM_HI:PWM_LO;
		}
	}
}

/**
 *	@brief	Send pulses to LEDs rely on LEDColor[] array
 *	@param	none.
 *	@pre	LEDColor[] contains LED color setting.
 */
void SendPulse(){

	//Convert LEDColor[] to LEDPulse[]
	Color2Pulse();

	//Send 'RESET' signal(80us > low data) for LEDs
	Delay_us(280);
	//End of RESET

	//Start DMA
	htim3.Instance->CNT = PWM_HI + 1;
	HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1,(uint32_t *) LEDPulse, TOTAL_BITS);
}

/* ******************************************************* **** END OF FILE****/
