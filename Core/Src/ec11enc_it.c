/**
 * @file ec11enc_it.c
 * @author jenoki
 * @brief LrE-6 Board EXTIx handling routine for 9.5KQ rotary encoder.
 * board R2.01 F2.2 (or above) available
 */
#include "main.h"
#include "stm32f0xx_it.h"

#include <stdbool.h>
#include <string.h>
#include "midi.h"
#include "stm32f0xx_hal_tim.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"

extern bool		isKeyPressed;
extern bool		isKeyRelaseSent;
extern KEYSCAN	Key_Stat;

extern uint8_t     rot0_prev;
extern uint8_t     rot1_prev;
extern uint8_t     rot2_prev;
extern uint8_t     rot3_prev;
extern uint8_t     rot4_prev;
extern uint8_t     rot5_prev;

#ifdef MIDI
extern uint8_t MIDI_CC_Value[SCENE_COUNT][ROT_COUNT];
extern uint8_t LrE6Scene;

#endif

static inline void MIDI_CC_Inc(uint8_t rot){
#if MIDI
	if (MIDI_CC_Value[LrE6Scene][rot] < MIDI_CC_MAX ) MIDI_CC_Value[LrE6Scene][rot]++;
#endif
}

static inline void MIDI_CC_Dec(uint8_t rot){
#if MIDI
	if (MIDI_CC_Value[LrE6Scene][rot] >= (MIDI_CC_MIN + 1) ) MIDI_CC_Value[LrE6Scene][rot]--;
#endif
}

/**
  * @brief This function handles EXTI line 0 and 1 interrupts.
  */
#if !(ENC_9R5KQ)
void EXTI0_1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_1_IRQn 0 */
    uint32_t pr = EXTI->PR;
	uint8_t	r5 = (ENC5_GPIO_Port->IDR) & ROT_MASK;
	//rotator 5
	if( pr & PRMASK_R5 ){
	  if (r5 == ENC_MOVE) {
	      if( rot5_prev == ENC_MVCCW ){ //CCW
	          Key_Stat.nb.rot5 = ROT_MOVE_CCW;
	          MIDI_CC_Dec(LrE6_ROT5);
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }else if( rot5_prev == ENC_MVCW ){ //CW
	          Key_Stat.nb.rot5 = ROT_MOVE_CW;
	          MIDI_CC_Inc(LrE6_ROT5);
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }
	  }else if( r5 == ENC_NOMV ){
			Key_Stat.nb.rot5 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
	  }
	  rot5_prev = r5;
	}

  /* USER CODE END EXTI0_1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI0_1_IRQn 1 */

  /* USER CODE END EXTI0_1_IRQn 1 */
}
#endif
/**
  * @brief This function handles EXTI line 4 to 15 interrupts.
  */
#if !(ENC_9R5KQ)
void EXTI4_15_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_15_IRQn 0 */
    uint32_t pr = EXTI->PR;

    uint8_t	ra = (ENC1_GPIO_Port->IDR);
    uint8_t	r230 = ( (ENC23S_GPIO_Port->IDR) >> 8 );

    // Rotator1
    if(pr & PRMASK_R1){// EXTI4,5
        uint8_t	r1 = ( ra >> 4 ) & ROT_MASK;
		if ( r1 == ENC_MOVE ) {
			if( rot1_prev == ENC_MVCCW ){ //CCW
				Key_Stat.nb.rot1 = ROT_MOVE_CCW;
		        MIDI_CC_Dec(LrE6_ROT1);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( rot1_prev == ENC_MVCW ){ //CW
				Key_Stat.nb.rot1 = ROT_MOVE_CW;
		        MIDI_CC_Inc(LrE6_ROT1);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r1 == ENC_NOMV ){
			Key_Stat.nb.rot1 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    rot1_prev = r1;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
		if (isKeyPressed)
			  return;
    }
    //Rotator 2
    if(pr & PRMASK_R2){ //EXTI8,9
    	uint8_t	r2 = r230 & ROT_MASK;
		if ( r2 == ENC_MOVE ) {
			if( rot2_prev == ENC_MVCCW ){ //CCW
		        MIDI_CC_Dec(LrE6_ROT2);
				Key_Stat.nb.rot2 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( rot2_prev == ENC_MVCW ){ //CW
				MIDI_CC_Inc(LrE6_ROT2);
				Key_Stat.nb.rot2 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r2 == ENC_NOMV ){
			Key_Stat.nb.rot2 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
		rot2_prev = r2;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
		if(isKeyPressed)
			return;
    }

    //Rotator 3
	if( pr & PRMASK_R3 ){	//EXTI10,11
		uint8_t	r3 = ( r230 >> 2 ) & ROT_MASK;
		if ( r3 == ENC_MOVE ) {
			if( rot3_prev == ENC_MVCCW ){ //CCW
				MIDI_CC_Dec(LrE6_ROT3);
				Key_Stat.nb.rot3 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( rot3_prev == ENC_MVCW ){ //CW
		        MIDI_CC_Inc(LrE6_ROT3);
				Key_Stat.nb.rot3 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r3 == ENC_NOMV ){
			Key_Stat.nb.rot3 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    rot3_prev = r3;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
		if(isKeyPressed)
			return;
	}

    //Rotator 4
    if(pr & PRMASK_R4){ //EXTI14&15
    	uint8_t	r4 = ( (ENC4_GPIO_Port->IDR) >> 14 ) & ROT_MASK;
		if ( r4 == ENC_MOVE ) {
			if( rot4_prev == ENC_MVCCW ){ //CCW
		        MIDI_CC_Dec(LrE6_ROT4);
				Key_Stat.nb.rot4 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( rot4_prev == ENC_MVCW ){ //CW
		        MIDI_CC_Inc(LrE6_ROT4);
				Key_Stat.nb.rot4 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r4 == ENC_NOMV ){
			Key_Stat.nb.rot4 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    rot4_prev = r4;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
		if(isKeyPressed)
			return;
    }

    //Rotator 0(selector)
    if( pr & PRMASK_R0 ){ //EXTI12,13
    	uint8_t	r0 = ( r230 >> 4 ) & ROT_MASK;
    	if ( r0 == ENC_MOVE ) {
			if( rot0_prev == ENC_MVCCW ){ //CCW
				Key_Stat.nb.rot0 = ROT_MOVE_CCW;
		        MIDI_CC_Dec(LrE6_ROT0);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if( rot0_prev == ENC_MVCW ){ //CW
				Key_Stat.nb.rot0 = ROT_MOVE_CW;
		        MIDI_CC_Inc(LrE6_ROT0);
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r0 == ENC_NOMV ){
			Key_Stat.nb.rot0 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
	    rot0_prev = r0;

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
