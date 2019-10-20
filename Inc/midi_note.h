/*
 * midi_note.h
 *
 *  Created on: 2019/09/03
 *      Author: jenok
 */

#ifndef INC_MIDI_NOTE_H_
#define INC_MIDI_NOTE_H_

#define MIDI_UNUSED				0x00

#define MIDI_CIN_NOTE_ON		0x9
#define MIDI_CIN_NOTE_OFF		0x8
#define MIDI_CIN_CONTCHG		0xB

#define MIDI_VELOCITY_DEFAULT	0x7F
#define MIDI_CABLE_NO_DEFAULT	0

#define CONFIG			0x02
#define INTERFACE		0x04
#define CS_INTERFACE	0x24
#define ENDPOINT		0x05
#define	CS_ENDPOINT		0x25
#define HEADER			0x01

#define AUDIO			0x01
#define AUDIO_CONTROL	0x01
#define MIDI_STREAM		0x03

#define MIDI_POWER		0x10 //=32mA

#define MIDI_IN_JACK	0x02
#define MIDI_OUT_JACK	0x03
#define MIDI_JACK_ENB	0x01
#define MIDI_JACK_EXT	0x02

#define MS_GENERAL		0x01
#define REFRESH			0x01


#define MDI_NT_C4	60
#define MDI_NT_C4S	61
#define MDI_NT_D4	62
#define	MDI_NT_D4S	63
#define MDI_NT_E4	64
#define MDI_NT_F4	65
#define MDI_NT_F4S	66
#define MDI_NT_G4	67
#define MDI_NT_G4S	68
#define MDI_NT_A4	69
#define MDI_NT_A4S	70
#define MDI_NT_B4	71

#define MDI_NT_C5	72
#define MDI_NT_C5S	73
#define MDI_NT_D5	74
#define	MDI_NT_D5S	75
#define MDI_NT_E5	76
#define MDI_NT_F5	77
#define MDI_NT_F5S	78
#define MDI_NT_G5	79
#define MDI_NT_G5S	80
#define MDI_NT_A5	81
#define MDI_NT_A5S	82
#define MDI_NT_B5	83

#define MDI_NT_C6	84
#define MDI_NT_C6S	85
#define MDI_NT_D6	86
#define	MDI_NT_D6S	87
#define MDI_NT_E6	88
#define MDI_NT_F6	89
#define MDI_NT_F6S	90
#define MDI_NT_G6	91
#define MDI_NT_G6S	92
#define MDI_NT_A6	93
#define MDI_NT_A6S	94
#define MDI_NT_B6	95

#define MIDI_NOTE_BASE	MDI_NT_C4

#endif /* INC_MIDI_NOTE_H_ */
