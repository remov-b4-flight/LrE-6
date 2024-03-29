/**
* @file key_define.c
* @brief MIDI channel definition
* @details This file defines MIDI Control Change(CC) / Note ON-OFF event on MIDI build.
* LrE-6 has 6 encoder as enc0~5, and 10 individual switch(SW) as SW1~10 and SW on rotator as 'rot0~5 push'
* In MIDI use , users can send individual CC/Note event channel per switch and encoder.
* At switches, LrE-6 sends Note message has velocity= 127 when switch on, and sends velocity = 0 when switch off.
* At encoder, LrE-6 sends CC message every encoders move,values are increase/decrease by towards.
* LrE-6 MIDI can use 'Scene'. Users can alter all SW/Encoder definition. To alter Scene, push SW10.
* Users can use up to 4 Scenes. SW10 is fixed for Scene function.
*
* Scene / CC event channel definition (by Encoders)
* ch. 64~71		Scene0
* ch. 72~79		Scene1
* ch. 80~87		Scene2
* ch. 88~95		Scene3
* Scene / Note definition (by SWs)
* Note	0~15	Scene0
* Note	16~31	Scene1
* Note	32~47	Scene2
* Note	48~63	Scene3
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "key_define.h"
#include "led.h"

/* Variables ----------------------------------------------------------------*/
//! User-friendly scene names appears on OLED.
const char *scene_name[SCENE_COUNT] = {
/*		 0123456789ABCDEF */
		"Library",
		"Basic Edits",
		"Tone Curve",
		"Transform",
};
//! LED patterns that set by switching scenes.
const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] = {
	//0			1			2			3			4			5
	{LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,},	//Scene0
	{LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,},	//Scene1
	{LED_OFF,	LED_DARK,	LED_GLAY,	LED_WHITE,	LED_HILIGHT,LED_OFF,},	//Scene2
	{LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,	LED_OFF,},	//Scene3
};

//! @union Key/encoder configuration table
const KEY_DEFINE keytable[SCENE_COUNT][DEFINES_PER_SCENE] = {
	{	//Scene0 Button (Library Tab)                                                                   0123456789ABCDEF
/*N00*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 1"},			//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 2"},			//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 3"},			//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 4"},			//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "2nd Monitor"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 0"},			//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Add Quick Colle."},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Rate = 5"},			//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_LONG,	.message = "Scene 0"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Grid View"},		//L2M2	enc4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Zoom reset"},		//L2M3	enc5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Rate reset"},		//L3M0	enc1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Flag reset"},		//L3M1	enc2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = NULL},				//L3M2	enc3 push
/*N15*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Reject"},			//L3M3	enc0 push
		//Scence0 Encoders																			0123456789ABCDEF
/*N16*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Next " RIGHTA},		//enc0 CW cursor right
/*N17*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Prev. " LEFTA},		//enc0 CCW cursor left
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_BLUE,	.period = LED_TIM_HALF,	.message = "Rate " UPA},		//enc1 CW
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_BLUE,	.period = LED_TIM_HALF,	.message = "Rate " DOWNA},		//enc1 CCW
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_GREEN,	.period = LED_TIM_HALF,	.message = "Flag " UPA},		//enc2 CW
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_GREEN,	.period = LED_TIM_HALF,	.message = "Flag " DOWNA},		//enc2 CCW
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_YELLOW,.period = LED_TIM_HALF,	.message = "Rotate " RIGHTA},	//enc3 CW
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_YELLOW,.period = LED_TIM_HALF,	.message = "Rotate " LEFTA},	//enc3 CCW
		{.type = TYPE_SWITCH,	.axis = 4,	.color =LED_MAGENTA,.period = LED_TIM_HALF,	.message = "Scroll " DOWNA},	//enc4 CW
		{.type = TYPE_SWITCH,	.axis = 4,	.color =LED_MAGENTA,.period = LED_TIM_HALF,	.message = "Scroll " UPA},		//enc4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_ORANGE,.period = LED_TIM_HALF,	.message = "Zoom In"},			//enc5 CW
/*N27*/	{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_ORANGE,.period = LED_TIM_HALF,	.message = "Zoom Out"},			//enc5 CCW
	},{	//Scene1 Button	(Basic Edits)																0123456789ABCDEF
/*N32*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "W/B Auto"},			//L0M0	SW1
/*N33*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Auto Tone"},		//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_ORANGE,.period = LED_TIM_NORM,	.message = "DayLight"},			//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Tungsten"},			//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "W/B Cloud"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "W/B Shade"},		//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_GREEN,	.period = LED_TIM_NORM,	.message = "Fluorescent"},		//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_LONG,	.message = "Scene 1"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Contra. reset"},	//L2M2	enc4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Vibra. reset"},		//L2M3	enc5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "C-Temp. reset"},	//L3M0	enc1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Tint reset"},		//L3M1	enc2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Expo. reset"},		//L3M2	enc3 push
/*N47*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Reject"},			//L3M3	enc0 push
		//Scence1 Encoders																			0123456879ABCDEF
/*N48*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Next " UPA},		//enc0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Prev. " LEFTA},		//enc0 CCW cursor left
/*C17*/	{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_YELLOW,.period = LED_TIM_HALF,	.message = "Color-Temp. " UPA},	//enc1 CW
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_BLUE,	.period = LED_TIM_HALF,	.message = "Color-Temp. "DOWNA},//enc1 CCW
		{.type = TYPE_ROTARY,	.axis = 2,	.color =LED_MAGENTA,.period = LED_TIM_HALF,	.message = "Magenta"},			//enc2 CW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_GREEN,	.period = LED_TIM_HALF,	.message = "Green"},			//enc2 CCW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_GLAY,	.period = LED_TIM_HALF,	.message = "Exposure " UPA},	//enc3 CW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Exposure " DOWNA},	//enc3 CCW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_GLAY,	.period = LED_TIM_HALF,	.message = "Contrast " UPA},	//enc4 CW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Contrast " DOWNA},	//enc4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_GLAY,	.period = LED_TIM_HALF,	.message = "Vibrance " UPA},	//enc5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Vibrance " DOWNA},	//enc5 CCW
	},{	//Scene2 Button																					0123456789ABCDEF
/*N64*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 1"},		//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 2"},		//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 3"},		//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 4"},		//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 6"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 7"},		//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 8"},		//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Keyword 5"},		//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_LONG,	.message = "Scene 2"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "White reset"},		//L2M2	enc4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = NULL},				//L2M3	enc5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Black reset"},		//L3M0	enc1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Shadows reset"},	//L3M1	enc2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "HiLights reset"},	//L3M2	enc3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_NORM,	.message = "Reject"},			//L3M3	enc0 push
		//Scence2 encators																			0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Next " RIGHTA},		//enc0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Prev. " LEFTA},		//enc0 CCW cursor left
/*C33*/	{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_DARK,	.period = LED_TIM_HALF,	.message = "Dark " UPA},		//enc1 CW
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = "Dark " DOWNA},		//enc1 CCW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Shadow " UPA},		//enc2 CW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_DARK,	.period = LED_TIM_HALF,	.message = "Shadow " DOWNA},	//enc2 CCW
		{.type = TYPE_ROTARY,	.axis = 3,	.color =LED_HILIGHT,.period = LED_TIM_HALF,	.message = "Light " UPA},		//enc3 CW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Light " DOWNA},		//enc3 CCW
		{.type = TYPE_ROTARY,	.axis = 4,	.color =LED_HILIGHT,.period = LED_TIM_HALF,	.message = "Hilight " UPA},		//enc4 CW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_WHITE,	.period = LED_TIM_HALF,	.message = "Hilight " DOWNA},	//enc4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = NULL},				//enc5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = NULL},				//enc5 CCW
	},{	//Scene3 Button																					0123456789ABCDEF
/*N96*/	{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Enable Detail"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "RedEye"},			//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Lens Colle."},		//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Upright Full"},		//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_BLUE,	.period = LED_TIM_NORM,	.message = "Auto Upright"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_YELLOW,.period = LED_TIM_NORM,	.message = "Upright Vertical"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Upright Horizon"},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_WHITE,	.period = LED_TIM_LONG,	.message = "Scene 3"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//L2M2	enc4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//L2M3	enc5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "Tilt reset"},		//L3M0	enc1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//L3M1	enc2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_DARK,	.period = LED_TIM_NORM,	.message = "De-Haze reset"},	//L3M2	enc3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = "Reject"},			//L3M3	enc0 push
		//Scence3 Encoders																			0123456789ABCDEF
/*N112*/{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Next " RIGHTA},		//enc0 CW cursor right
/*N113*/{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_RED,	.period = LED_TIM_NORM,	.message = "Prev. " LEFTA},		//enc0 CCW cursor left
/*C49*/	{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = "Tilt " RIGHTA},		//enc1 CW
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = "Tilt " LEFTA},		//enc1 CCW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc2 CW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc2 CCW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = "De-Haze " UPA},		//enc3 CW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_OFF,	.period = LED_TIM_HALF,	.message = "De-Haze " DOWNA},	//enc3 CCW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc4 CW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_OFF,	.period = LED_TIM_NORM,	.message = NULL},				//enc5 CCW
	}
};
/* ******************************************************* **** END OF FILE****/
