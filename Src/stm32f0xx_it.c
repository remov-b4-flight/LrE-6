/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include "stm32f0xx_hal_tim.h"
#include "i2c-lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

extern uint8_t	keyline;
extern bool		isKeyPressed;
extern bool		isKeyRelaseSent;
extern KEYSCAN	keystat;

extern bool		lcd_flag;
extern bool		lcd_timer_enable;
extern int32_t	lcd_timer;

extern uint8_t	LEDColor[];
extern uint8_t	LEDTimer[];
extern bool		led_sendpulse;
extern bool		led_timer_update;

uint32_t previous_scan = 0;
uint32_t previous_key = 0;
uint32_t current_key = 0;
KEYSCAN current_scan;
uint8_t     rots_prev;
uint8_t     rot1_prev;
uint8_t     rot2_prev;
uint8_t     rot3_prev;
uint8_t     rot4_prev;
uint8_t     rot5_prev;

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_FS;
extern DMA_HandleTypeDef hdma_tim3_ch1_trig;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim16;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
  LCD_Print("HRDFAULT");
  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line 0 and 1 interrupts.
  */
void EXTI0_1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_1_IRQn 0 */
    uint32_t pr = EXTI->PR;
	uint8_t	r5 = (ENC5_GPIO_Port->IDR) & ROT_MASK;
	if(pr & PRMASK_R5){
#if ENC_9R5KQ
    	if ( r5 == ENC_MV0 ) {
			if(rots_prev == ENC_MV2){ //CCW
				keystat.nb.rot5 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CW
	          keystat.nb.rot5 = ROT_MOVE_CCW;
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
			}
		}else if( r5 == ENC_MV3 ){
			if(rots_prev == ENC_MV2){ //CCW
				keystat.nb.rot5 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CW
				keystat.nb.rot5 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
	  if (r5 == ENC_MOVE) {
	      if(rot5_prev == ENC_MVCCW){ //CCW
	          keystat.nb.rot5 = ROT_MOVE_CCW;
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }else if(rot5_prev == ENC_MVCW){ //CW
	          keystat.nb.rot5 = ROT_MOVE_CW;
	          isKeyPressed = true;
	          isKeyRelaseSent = false;
	      }
	  }else if(r5 == ENC_NOMV){
			keystat.nb.rot5 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
	  }
#endif
	  rot5_prev = r5;
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
    uint8_t	r23s = ( (ENC23S_GPIO_Port->IDR) >> 8 );

    // Rotator1
    if(pr & PRMASK_R1){// EXTI4,5
        uint8_t	r1 = ( ra >> 4 ) & ROT_MASK;
#if	ENC_9R5KQ
    	if ( r1 == ENC_MV0 ) {
			if(rot1_prev == ENC_MV2){ //CW
				keystat.nb.rot1 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CCW
				keystat.nb.rot1 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r1 == ENC_MV3 ){
			if(rots_prev == ENC_MV2){ //CCW
				keystat.nb.rot1 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CW
				keystat.nb.rot1 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
		if (r1 == ENC_MOVE) {
			if(rot1_prev == ENC_MVCCW){ //CCW
				keystat.nb.rot1 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot1_prev == ENC_MVCW){ //CW
				keystat.nb.rot1 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if(r1 == ENC_NOMV){
			keystat.nb.rot1 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
#endif
	    rot1_prev = r1;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
		if (isKeyPressed)
			  return;
    }
    //Rotator 2
    if(pr & PRMASK_R2){ //EXTI8,9
    	uint8_t	r2 = r23s & ROT_MASK;
#if ENC_9R5KQ
    	if ( r2 == ENC_MV0 ) {
			if(rots_prev == ENC_MV2){ //CW
				keystat.nb.rot2 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CCW
				keystat.nb.rot2 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r2 == ENC_MV3 ){
			if(rots_prev == ENC_MV2){ //CCW
				keystat.nb.rot2 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CW
				keystat.nb.rot2 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
		if (r2 == ENC_MOVE) {
			if(rot2_prev == ENC_MVCCW){ //CCW
				keystat.nb.rot2 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot2_prev == ENC_MVCW){ //CW
				keystat.nb.rot2 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if(r2 == ENC_NOMV){
			keystat.nb.rot2 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
#endif
		rot2_prev = r2;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
		if(isKeyPressed)
			return;
    }

    //Rotator 3
	if(pr & PRMASK_R3){	//EXTI10,11
		uint8_t	r3 = ( r23s >> 2 ) & ROT_MASK;
#if ENC_9R5KQ
    	if ( r3 == ENC_MV0 ) {
			if(rot3_prev == ENC_MV2){ //CW
				keystat.nb.rot3 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot3_prev == ENC_MV1){ //CCW
				keystat.nb.rot3 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r3 == ENC_MV3 ){
			if(rot3_prev == ENC_MV2){ //CCW
				keystat.nb.rot3 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot3_prev == ENC_MV1){ //CW
				keystat.nb.rot3 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
		if (r3 == ENC_MOVE) {
			if(rot3_prev == ENC_MVCCW){ //CCW
				keystat.nb.rot3 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot3_prev == ENC_MVCW){ //CW
				keystat.nb.rot3 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if(r3 == ENC_NOMV){
			keystat.nb.rot3 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
#endif
	    rot3_prev = r3;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
		if(isKeyPressed)
			return;
	}

    //Rotator 4
    if(pr & PRMASK_R4){ //EXTI14&15
    	uint8_t	r4 = ( (ENC4_GPIO_Port->IDR) >> 14 ) & ROT_MASK;
#if ENC_9R5KQ
    	if ( r4 == ENC_MV0 ) {
			if(rot4_prev == ENC_MV2){ //CW
				keystat.nb.rot4 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot4_prev == ENC_MV1){ //CCW
				keystat.nb.rot4 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( r4 == ENC_MV3 ){
			if(rot4_prev == ENC_MV2){ //CCW
				keystat.nb.rot4 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot4_prev == ENC_MV1){ //CW
				keystat.nb.rot4 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
		if (r4 == ENC_MOVE) {
			if(rot4_prev == ENC_MVCCW){ //CCW
				keystat.nb.rot4 = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rot4_prev == ENC_MVCW){ //CW
				keystat.nb.rot4 = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if(r4 == ENC_NOMV){
			keystat.nb.rot4 = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
#endif
	    rot4_prev = r4;

		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
		if(isKeyPressed)
			return;
    }

    //Rotator 6(selector)
    if(pr & PRMASK_RS){ //EXTI12,13
    	uint8_t	rs = ( r23s >> 4 ) & ROT_MASK;
#if ENC_9R5KQ
    	if ( rs == ENC_MV0 ) {
			if(rots_prev == ENC_MV2){ //CW
				keystat.nb.rots = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV1){ //CCW
				keystat.nb.rots = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if( rs == ENC_MV3 ){
			if(rots_prev == ENC_MV2){ //CCW
				keystat.nb.rots = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MV2){ //CW
				keystat.nb.rots = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}
#else
    	if (rs == ENC_MOVE) {
			if(rots_prev == ENC_MVCCW){ //CCW
				keystat.nb.rots = ROT_MOVE_CCW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}else if(rots_prev == ENC_MVCW){ //CW
				keystat.nb.rots = ROT_MOVE_CW;
				isKeyPressed = true;
				isKeyRelaseSent = false;
			}
		}else if(rs == ENC_NOMV){
			keystat.nb.rots = ROT_NOT_MOVE;
			isKeyPressed = true;
			isKeyRelaseSent = true;
		}
#endif
	    rots_prev = rs;

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

/**
  * @brief This function handles DMA1 channel 2 and 3 interrupts.
  */
void DMA1_Channel2_3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 0 */

  /* USER CODE END DMA1_Channel2_3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 1 */

  /* USER CODE END DMA1_Channel2_3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 4, 5, 6 and 7 interrupts.
  */
void DMA1_Channel4_5_6_7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel4_5_6_7_IRQn 0 */
  HAL_TIM_PWM_Stop_DMA(&htim3,TIM_CHANNEL_1);
  /* USER CODE END DMA1_Channel4_5_6_7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim3_ch1_trig);
  /* USER CODE BEGIN DMA1_Channel4_5_6_7_IRQn 1 */

  /* USER CODE END DMA1_Channel4_5_6_7_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break, update, trigger and commutation interrupts.
  */
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 0 */
    uint8_t r;
    //keyboard matrix
    switch(keyline){
        case L0:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n0 = (r);
            keyline++;
            led_timer_update = true;
            HAL_GPIO_WritePin(L0_GPIO_Port,L0_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
            break;
        case L1:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n1 = (r);
            keyline++;
            HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
            break;
        case L2:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n2 = (r);
            keyline++;
            HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
            break;
        case L3:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n3 = (r);
            HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L0_GPIO_Port,L0_Pin,GPIO_PIN_SET);
            keyline = L0;

            //Key detection
            if (previous_scan==current_scan.wd){
                current_key = current_scan.wd;
                uint32_t dif = current_key ^ previous_key;
                keystat.wd = current_key;
                if (dif != 0){
                    previous_key = current_key;
                    isKeyPressed = true;
                }
            }
            if(isKeyRelaseSent==false){
            	current_key = 0;
                isKeyPressed = true;
            }
            previous_scan = current_scan.wd;
            break;
    }

    //LCD timer
    if(lcd_timer_enable == true && (--lcd_timer) <= 0){
    	lcd_timer_enable = false;
        lcd_flag = true;
    }


  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 1 */

  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 1 */
}

/**
  * @brief This function handles TIM16 global interrupt.
  */
void TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim16);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  /* USER CODE END TIM16_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt / USART1 wake-up interrupt through EXTI line 25.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USB global interrupt / USB wake-up interrupt through EXTI line 18.
  */
void USB_IRQHandler(void)
{
  /* USER CODE BEGIN USB_IRQn 0 */

  /* USER CODE END USB_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_FS);
  /* USER CODE BEGIN USB_IRQn 1 */

  /* USER CODE END USB_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
