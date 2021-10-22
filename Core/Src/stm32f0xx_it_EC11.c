/**
 * @file : stm32f0xx_it_EC11.c
 * @author : remov_b4_flight
 * @brief : IRQ Handlers for EC11 type rotary encoders
 * @note : This file is provided as 'UNTESTED'
 */
#include "main.h"
#include "stm32f0xx_it.h"
#include <stdbool.h>

//! previous value of encoder 0
extern uint8_t     enc0_prev;
//! previous value of encoder 1
extern uint8_t     enc1_prev;
//! previous value of encoder 2
extern uint8_t     enc2_prev;
//! previous value of encoder 3
extern uint8_t     enc3_prev;
//! previous value of encoder 4
extern uint8_t     enc4_prev;
//! previous value of encoder 5
extern uint8_t     enc5_prev;

extern KEYSCAN	Key_Stat;
extern bool		isKeyPressed;
extern bool		isKeyRelaseSent;

#if !(ENC_9R5KQ)
/**
  * @brief This function handles EXTI line 0 and 1 interrupts.
  */
void EXTI0_1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_1_IRQn 0 */
    uint32_t pr = EXTI->PR;
	uint8_t	r5 = (ENC5_GPIO_Port->IDR) & ENC_MASK;
	//rotator 5
	if( pr & PRMASK_R5 ){
	  if (r5 == ENC_MOVE) {
	      if( enc5_prev == ENC_MVCCW ){ //CCW
	          Key_Stat.nb.enc5 = ENC_MOVE_CCW;
	          MIDI_CC_Dec(LrE6_ENC5);
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }else if( enc5_prev == ENC_MVCW ){ //CW
	          Key_Stat.nb.enc5 = ENC_MOVE_CW;
	          MIDI_CC_Inc(LrE6_ENC5);
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }
	  }else if( r5 == ENC_NOMV ){
			Key_Stat.nb.enc5 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
	  }
	  enc5_prev = r5;
	}

  /* USER CODE END EXTI0_1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI0_1_IRQn 1 */

  /* USER CODE END EXTI0_1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line 4 to 15 interrupts.
  */
void EXTI4_15_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_15_IRQn 0 */
    uint32_t pr = EXTI->PR;

    uint8_t	ra = (ENC1_GPIO_Port->IDR);
    uint8_t	r230 = ( (ENC230_GPIO_Port->IDR) >> 8 );

    // Rotator1
    if(pr & PRMASK_R1){// EXTI4,5
        uint8_t	r1 = ( ra >> 4 ) & ENC_MASK;
		if ( r1 == ENC_MOVE ) {
			if( enc1_prev == ENC_MVCCW ){ //CCW
				Key_Stat.nb.enc1 = ENC_MOVE_CCW;
		        MIDI_CC_Dec(LrE6_ENC1);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( enc1_prev == ENC_MVCW ){ //CW
				Key_Stat.nb.enc1 = ENC_MOVE_CW;
		        MIDI_CC_Inc(LrE6_ENC1);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r1 == ENC_NOMV ){
			Key_Stat.nb.enc1 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    enc1_prev = r1;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
		if (isKeyPressed)
			  return;
    }
    //Rotator 2
    if(pr & PRMASK_R2){ //EXTI8,9
    	uint8_t	r2 = r230 & ENC_MASK;
		if ( r2 == ENC_MOVE ) {
			if( enc2_prev == ENC_MVCCW ){ //CCW
		        MIDI_CC_Dec(LrE6_ENC2);
				Key_Stat.nb.enc2 = ENC_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( enc2_prev == ENC_MVCW ){ //CW
				MIDI_CC_Inc(LrE6_ENC2);
				Key_Stat.nb.enc2 = ENC_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r2 == ENC_NOMV ){
			Key_Stat.nb.enc2 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
		enc2_prev = r2;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
		if(isKeyPressed)
			return;
    }

    //Rotator 3
	if( pr & PRMASK_R3 ){	//EXTI10,11
		uint8_t	r3 = ( r230 >> 2 ) & ENC_MASK;
		if ( r3 == ENC_MOVE ) {
			if( enc3_prev == ENC_MVCCW ){ //CCW
				MIDI_CC_Dec(LrE6_ENC3);
				Key_Stat.nb.enc3 = ENC_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( enc3_prev == ENC_MVCW ){ //CW
		        MIDI_CC_Inc(LrE6_ENC3);
				Key_Stat.nb.enc3 = ENC_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r3 == ENC_NOMV ){
			Key_Stat.nb.enc3 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    enc3_prev = r3;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
		if(isKeyPressed)
			return;
	}

    //Rotator 4
    if(pr & PRMASK_R4){ //EXTI14&15
    	uint8_t	r4 = ( (ENC4_GPIO_Port->IDR) >> 14 ) & ENC_MASK;
		if ( r4 == ENC_MOVE ) {
			if( enc4_prev == ENC_MVCCW ){ //CCW
		        MIDI_CC_Dec(LrE6_ENC4);
				Key_Stat.nb.enc4 = ENC_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( enc4_prev == ENC_MVCW ){ //CW
		        MIDI_CC_Inc(LrE6_ENC4);
				Key_Stat.nb.enc4 = ENC_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r4 == ENC_NOMV ){
			Key_Stat.nb.enc4 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    enc4_prev = r4;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
		if(isKeyPressed)
			return;
    }

    //Rotator 0(selector)
    if( pr & PRMASK_R0 ){ //EXTI12,13
    	uint8_t	r0 = ( r230 >> 4 ) & ENC_MASK;
    	if ( r0 == ENC_MOVE ) {
			if( enc0_prev == ENC_MVCCW ){ //CCW
				Key_Stat.nb.enc0 = ENC_MOVE_CCW;
		        MIDI_CC_Dec(LrE6_ENC0);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( enc0_prev == ENC_MVCW ){ //CW
				Key_Stat.nb.enc0 = ENC_MOVE_CW;
		        MIDI_CC_Inc(LrE6_ENC0);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r0 == ENC_NOMV ){
			Key_Stat.nb.enc0 = ENC_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    enc0_prev = r0;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
		if(isKeyPressed)
			return;

    }
  /* USER CODE END EXTI4_15_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
  /* USER CODE BEGIN EXTI4_15_IRQn 1 */

  /* USER CODE END EXTI4_15_IRQn 1 */
}
#endif
