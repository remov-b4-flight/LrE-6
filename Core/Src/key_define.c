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
#include "EmulateHID.h"
#include "led.h"

/* Variables ----------------------------------------------------------------*/
#if MIDI
//! User-friendly scene names appears on LCD.
const char *scene_name[SCENE_COUNT] = { "Library", "Basic Edits",  "Tone Curve", "Transform", };
//! LED patterns that set by switching scenes.
const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] = {
	//0					1					2					3					4					5
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,},	//Scene0
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,},	//Scene1
	{LED_COLOR_OFF,		LED_COLOR_DARK,		LED_COLOR_GLAY,		LED_COLOR_WHITE,	LED_COLOR_HILIGHT,	LED_COLOR_OFF,},	//Scene2
	{LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,		LED_COLOR_OFF,},	//Scene3
};

//! @union Key/rotator configuration table
const KEY_DEFINE keytable[SCENE_COUNT][KEY_DEFINE_COUNT] = {
	{	//Scene0 Button (Library Tab)                                                                   0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 1"},			//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 2"},			//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 3"},			//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 4"},			//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "2nd Monitor"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 0"},			//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Add Quick Colle."},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Rate = 5"},			//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene 0"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Grid View"},		//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Zoom reset"},		//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Rate reset"},		//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Flag reset"},		//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Reject"},			//L3M3	rot0 push
		//Scence0 Rotators																				0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Next \x80"},		//rot0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Prev. \x81"},		//rot0 CCW cursor left
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Rate \x82"},		//rot1 CW
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Rate \x83"},		//rot1 CCW
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Flag \x82"},		//rot2 CW
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Flag \x83"},		//rot2 CCW
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Rotate \x80"},		//rot3 CW
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Rotate \x81"},		//rot3 CCW
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Scroll \x82"},		//rot4 CW
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Scroll \x83"},		//rot4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_HALF,		.message = "Zoom In"},			//rot5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_HALF,		.message = "Zoom Out"},			//rot5 CCW
	},{	//Scene1 Button																					0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "W/B Auto"},			//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Auto Tone"},		//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_ORANGE,	.duration = LED_TIMER_DEFAULT,	.message = "DayLight"},			//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Tungsten"},			//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "W/B Cloud"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "W/B Shade"},		//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_DEFAULT,	.message = "Fluorescent"},		//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene 1"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Contra. reset"},	//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Vibra. reset"},		//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "C-Temp. reset"},	//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Tint reset"},		//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Expo. reset"},		//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Reject"},			//L3M3	rot0 push
		//Scence1 Rotators																				0123456879ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Next \x80"},		//rot0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Prev. \x81"},		//rot0 CCW cursor left
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_HALF,		.message = "Color-Temp. \x82"},	//rot1 CW
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_HALF,		.message = "Color-Temp. \x83"},	//rot1 CCW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_MAGENTA,	.duration = LED_TIMER_HALF,		.message = "Magenta"},			//rot2 CW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_GREEN,	.duration = LED_TIMER_HALF,		.message = "Green"},			//rot2 CCW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_GLAY,	.duration = LED_TIMER_HALF,		.message = "Exposure \x82"},	//rot3 CW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "Exposure \x83"},	//rot3 CCW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_GLAY,	.duration = LED_TIMER_HALF,		.message = "Contrast \x82"},	//rot4 CW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "Contrast \x83"},	//rot4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_GLAY,	.duration = LED_TIMER_HALF,		.message = "Vibrance \x82"},	//rot5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "Vibrance \x83"},	//rot5 CCW
	},{	//Scene2 Button																					0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 1"},		//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 2"},		//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 3"},		//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 4"},		//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 6"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 7"},		//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 8"},		//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Keyword 5"},		//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene 2"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "White reset"},		//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Black reset"},		//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Shadows reset"},	//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "HiLights reset"},	//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_DEFAULT,	.message = "Reject"},			//L3M3	rot0 push
		//Scence2 Rotators																				0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Next \x80"},		//rot0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Prev. \x81"},		//rot0 CCW cursor left
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_HALF,		.message = "Black \x82"},		//rot1 CW
		{.type = TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Black \x83"},		//rot1 CCW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "Shadows \x82"},		//rot2 CW
		{.type = TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_HALF,		.message = "Shadows \x83"},		//rot2 CCW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_HILIGHT,	.duration = LED_TIMER_HALF,		.message = "HiLights \x82"},	//rot3 CW
		{.type = TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "HiLights \x83"},	//rot3 CCW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_HILIGHT,	.duration = LED_TIMER_HALF,		.message = "White \x82"},		//rot4 CW
		{.type = TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_HALF,		.message = "White \x83"},		//rot4 CCW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = NULL},				//rot5 CW
		{.type = TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = NULL},				//rot5 CCW
	},{	//Scene3 Button																					0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Enable Detail"},	//L0M0	SW1
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "RedEye"},			//L0M1	SW2
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Lens Collection"},	//L0M2	SW3
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Upright Full"},		//L0M3	SW4
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_BLUE,	.duration = LED_TIMER_DEFAULT,	.message = "Auto Upright"},		//L1M0	SW6
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_YELLOW,	.duration = LED_TIMER_DEFAULT,	.message = "Upright Vertical"},	//L1M1	SW7
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Upright Horizon"},	//L1M2	SW8
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Undo"},				//L1M3	SW9
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L2M0	SW5
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_WHITE,	.duration = LED_TIMER_LONG,		.message = "Scene 3"},			//L2M1	SW10 [SCENE]
		{.type = TYPE_SWITCH,	.axis = 4,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L2M2	rot4 push
		{.type = TYPE_SWITCH,	.axis = 5,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L2M3	rot5 push
		{.type = TYPE_SWITCH,	.axis = 1,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "Tilt reset"},		//L3M0	rot1 push
		{.type = TYPE_SWITCH,	.axis = 2,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//L3M1	rot2 push
		{.type = TYPE_SWITCH,	.axis = 3,	.color = LED_COLOR_DARK,	.duration = LED_TIMER_DEFAULT,	.message = "De-Haze reset"},	//L3M2	rot3 push
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = "Reject"},			//L3M3	rot0 push
		//Scence3 Rotators																				0123456789ABCDEF
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Next \x80"},		//rot0 CW cursor right
		{.type = TYPE_SWITCH,	.axis = 0,	.color = LED_COLOR_RED,		.duration = LED_TIMER_DEFAULT,	.message = "Prev. \x81"},		//rot0 CCW cursor left
		{.type =TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Tilt \x80"},		//rot1 CW
		{.type =TYPE_ROTARY,	.axis = 1,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "Tilt \x81"},		//rot1 CCW
		{.type =TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot2 CW
		{.type =TYPE_ROTARY,	.axis = 2,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot2 CCW
		{.type =TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "De-Haze \x82"},		//rot3 CW
		{.type =TYPE_ROTARY,	.axis = 3,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_HALF,		.message = "De-Haze \x83"},		//rot3 CCW
		{.type =TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot4 CW
		{.type =TYPE_ROTARY,	.axis = 4,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot4 CCW
		{.type =TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot5 CW
		{.type =TYPE_ROTARY,	.axis = 5,	.color = LED_COLOR_OFF,		.duration = LED_TIMER_DEFAULT,	.message = NULL},				//rot5 CCW
	}
};
#else //HID
const uint8_t LED_Scene[SCENE_COUNT][LED_COUNT] ={
		{LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF,	LED_COLOR_OFF, },
};

const HID_DEFINE keytable[HID_DEFINE_COUNT] = {
#if LrE6_WIN //Windows Key Table Definitions
//Switch definitions
	{HID_NONM,			HID_1,		"Rate = 1"},	//L0M0	SW1
	{HID_NONM,			HID_2,		"Rate = 2"},	//L0M1	SW2
	{HID_NONM,			HID_3,		"Rate = 3"},	//L0M2	SW3
	{HID_NONM,			HID_4,		"Rate = 4"},	//L1M3	SW4
	{HID_NONM,			HID_F11,	"2nd Monitor"},	//L1M0	SW6
	{HID_NONM,			HID_0,		"Rate = 0"},	//L1M1	SW7
	{HID_NONM,			HID_z,		"Zoom In "},	//L1M2	SW8
	{HID_CTLM,			HID_z,		"Undo    "},	//L1M3	SW9
	{HID_NONM,			HID_5,		"Rate = 5"},	//L2M0	SW5
	{HID_NONM,			HID_b,		"Add Quick Colle."},	//L2M1	SW10 [MODE]
	{HID_NONM,			HID_NONE,	NULL},			//L2M2 rot4 push
	{HID_NONM,			HID_NONE,	NULL},			//L2M3 rot5 push
	{HID_NONM,			HID_0,		"Rate reset"},	//L3M0 rot1 push
	{HID_NONM,			HID_u,		"Flag reset"},	//L3M1 rot2 push
	{HID_NONM,			HID_NONE,	NULL},			//L3M2 rot3 push
	{HID_NONM,			HID_x,		"Reject  "},	//L3M3 rot0 push
//Rotator movements
	{HID_NONM,			HID_RIGHT,	"Next \x80  "},	//rot0 CW
	{HID_NONM,			HID_LEFT,	"Prev. \x81 "},	//rot0 CCW
	{HID_NONM,			HID_LB,		"Rate \x82  "},	//rot1 CW
	{HID_NONM,			HID_RB,		"Rate \x83  "},	//rot1 CCW
	{HID_CTLM,			HID_UP,		"Flag \x82  "},	//rot2 CW
	{HID_CTLM,			HID_DOWN,	"Flag \x83  "},	//rot2 CCW
	{HID_CTLM,			HID_LB,		"Rotate \x80"},	//rot3 CW
	{HID_CTLM,			HID_RB,		"Rotate \x81"},	//rot3 CCW
	{HID_NONM,			HID_PGUP,	"Scroll \x82"},	//rot4 CW
	{HID_NONM,			HID_PGDOWN,	"Scroll \x83"},	//rot4 CCW
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
	{HID_NONM,			HID_x,		"Reject  "},	//L3M3 rot0 push
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
