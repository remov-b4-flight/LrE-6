/**
* @file key_define.c
* @brief HID key definition & MIDI channel definition
* @details This file defines 'key code' sent to PC on HID mode OR MIDI Control Change(CC) event on MIDI build.
* LrE-6 has 6 rotator as rot0~5, and 10 individual switch(SW) as SW1~10 and SW on rotator as 'rot0~5 push'
* In MIDI use , users can send individual CC event channel per switch and rotator.
* At switches, LrE-6 sends CC message has value = 127 when switch on, and sends value = 0 when switch off.
* At rotator, LrE-6 sends CC message every rotators move,values are increase/decrease by towards.
* LrE-6 MIDI can use 'Scene'. Users can alter all SW/Rotator definition. To alter Scene, push SW10.
* Users can use up to 4 Scenes. SW10 is fixed for Scene function.
* Scene / CC event channel definition (by Rotators)
* ch. 0-5	Scene0
* ch. 8-15	Scene1
* ch. 16-23	Scene2
* ch. 24-31	Scene3
* Scene / CC event channel definition (by SWs)
* ch. 32-47	Scene0
* ch. 48-63	Scene1
* ch. 64-79	Scene2
* ch. 80-95	Scene3
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "key_define.h"
#include "led.h"

/* Variables ----------------------------------------------------------------*/
#ifdef MIDI
	//! @brief	User-friendly scene names appears on LCD.
	const char *scene_name[SCENE_COUNT] = { "Library ", "TonCurve",  "ColorSat", "Sharpen ", };
	//! @brief	LED patterns that set by switching scenes.
	const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] ={
		//0					1					2					3					4					5
		{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,},//Scene0
		{LED_COLOR_GREEN,	LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_WHITE,	LED_COLOR_OFF,},//Scene1
		{LED_COLOR_RED,		LED_COLOR_ORANGE,	LED_COLOR_YELLOW,	LED_COLOR_GREEN,	LED_COLOR_CYAN,		LED_COLOR_BLUE,},//Scene2
		{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_WHITE,	LED_COLOR_MAGENTA,},//Scene3
	};
	const KEY_DEFINE keytable[SCENE_COUNT][KEY_DEFINE_COUNT] = {
		{	//Scene0 Button (Library Tab)
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 1"},	//L0M0	SW1
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 2"},	//L0M1	SW2
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 3"},	//L0M2	SW3
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 4"},	//L0M3	SW4
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"2nd Mon."},	//L1M0	SW6
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 0"},	//L1M1	SW7
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Zoom In "},	//L1M2	SW8
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Undo    "},	//L1M3	SW9
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate = 5"},	//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT*2,"Scene  0"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"QuickCol"},	//L2M2	rot4 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L2M3	rot5 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Rate res."},	//L3M0	rot1 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Flag res."},	//L3M1	rot2 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Reject   "},	//L3M3	rot0 push
			//Scence0 Rotators
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	NULL},			//rot0 CW	cursor right
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	NULL},			//rot0 CCW	cursor left
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Rate \x5  "},	//rot1 CW
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Rate \x6  "},	//rot1 CCW
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Flag \x5  "},	//rot2 CW
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Flag \x6  "},	//rot2 CCW
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rotate \x7"},	//rot3 CW
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rotate \x8"},	//rot3 CCW
			{LED_COLOR_MAGENTA,	LED_TIMER_DEFAULT,	"Scroll \x5"},	//rot4 CW
			{LED_COLOR_MAGENTA,	LED_TIMER_DEFAULT,	"Scroll \x6"},	//rot4 CCW
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT,	"Zoom In "},	//rot5 CW
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT,	"Zoom Out"},	//rot5 CCW
		},{	//Scene1 Button
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"W/B Auto"},	//L0M0	SW1
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	"AutoTone"},	//L0M1	SW2
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT,	"DayLight"},	//L0M2	SW3
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Tungsten"},	//L0M3	SW4
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M0	SW6
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M3	SW9
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Fluores."},			//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT*2,"Scene  1"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrHiLit"},	//L2M2	rot4 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Clr.Temp"},	//L2M3	rot5 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"ClrShadw"},	//L3M0	rot1 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Clr.Dark"},	//L3M1	rot2 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"ClrLight"},	//L3M2	rot3 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Clr. W/B"},	//L3M3	rot0 push
			//Scence1 Rotators
			{LED_COLOR_MAGENTA,	LED_TIMER_DEFAULT,	"Magenta "},	//rot0 CW
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Green   "},	//rot0 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Shadows\x5"},	//rot1 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Shadows\x6"},	//rot1 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Darks \x5 "},	//rot2 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Darks \x6 "},	//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Lights \x5"},	//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Lights \x6"},	//rot3 CCW
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"HiLight\x5"},	//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"HiLight\x6"},	//rot4 CCW
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Temp.  \x5"},	//rot5 CW
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Temp.  \x6"},	//rot5 CCW
		},{	//Scene2 Button
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M0	SW1
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M1	SW2
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M2	SW3
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M3	SW4
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M0	SW6
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatAl"},	//L1M3	SW9
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M0	SW5
			{LED_COLOR_RED,		LED_TIMER_DEFAULT*2,"Scene  2"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatCY"},	//L2M2	rot4 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatBL"},	//L2M3	rot5 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatOR"},	//L3M0	rot1 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatRD"},	//L3M1	rot2 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatYW"},	//L3M2	rot3 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatRD"},	//L3M3	rot0 push
			//Scence2 Rotators
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Sat.Red\x5"},	//rot0 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Sat.Red\x6"},	//rot0 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatOrng\x5"},	//rot1 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatOrng\x6"},	//rot1 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatYelw\x5"},	//rot2 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatYelw\x6"},	//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatGren\x5"},	//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatGren\x6"},	//rot3 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatCyan\x5"},	//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatCyan\x6"},	//rot4 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatBlue\x5"},	//rot5 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatBlue\x6"},	//rot5 CCW
		},{	//Scene3 Button
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M0	SW1
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M1	SW2
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M2	SW3
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M3	SW4
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"EnDetail"},	//L1M0	SW6
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"ATUprigt"},	//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M3	SW9
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"LensColl"},	//L2M0	SW5
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT*2,"Scene  3"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatAl"},	//L2M2	rot4 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrSatMG"},	//L2M3	rot5 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrRadi."},	//L3M0	rot1 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"ClrDetil"},	//L3M1	rot2 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Clear # "},	//L3M3	rot0 push
			//Scence3 Rotators
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Sharpen\x5"},	//rot0 CW
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Sharpen\x6"},	//rot0 CCW
			{LED_COLOR_CYAN,	LED_TIMER_DEFAULT,	"#Radius\x5"},	//rot1 CW
			{LED_COLOR_CYAN,	LED_TIMER_DEFAULT,	"#Radius\x6"},	//rot1 CCW
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	"#Detail\x5"},	//rot2 CW
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	"#Detail\x6"},	//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Sat.All\x5"},	//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"Sat.All\x6"},	//rot4 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatMgnt\x5"},	//rot5 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	"SatMgnt\x6"},	//rot5 CCW
		},
	};
#else //HID
	const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] ={
			{LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF, },
	};

	const KEY_DEFINE keytable[KEY_DEFINE_COUNT] = {
	#if LrE6_WIN //Windows Key Table Definitions
	//Switch definitions
		{HID_NONM,			HID_1,		"Rate 1  "},	//L0M0	SW1
		{HID_NONM,			HID_2,		"Rate 2  "},	//L0M1	SW2
		{HID_NONM,			HID_3,		"Rate 3  "},	//L0M2	SW3
		{HID_NONM,			HID_4,		"Rate 4  "},	//L1M3	SW4
		{HID_NONM,			HID_F11,	"2nd Mon."},	//L1M0	SW6
		{HID_NONM,			HID_0,		"Rate 0  "},	//L1M1	SW7
		{HID_NONM,			HID_z,		"Zoom In "},	//L1M2	SW8
		{HID_CTLM,			HID_z,		"Undo    "},	//L1M3	SW9
		{HID_NONM,			HID_5,		"Rate 5  "},	//L2M0	SW5
		{HID_NONM,			HID_b,		"Quick c."},	//L2M1	SW10 [MODE]
		{HID_NONM,			HID_NONE,	NULL},			//L2M2 rot3 push
		{HID_NONM,			HID_NONE,	NULL},			//L2M3 rot4 push
		{HID_NONM,			HID_0,		"Rate res."},	//L3M0 rot0 push
		{HID_NONM,			HID_u,		"Flag res."},	//L3M1 rot1 push
		{HID_NONM,			HID_NONE,	NULL},			//L3M2 rot2 push
		{HID_NONM,			HID_x,		"Reject  "},	//L3M3 rot5 push
	//Rotator movements
		{HID_NONM,			HID_RIGHT,	NULL},			//rot0 CW
		{HID_NONM,			HID_LEFT,	NULL},			//rot0 CCW
		{HID_NONM,			HID_LB,		"Rate \x5  "},	//rot1 CW
		{HID_NONM,			HID_RB,		"Rate \x6  "},	//rot1 CCW
		{HID_CTLM,			HID_UP,		"Flag \x5  "},	//rot2 CW
		{HID_CTLM,			HID_DOWN,	"Flag \x6  "},	//rot2 CCW
		{HID_CTLM,			HID_LB,		"Rotate \x7"},	//rot3 CW
		{HID_CTLM,			HID_RB,		"Rotate \x8"},	//rot3 CCW
		{HID_NONM,			HID_PGUP,	"Scroll \x5"},	//rot4 CW
		{HID_NONM,			HID_PGDOWN,	"Scroll \x6"},	//rot4 CCW
		{HID_CTLM+HID_SFTM,	HID_DT,		"Zoom In "},	//rot5 CW
		{HID_CTLM+HID_SFTM,	HID_CM,		"Zoom Out"},	//rot5 CCW
	#else //macOS Key Table Definitions
	//Switch definitions
		{HID_NONM,			HID_1,		"Rate 1  "},	//L0M0	SW1
		{HID_NONM,			HID_2,		"Rate 2  "},	//L0M1	SW2
		{HID_NONM,			HID_3,		"Rate 3  "},	//L0M1	SW3
		{HID_NONM,			HID_4,		"Rate 4  "},	//L1M3	SW4
		{HID_GUIM,			HID_F11,	"2nd Mon."},	//L1M0	SW6
		{HID_NONM,			HID_0,		"Rate 0  "},	//L1M1	SW7
		{HID_NONM,			HID_z,		"Zoom In "},	//L1M2	SW8
		{HID_GUIM,			HID_z,		"Undo    "},	//L1M3	SW9
		{HID_NONM,			HID_5,		"Rate 5  "},	//L2M0	SW5
		{HID_NONM,			HID_b,		"Quick c."},	//L2M1	SW10 [MODE]
		{HID_NONM,			HID_NONE,	NULL},			//L2M2 rot4 push
		{HID_NONM,			HID_NONE,	NULL},			//L2M3 rot5 push
		{HID_NONM,			HID_0,		"Rate res."},	//L3M0 rot1 push
		{HID_NONM,			HID_u,		"Flag res."},	//L3M1 rot2 push
		{HID_NONM,			HID_NONE,	NULL},			//L3M2 rot3 push
		{HID_NONM,			HID_x,		"Reject  "},	//L3M3 rots push
	//Rotator movements
		{HID_NONM,			HID_RIGHT,	NULL},			//rot0 CW
		{HID_NONM,			HID_LEFT,	NULL},			//rot0 CCW
		{HID_NONM,			HID_LB,		"Rate \x5  "},	//rot1 CW
		{HID_NONM,			HID_RB,		"Rate \x6  "},	//rot1 CCW
		{HID_GUIM,			HID_UP,		"Flag \x5  "},	//rot2 CW
		{HID_GUIM,			HID_DOWN,	"Flag \x6  "},	//rot2 CCW
		{HID_GUIM,			HID_LB,		"Rotate \x7"},	//rot3 CW
		{HID_GUIM,			HID_RB,		"Rotate \x8"},	//rot3 CCW
		{HID_SFTM,			HID_PGUP,	"Scroll \x5"},	//rot4 CW
		{HID_SFTM,			HID_PGDOWN,	"Scroll \x6"},	//rot4 CCW
		{HID_GUIM+HID_SFTM,	HID_DT,		"Zoom In "},	//rot5 CW
		{HID_GUIM+HID_SFTM,	HID_CM,		"Zoom Out"},	//rot5 CCW
	#endif
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
	};
#endif
/* ******************************************************* **** END OF FILE****/

