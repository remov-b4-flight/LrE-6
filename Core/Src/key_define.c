/**
* @file key_define.c
* @brief HID key definition & MIDI channel definition
* @details This file defines 'key code' sent to PC on HID build OR MIDI Control Change(CC) / Note ON-OFF event on MIDI build.
* LrE-6 has 6 rotator as rot0~5, and 10 individual switch(SW) as SW1~10 and SW on rotator as 'rot0~5 push'
* In MIDI use , users can send individual CC/Note event channel per switch and rotator.
* At switches, LrE-6 sends Note message has velocity= 127 when switch on, and sends velocity = 0 when switch off.
* At rotator, LrE-6 sends CC message every rotators move,values are increase/decrease by towards.
* LrE-6 MIDI can use 'Scene'. Users can alter all SW/Rotator definition. To alter Scene, push SW10.
* Users can use up to 4 Scenes. SW10 is fixed for Scene function.
*
* Scene / CC event channel definition (by Rotators)
* ch. 0~15		Scene0
* ch. 16~31		Scene1
* ch. 32~47		Scene2
* ch. 48~64		Scene3
* Scene / Note definition (by SWs)
* Note	0~15	Scene0
* Note	16~31	Scene1
* Note	32~47	Scene2
* Note	48~64	Scene3
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "key_define.h"
#include "led.h"

/* Variables ----------------------------------------------------------------*/
#if MIDI
//! @brief	User-friendly scene names appears on LCD.
const char *scene_name[SCENE_COUNT] = { "Library ", "TonCurve",  "ColorSat", "Sharpen ", };
//! @brief	LED patterns that set by switching scenes.
const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] = {
	//0					1					2					3					4					5
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,},		//Scene0
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_DARK,		LED_COLOR_GLAY,		LED_COLOR_WHITE,	LED_COLOR_OFF,},		//Scene1
	{LED_COLOR_RED,		LED_COLOR_ORANGE,	LED_COLOR_YELLOW,	LED_COLOR_GREEN,	LED_COLOR_CYAN,		LED_COLOR_BLUE,},		//Scene2
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_WHITE,	LED_COLOR_MAGENTA,},	//Scene3
};
const uint8_t led_axis_table[KEY_DEFINE_COUNT]={
//	0,	1,	2,	3,	4,	5,	6,	7,	8,	9|	10,	11,	12,	13,	14,	15|	16,	17,	18,	19,	20,	21,	22,	23,	24,	25,	26,	27
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	5,	1,	2,	3,	0,	0,	0,	1,	1,	2,	2,	3,	3,	4,	4,	5,	5,
};
const KEY_DEFINE keytable[SCENE_COUNT][KEY_DEFINE_COUNT] = {
	{	//Scene0 Button (Library Tab)
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 1"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 2"},	//L0M1	SW2
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 3"},	//L0M2	SW3
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 4"},	//L0M3	SW4
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "2nd Mon."},	//L1M0	SW6
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 0"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "QuickCol"},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Undo    "},	//L1M3	SW9
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 5"},	//L2M0	SW5
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene  0"},	//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "GridView"},	//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "PeopleVw"},	//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Rate res"},	//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Flag res"},	//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = NULL},		//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Reject  "},	//L3M3	rot0 push
		//Scence0 Rotators
		{.type = TYPE_SWITCH,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = NULL},			//rot0 CW cursor right
		{.type = TYPE_SWITCH,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = NULL},			//rot0 CCW cursor left
		{.type = TYPE_SWITCH,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Rate \x5  "},	//rot1 CW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Rate \x6  "},	//rot1 CCW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Flag \x5  "},	//rot2 CW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Flag \x6  "},	//rot2 CCW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Rotate \x7"},	//rot3 CW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Rotate \x8"},	//rot3 CCW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Scroll \x5"},	//rot4 CW
		{.type = TYPE_SWITCH,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Scroll \x6"},	//rot4 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_HALF,		.message = "Zoom In "},		//rot5 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_HALF,		.message = "Zoom Out"},		//rot5 CCW
	},{	//Scene1 Button
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "W/B Auto"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "AutoTone"},	//L0M1	SW2
		{.type = TYPE_SWITCH,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_DEFAULT,	.message = "DayLight"},	//L0M2	SW3
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Tangsten"},	//L0M3	SW4
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "WB Cloud"},	//L1M0	SW6
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "WB Shade"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},		//L1M2	SW8
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},		//L1M3	SW9
		{.type = TYPE_SWITCH,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_DEFAULT,	.message = "Fluores."},	//L2M0	SW5
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene  1"},	//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrHiLit"},	//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Clr.Temp"},	//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "ClrShadw"},	//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Clr.Dark"},	//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "ClrLight"},	//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Clr. W/B"},	//L3M3	rot0 push
		//Scence1 Rotators
		{.type = TYPE_ROTARY,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Magenta "},		//rot0 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Green   "},		//rot0 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Shadows\x5"},	//rot1 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Shadows\x6"},	//rot1 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Darks \x5 "},	//rot2 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Darks \x6 "},	//rot2 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_GLAY,	.duration = LED_TIMER_HALF,		.message = "Lights \x5"},	//rot3 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Lights \x6"},	//rot3 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "HiLight\x5"},	//rot4 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "HiLight\x6"},	//rot4 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "C-Temp.\x5"},	//rot5 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "C-Temp.\x6"},	//rot5 CCW
	},{	//Scene2 Button
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword1"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword2"},	//L0M1	SW2
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword3"},	//L0M2	SW3
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword4"},	//L0M3	SW4
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword6"},	//L1M0	SW6
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword7"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword8"},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "GryScale"},	//L1M3	SW9
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword5"},	//L2M0	SW5
		{.type = TYPE_SWITCH,	.color = LED_COLOR_RED,		.duration = LED_TIMER_LONG,		.message = "Scene  2"},	//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatCY"},	//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatBL"},	//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatOR"},	//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatYW"},	//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatGR"},	//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatRD"},	//L3M3	rot0 push
		//Scence2 Rotators
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Sat.Red\x5"},	//rot0 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Sat.Red\x6"},	//rot0 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatOrng\x5"},	//rot1 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatOrng\x6"},	//rot1 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatYelw\x5"},	//rot2 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatYelw\x6"},	//rot2 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatGren\x5"},	//rot3 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatGren\x6"},	//rot3 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatCyan\x5"},	//rot4 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatCyan\x6"},	//rot4 CCW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatBlue\x5"},	//rot5 CW
		{.type = TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatBlue\x6"},	//rot5 CCW
	},{	//Scene3 Button
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "EnDetail"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "RedEye  "},	//L0M1	SW2
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "LensColl"},	//L0M2	SW3
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "UprigtFL"},	//L0M3	SW4
		{.type = TYPE_SWITCH,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_DEFAULT,	.message = "ATUprigt"},	//L1M0	SW6
		{.type = TYPE_SWITCH,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Uprigt-V"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Uprigt-H"},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "UpritOff"},	//L1M3	SW9
		{.type = TYPE_SWITCH,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_DEFAULT,	.message = NULL},		//L2M0	SW5
		{.type = TYPE_SWITCH,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_LONG,		.message = "Scene  3"},	//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatAl"},	//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrSatMG"},	//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Clr Tilt"},	//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrVibra"},	//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "ClrDeHaz"},	//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Clear # "},	//L3M3	rot0 push
		//Scence3 Rotators
		{.type =TYPE_ROTARY,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Sharpen\x5"},	//rot0 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Sharpen\x6"},	//rot0 CCW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_CYAN,	.duration = LED_TIMER_HALF,		.message = "Tilt   \x7"},	//rot1 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Tilt   \x8"},	//rot1 CCW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_RED,		.duration = LED_TIMER_HALF,		.message = "Vibranc\x5"},	//rot2 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_HALF,		.message = "Vibrabc\x6"},	//rot2 CCW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "De-Haze\x5"},	//rot3 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "De-Haze\x6"},	//rot3 CCW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Sat.All\x5"},	//rot4 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Sat.All\x6"},	//rot4 CCW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatMgnt\x5"},	//rot5 CW
		{.type =TYPE_ROTARY,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "SatMgnt\x6"},	//rot5 CCW
	}
};
#else //HID
const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] ={
		{LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF, },
};

const HID_DEFINE keytable[HID_DEFINE_COUNT] = {
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

