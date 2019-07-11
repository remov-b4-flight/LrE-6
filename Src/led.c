/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "led.h"
/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "main.h"
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
extern TIM_HandleTypeDef htim3;
uint32_t period;
uint8_t		LEDColor[LED_COUNT];
uint8_t		LEDPulse[TOTAL_BITS];	//Data formed PWM width send to LED
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
	{.rgbw = {.r=LMAX,.g=LQTR,.b=LOFF}},//COLOR_ORANGE,
};

void LED_Initialize(){
	LEDColor[0]=LED_COLOR_WHITE;
	LEDColor[1]=LED_COLOR_RED;
	LEDColor[2]=LED_COLOR_ORANGE;
	LEDColor[3]=LED_COLOR_YELLOW;
	LEDColor[4]=LED_COLOR_GREEN;
	LEDColor[5]=LED_COLOR_BLUE;
	SendPulse();
	return;
}

//Flash LEDs immediately with LEDColor[]
void LED_Set_Quick(uint8_t index,uint8_t color){
	LEDColor[index] = color;
	SendPulse();
}

//make LEDPulse[] from LEDColor[]
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

// Send pulses to LEDs rely on LEDColor[] array
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


/* *****************************************************************************
 End of File
 */
