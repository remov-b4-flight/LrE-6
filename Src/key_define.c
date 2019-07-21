#include "main.h"
#include "key_define.h"

const KEY_DEFINE keytable[KEY_DEFINE_COUNT] = {
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
    {HID_NONM,			HID_NONE,	"[Mode]  "},	//L2M1	SW10 [MODE]
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
    {HID_NONM,			HID_NONE,	NULL},	//padding
    {HID_NONM,			HID_NONE,	NULL},	//padding
    {HID_NONM,			HID_NONE,	NULL},	//padding
    {HID_NONM,			HID_NONE,	NULL},	//padding
};
