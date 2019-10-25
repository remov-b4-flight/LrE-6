#include "main.h"
#include "key_define.h"
#include "led.h"

#ifdef MIDI
	const KEY_DEFINE keytable[SCENE_COUNT][KEY_DEFINE_COUNT] = {
		{	//Scene0 Button (Library Tab)
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 1"},		//L0M0	SW1
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 2"},		//L0M1	SW2
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 3"},		//L0M2	SW3
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 4"},		//L0M3	SW4
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"2nd Mon."},	//L1M0	SW6
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 0"},		//L1M1	SW7
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Zoom In"},		//L1M2	SW8
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Undo"},		//L1M3	SW9
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rate 5"},		//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT * 2,	"Scene1"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L2M2	rot4 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L2M3	rot5 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Rate res."},	//L3M0	rot1 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Flag res."},	//L3M1	rot2 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT,	"Reject"},		//L3M3	rot0 push
			//Scence0 Rotators
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	NULL},			//rot0 CW
			{LED_COLOR_RED,		LED_TIMER_DEFAULT,	NULL},			//rot0 CCW
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Rate \x5"},	//rot1 CW
			{LED_COLOR_BLUE,	LED_TIMER_DEFAULT,	"Rate \x6"},	//rot1 CCW
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Flag \x5"},	//rot2 CW
			{LED_COLOR_GREEN,	LED_TIMER_DEFAULT,	"Flag \x6"},	//rot2 CCW
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rotate \x7"},	//rot3 CW
			{LED_COLOR_YELLOW,	LED_TIMER_DEFAULT,	"Rotate \x8"},	//rot3 CCW
			{LED_COLOR_MAGENTA,	LED_TIMER_DEFAULT,	"Scroll \x5"},	//rot4 CW
			{LED_COLOR_MAGENTA,	LED_TIMER_DEFAULT,	"Scroll \x6"},	//rot4 CCW
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT,	"Zoom In"},		//rot5 CW
			{LED_COLOR_ORANGE,	LED_TIMER_DEFAULT,	"Zoom Out"},	//rot5 CCW
		},{	//Scene1 Button
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M0	SW1
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M1	SW2
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M2	SW3
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M3	SW4
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M0	SW6
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M3	SW9
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT * 2,	"Scene2"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M2	rot4 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M3	rot5 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M0	rot1 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M1	rot2 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M3	rot0 push
			//Scence1 Rotators
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CCW
		},{	//Scene2 Button
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M0	SW1
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M1	SW2
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M2	SW3
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M3	SW4
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M0	SW6
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M3	SW9
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT * 2,	"Scene3"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M2	rot4 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M3	rot5 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M0	rot1 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M1	rot2 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M3	rot0 push
			//Scence2 Rotators
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CCW
		},{	//Scene3 Button
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M0	SW1
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M1	SW2
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M2	SW3
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L0M3	SW4
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M0	SW6
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M1	SW7
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M2	SW8
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L1M3	SW9
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M0	SW5
			{LED_COLOR_WHITE,	LED_TIMER_DEFAULT * 2,	"Scene0"},	//L2M1	SW10 [SCENE]
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M2	rot4 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L2M3	rot5 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M0	rot1 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M1	rot2 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M2	rot3 push
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//L3M3	rot0 push
			//Scence3 Rotators
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot0 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot1 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot2 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot3 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot4 CCW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CW
			{LED_COLOR_OFF,		LED_TIMER_DEFAULT,	NULL},			//rot5 CCW
		},
	};
#else

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
		{HID_NONM,			HID_RIGHT,	NULL},	//rots CW
		{HID_NONM,			HID_LEFT,	NULL},	//rots CCW
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
		{HID_NONM,			HID_RIGHT,	NULL},	//rots CW
		{HID_NONM,			HID_LEFT,	NULL},	//rots CCW
	#endif
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
		{HID_NONM,			HID_NONE,	NULL},	//padding
	};
#endif
