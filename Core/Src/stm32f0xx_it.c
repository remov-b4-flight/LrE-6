/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include <string.h>
#include "midi.h"
#include "stm32f0xx_hal_tim.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
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

extern uint8_t	Key_Line;
extern bool		isKeyPressed;
extern KEYSCAN	Key_Stat;
extern char		*Msg_Buffer[];

extern bool		LED_Timer_Update;
extern bool		Msg_Timer_Update;
extern uint8_t	MIDI_CC_Value[SCENE_COUNT][ENC_COUNT];
extern uint8_t	LrScene;

uint32_t previous_scan = 0;
uint32_t previous_key = 0;
uint32_t current_key = 0;
//! Value of scanned from key matrix.
KEYSCAN current_scan;
uint8_t	enc_prev[ENC_COUNT];
uint8_t	enc_timer[ENC_COUNT];

uint8_t enc_table[4][4] = {
//now =	0			1				2				3
	{ENC_INVALID,	ENC_MOVE_CW,	ENC_MOVE_CCW,	ENC_INVALID,	},//prev = 0
	{ENC_STOPPED,	ENC_INVALID,	ENC_INVALID,	ENC_STOPPED,	},//prev = 1
	{ENC_STOPPED,	ENC_INVALID,	ENC_INVALID,	ENC_STOPPED,	},//prev = 2
	{ENC_INVALID,	ENC_MOVE_CCW,	ENC_MOVE_CW,	ENC_INVALID,	},//prev = 3
};

static inline void MIDI_CC_Inc(uint8_t enc){
	if (MIDI_CC_Value[LrScene][enc] < MIDI_CC_MAX ) MIDI_CC_Value[LrScene][enc]++;
}

static inline void MIDI_CC_Dec(uint8_t enc){
	if (MIDI_CC_Value[LrScene][enc] >= (MIDI_CC_MIN + 1) ) MIDI_CC_Value[LrScene][enc]--;
}

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_FS;
extern DMA_HandleTypeDef hdma_i2c1_tx;
extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_tim3_ch1_trig;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
/* USER CODE BEGIN EV */
extern TIM_HandleTypeDef htim3;
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
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
  strcpy(Msg_Buffer[0],"Hard Fault");
  SSD1306_Render2Buffer();
  SSD1306_FlashScreen();
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
	// Encoder 5
	if( pr & PRMASK_R5 ){
	uint8_t	r5 = (ENC5_GPIO_Port->IDR) & ENC_MASK;
   	uint8_t op = enc_table[enc_prev[Lr_ENC5]][r5];
	enc_prev[Lr_ENC5] = r5;

    	if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc5 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC5);
			isKeyPressed = true;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc5 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC5);
	        isKeyPressed = true;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc5 = ENC_STOPPED;
			isKeyPressed = true;
    	}else{
			Key_Stat.nb.enc5 = ENC_STOPPED;
			isKeyPressed = false;
    	}
	}

  /* USER CODE END EXTI0_1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(ENC_5A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_5B_Pin);
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

    // Encoder 1
    if(pr & PRMASK_R1){
	    uint8_t	ra = (ENC1_GPIO_Port->IDR);
        uint8_t	r1 = ( ra >> 4 ) & ENC_MASK;
    	uint8_t op = enc_table[enc_prev[Lr_ENC1]][r1];
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
    	if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc1 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC1);
			isKeyPressed = true;
			return;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc1 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC1);
	        isKeyPressed = true;
	        return;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc1 = ENC_STOPPED;
			isKeyPressed = true;
			return;
    	}else{
			Key_Stat.nb.enc1 = ENC_STOPPED;
			isKeyPressed = false;
    	}
    }


    //Encoder 2
    if(pr & PRMASK_R2){ 
	    uint8_t	r230 = ( (ENC230_GPIO_Port->IDR) >> 8 );
    	uint8_t	r2 = r230 & ENC_MASK;
    	uint8_t op = enc_table[enc_prev[Lr_ENC2]][r2];
		enc_prev[Lr_ENC2] = r2;
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);

		if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc2 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC2);
			isKeyPressed = true;
			return;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc2 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC2);
	        isKeyPressed = true;
	        return;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc2 = ENC_STOPPED;
			isKeyPressed = true;
			return;
    	}else{
			Key_Stat.nb.enc2 = ENC_STOPPED;
			isKeyPressed = false;
    	}
    }

    //Rotator 3
	if( pr & PRMASK_R3 ){
	    uint8_t	r230 = ( (ENC230_GPIO_Port->IDR) >> 8 );
		uint8_t	r3 = ( r230 >> 2 ) & ENC_MASK;
    	uint8_t op = enc_table[enc_prev[Lr_ENC3]][r3];
		enc_prev[Lr_ENC3] = r3;
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);

    	if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc3 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC3);
			isKeyPressed = true;
			return;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc3 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC3);
	        isKeyPressed = true;
	        return;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc3 = ENC_STOPPED;
			isKeyPressed = true;
			return;
    	}else{
			Key_Stat.nb.enc3 = ENC_STOPPED;
			isKeyPressed = false;
    	}
	}

    //Encoder 4
    if(pr & PRMASK_R4){
    	uint8_t	r4 = ( (ENC4_GPIO_Port->IDR) >> 14 ) & ENC_MASK;
    	uint8_t op = enc_table[enc_prev[Lr_ENC4]][r4];
		enc_prev[Lr_ENC4] = r4;
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
    	if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc4 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC4);
			isKeyPressed = true;
			return;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc4 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC4);
	        isKeyPressed = true;
	        return;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc4 = ENC_STOPPED;
			isKeyPressed = true;
			return;
    	}else{
			Key_Stat.nb.enc4 = ENC_STOPPED;
			isKeyPressed = false;
    	}
    }

    //Encoder 0(selector)
    if( pr & PRMASK_R0 ){
	    uint8_t	r230 = ( (ENC230_GPIO_Port->IDR) >> 8 );
    	uint8_t	r0 = ( r230 >> 4 ) & ENC_MASK;
    	uint8_t op = enc_table[enc_prev[Lr_ENC0]][r0];
		enc_prev[Lr_ENC0] = r0;
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
    	if (op == ENC_MOVE_CW) {
			Key_Stat.nb.enc0 = ENC_MOVE_CW;
	        MIDI_CC_Inc(Lr_ENC0);
			isKeyPressed = true;
			return;
    	}else if(op == ENC_MOVE_CCW){
			Key_Stat.nb.enc0 = ENC_MOVE_CCW;
	        MIDI_CC_Dec(Lr_ENC0);
	        isKeyPressed = true;
	        return;
    	}else if(op == ENC_STOPPED){
			Key_Stat.nb.enc0 = ENC_STOPPED;
			isKeyPressed = true;
			return;
    	}else{
			Key_Stat.nb.enc0 = ENC_STOPPED;
			isKeyPressed = false;
    	}
  }

  /* USER CODE END EXTI4_15_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(ENC_1A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_1B_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_2A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_2B_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_3A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_3B_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_6A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_6B_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_4A_Pin);
  HAL_GPIO_EXTI_IRQHandler(ENC_4B_Pin);
  /* USER CODE BEGIN EXTI4_15_IRQn 1 */

  /* USER CODE END EXTI4_15_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 4, 5, 6 and 7 interrupts.
  */
void DMA1_Channel4_5_6_7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel4_5_6_7_IRQn 0 */
  if(DMA1->ISR & DMA_ISR_TCIF4){
	HAL_TIM_PWM_Stop_DMA(&htim3, TIM_CHANNEL_1);

	GPIOA->ODR |= GPIO_PIN_6;	//'RESET' state
	//Set PA6 AF -> GPIO
	GPIOA->MODER &= ~(GPIO_MODER_MODER6_1);
	GPIOA->MODER |=	GPIO_MODER_MODER6_0;

  }
  /* USER CODE END DMA1_Channel4_5_6_7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim3_ch1_trig);
  HAL_DMA_IRQHandler(&hdma_i2c1_tx);
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
    switch(Key_Line){
        case L0:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n0 = (r);
            Key_Line++;
            HAL_GPIO_WritePin(L0_GPIO_Port,L0_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
            break;
        case L1:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n1 = (r);
            Key_Line++;
            HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
            break;
        case L2:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n2 = (r);
            Key_Line++;
            HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
            break;
        case L3:
            r = (Mx_GPIO_Port->IDR) & LxMASK;
            current_scan.nb.n3 = (r);
            HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(L0_GPIO_Port,L0_Pin,GPIO_PIN_SET);
            Key_Line = L0;

            //Key detection
            if (previous_scan == current_scan.wd){
                current_key = current_scan.wd;
                uint32_t dif = current_key ^ previous_key;
                Key_Stat.wd = current_key;
                if (dif != 0){
                    previous_key = current_key;
                    isKeyPressed = true;
                }
            }
            previous_scan = current_scan.wd;
            break;
    }
  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 1 */

  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global and DAC channel underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */
  LED_Timer_Update = true;
  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */
  Msg_Timer_Update = true;
  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

  /* USER CODE END TIM7_IRQn 1 */
}

/**
  * @brief This function handles I2C1 event global interrupt / I2C1 wake-up interrupt through EXTI line 23.
  */
void I2C1_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_IRQn 0 */

  /* USER CODE END I2C1_IRQn 0 */
  if (hi2c1.Instance->ISR & (I2C_FLAG_BERR | I2C_FLAG_ARLO | I2C_FLAG_OVR)) {
    HAL_I2C_ER_IRQHandler(&hi2c1);
  } else {
    HAL_I2C_EV_IRQHandler(&hi2c1);
  }
  /* USER CODE BEGIN I2C1_IRQn 1 */

  /* USER CODE END I2C1_IRQn 1 */
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
