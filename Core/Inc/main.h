/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file	main.h
  * @brief	Header for main.c file.
  * 		This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define USBD_DEVICE_VER_MAJ	0x00
#define USBD_DEVICE_VER_MIN	0x58
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef union keyscan_t {
    uint32_t wd;
    struct ks_bit_t {
		unsigned char n0:4;		//Switch Line0
		unsigned char n1:4;		//Switch Line1
		unsigned char n2:4;		//Switch Line2
		unsigned char n3:4;		//Switch Line3
		unsigned char enc0:2;	//Rotary encoder
		unsigned char enc1:2;	//Rotary encoder
		unsigned char enc2:2;	//Rotary encoder
		unsigned char enc3:2;	//Rotary encoder
		unsigned char enc4:2;	//Rotary encoder
		unsigned char enc5:2;	//Rotary encoder
        unsigned char dummy:4;	//dummy
    } nb;
} KEYSCAN;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Lr_PID 0xA320
#define TIM_PERIOD_24mS 24576
#define TIM_PERIOD_8mS 7999
#define TIM_PERIOD_32mS 32768
#define TIM_PERIOD_125uS 125
#define PWM_HI 38
#define TIM_PRESC_1uS 47
#define Lr_VENDOR "Ruffles Inc."
#define PWM_LO 15
#define Lr_PRODUCT "LrE-6"
#define PWM_PERIOD 59
#define TIM_PERIOD_100uS 99
#define ENC_4A_Pin GPIO_PIN_14
#define ENC_4A_GPIO_Port GPIOC
#define ENC_4A_EXTI_IRQn EXTI4_15_IRQn
#define ENC_4B_Pin GPIO_PIN_15
#define ENC_4B_GPIO_Port GPIOC
#define ENC_4B_EXTI_IRQn EXTI4_15_IRQn
#define ENC_5A_Pin GPIO_PIN_0
#define ENC_5A_GPIO_Port GPIOF
#define ENC_5A_EXTI_IRQn EXTI0_1_IRQn
#define ENC_5B_Pin GPIO_PIN_1
#define ENC_5B_GPIO_Port GPIOF
#define ENC_5B_EXTI_IRQn EXTI0_1_IRQn
#define M0_Pin GPIO_PIN_0
#define M0_GPIO_Port GPIOA
#define M1_Pin GPIO_PIN_1
#define M1_GPIO_Port GPIOA
#define M2_Pin GPIO_PIN_2
#define M2_GPIO_Port GPIOA
#define M3_Pin GPIO_PIN_3
#define M3_GPIO_Port GPIOA
#define ENC_1A_Pin GPIO_PIN_4
#define ENC_1A_GPIO_Port GPIOA
#define ENC_1A_EXTI_IRQn EXTI4_15_IRQn
#define ENC_1B_Pin GPIO_PIN_5
#define ENC_1B_GPIO_Port GPIOA
#define ENC_1B_EXTI_IRQn EXTI4_15_IRQn
#define LED_DON_Pin GPIO_PIN_6
#define LED_DON_GPIO_Port GPIOA
#define L3_Pin GPIO_PIN_2
#define L3_GPIO_Port GPIOB
#define ENC_3A_Pin GPIO_PIN_10
#define ENC_3A_GPIO_Port GPIOB
#define ENC_3A_EXTI_IRQn EXTI4_15_IRQn
#define ENC_3B_Pin GPIO_PIN_11
#define ENC_3B_GPIO_Port GPIOB
#define ENC_3B_EXTI_IRQn EXTI4_15_IRQn
#define ENC_6A_Pin GPIO_PIN_12
#define ENC_6A_GPIO_Port GPIOB
#define ENC_6A_EXTI_IRQn EXTI4_15_IRQn
#define ENC_6B_Pin GPIO_PIN_13
#define ENC_6B_GPIO_Port GPIOB
#define ENC_6B_EXTI_IRQn EXTI4_15_IRQn
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define L0_Pin GPIO_PIN_3
#define L0_GPIO_Port GPIOB
#define L1_Pin GPIO_PIN_4
#define L1_GPIO_Port GPIOB
#define L2_Pin GPIO_PIN_5
#define L2_GPIO_Port GPIOB
#define SCL_Pin GPIO_PIN_6
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOB
#define ENC_2A_Pin GPIO_PIN_8
#define ENC_2A_GPIO_Port GPIOB
#define ENC_2A_EXTI_IRQn EXTI4_15_IRQn
#define ENC_2B_Pin GPIO_PIN_9
#define ENC_2B_GPIO_Port GPIOB
#define ENC_2B_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */
#undef	Lr_PID
#undef	Lr_PRODUCT
#define Lr_PID 0xA320
#define Lr_PRODUCT "LrE-6"
#define Lr_VENDOR "Ruffles Inc."

//! LrE-6 Ports on Board
#define Mx_GPIO_Port GPIOA
#define ENC1_GPIO_Port GPIOA
#define ENC230_GPIO_Port GPIOB
#define ENC4_GPIO_Port GPIOC
#define ENC5_GPIO_Port GPIOF

//! Lr**** Hardware definition
#define KEY_COUNT	16
#define	ENC_COUNT	6

//! Lr**** States
enum lr_state_t {
	LR_RESET,        //!< LR_RESET
	LR_USB_NOLINK,   //!< LRE6_USB_NOLINK
	LR_USB_LINKUP,   //!< LR_USB_LINKUP
	LR_USB_LINKED,   //!< LR_USB_LINKED
	LR_USB_LINK_LOST,//!< LR_USB_LINK_LOST
};

//! Key matrix lines
enum {
	L0 = 0,
	L1,
	L2,
	L3
};

//! Scene definition in MIDI
enum lr_scene_t {
	Lr_SCENE0 = 0,
	Lr_SCENE1 = 1,
	Lr_SCENE2 = 2,
	Lr_SCENE3 = 3,
};
#define	SCENE_COUNT		4

//! Encoder definitions
enum lr_enc_t {
	Lr_ENC0 = 0,
	Lr_ENC1,
	Lr_ENC2,
	Lr_ENC3,
	Lr_ENC4,
	Lr_ENC5,
};
//! Define key that designated for scene change.
#define SCENE_BIT			9
#define CC_CH_OFFSET		64
#define CC_CH_PER_SCENE		8
#define NOTES_PER_SCENE		32
//! Key define structure
#define DEFINES_PER_SCENE	( KEY_COUNT + (ENC_COUNT * 2) )

// Screen timer definitions
#define MSG_TIMER_DEFAULT	122		//4Sec (1 tick=32.7ms)
#define MSG_TIMER_UPDATE	31		//1Sec (OLED update in USB not connected)

// LED timer definitions
#define LED_TIM_NORM		21		//500ms (1 tick=24ms)
#define LED_TIM_HALF		11		//250ms
#define LED_TIM_LONG		42		//1Sec
#define LED_TIM_CONNECT		83		//2Sec
//! LED TIM3 definitions
#define LED_TIM_RETRY_WAIT	21		//Transfer period for I2C

//! I2C time definitions
#define I2C_RETRY_WAIT		2		//Transfer period for TIM3 PWM

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
