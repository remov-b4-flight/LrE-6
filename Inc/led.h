/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _LED_H    /* Guard against multiple inclusion */
#define _LED_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <stdint.h>
#include <stdbool.h>
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
enum{   //constants for expressing color.
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
};
#define COLOR_MAX 10

#define LED_COUNT		6
#define BITS_PER_LED    24  // (RGB) 4 * 8bit
#define TOTAL_BITS      (LED_COUNT * BITS_PER_LED)

//LED intensity definition
#define LFFH	0xFF
#define LBRIGHT	0x80
#define LMAX	0x78
#define L43		0x58
#define LHLF	0x38
#define LQTR	0x10
#define LMIN	0x08
#define LOFF	0x00

#define LED_TIMER_CONSTANT	0xFF
#define	LED_IDX_SELECTOR	0

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
typedef union leddata_t {
	uint32_t	n;
	struct	rgbw_t {
		uint8_t	padding;
		uint8_t	b;
		uint8_t	r;
		uint8_t g;
	}	rgbw;
} LEDDATA;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
    void LED_Initialize();
    void LED_TestPattern();
    void LED_Set_Quick(uint8_t index, uint8_t color);
    void LED_Set(uint8_t index, uint8_t color);
    void LED_SetPulse(uint8_t index, uint8_t color,uint8_t pulse);
    void SendPulse();
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
