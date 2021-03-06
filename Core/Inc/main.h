/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file	main.h
  * @brief	Header for main.c file.
  *         This file contains the common defines of the application.
  * @author	remov-b4-flight
  * @copyright GPLv3
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
#define USBD_DEVICE_VER_MIN	0x47
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
        unsigned int  uu:4;		//dummy
    } nb;
} KEYSCAN;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define MSG_LINES	2
#define MSG_WIDTH	16
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Delay_us(uint32_t microsec);
void Start_LCDTimer(uint32_t tick);
uint16_t get_Rotary_Encoder(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TIM_PRESC_1uS 47
#define TIM_PRESC_100uS 4799
#define TIM_PERIOD_4mS 4000
#define TIM_PERIOD_1SEC 10000
#define TIM_PERIOD_125uS 125
#define TIM_PERIOD_10mS 10000
#define LrE6_PID 0x0BEA
#define LrE6_PRODUCT "LrE-6"
#define LrE6_VENDOR "Ruffles Inc."
#define PWM_PERIOD 59	//1.25 us
#define PWM_HI 38 //791ns
#define PWM_LO 15 //312ns
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
#undef		LrE6_PID
#undef		LrE6_PRODUCT
#if MIDI
	#define LrE6_PID 0xA320
	#define LrE6_PRODUCT "LrE-6"
#else
	#define	LrE6_PID 0xB737
	#define LrE6_PRODUCT "LrKB"
	#define LrE6_WIN	1	//Use windows shortcut.
#endif
#define LrE6_VENDOR "Ruffles Inc."

#if ENC_9R5KQ
//! 9R5KQ type Encoder
enum enc9R5_t {
	ENC_MV3 =	3,
	ENC_MV2	=	2,
	ENC_MV1	=	1,
	ENC_MV0	=	0,
};
#endif
//! LrE-6 Ports on Board
#define Mx_GPIO_Port GPIOA
#define ENC1_GPIO_Port GPIOA
#define ENC230_GPIO_Port GPIOB
#define ENC4_GPIO_Port GPIOC
#define ENC5_GPIO_Port GPIOF

//! LrE-6 Hardware definition
#define KEY_COUNT	16
#define	ENC_COUNT	6

//! LrE-6 States
enum lre6_state_t {
	LRE6_RESET,        //!< LRE6_RESET
	LRE6_USB_NOLINK,   //!< LRE6_USB_NOLINK
	LRE6_USB_LINKUP,   //!< LRE6_USB_LINKUP
	LRE6_USB_LINKED,   //!< LRE6_USB_LINKED
	LRE6_USB_LINK_LOST,//!< LRE6_USB_LINK_LOST
};

//! Key matrix lines
enum {
	L0 = 0,
	L1,
	L2,
	L3
};

#if MIDI
//! Scene definition in MIDI
enum {
	LrE6_SCENE0 = 0,
	LrE6_SCENE1 = 1,
	LrE6_SCENE2 = 2,
	LrE6_SCENE3 = 3,
};
#else
#define	LrE6_SCENE0 0
#endif
//! Encoder definitions
enum {
	LrE6_ENC0 = 0,
	LrE6_ENC1,
	LrE6_ENC2,
	LrE6_ENC3,
	LrE6_ENC4,
	LrE6_ENC5,
};

#define SCENE_COUNT		4
//! Define key that designated for scene change.
#define SCENE_BIT		9
#define KEY_PER_SCENE	(KEY_COUNT)
#define	CC_CH_PER_SCENE	16
#define NOTES_PER_SCENE	32
//! Key define structure
#define KEY_DEFINE_COUNT	( KEY_COUNT + (ENC_COUNT * 2) )

#define LxMASK	0x0F
//
#define PRMASK_R0	0x3000
#define PRMASK_R1	0x0030
#define PRMASK_R2	0x0300
#define PRMASK_R3	0x0C00
#define PRMASK_R4	0xC000
#define PRMASK_R5	0x0003

// Screen timer definitions
#define MSG_TIMER_DEFAULT	1000	//4s (1 tick=4ms)
#define MSG_TIMER_INIT		10      //40ms SSD1306 initialize time
#define MSG_TIMER_UPDATE	250		//1s (LCD update in USB not connected)

// LED timer definitions
#define LED_TIM_NORM		25		//400ms (1 tick=16ms)
#define LED_TIM_HALF		12		//192ms
#define LED_TIM_LONG		35		//560ms
#define	LED_TIM_CONNECT		150

#define ENC_NOT_MOVE        0
#define ENC_MOVE_CW         1
#define ENC_MOVE_CCW        2
#define ENC_MASK			0x03
#define MOD_SW_BIT_MASK		0x0fffffff

//! I2C time definitions
#define I2C_RETRY_WAIT		8

//! For temperature calculator
#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
#define VDD_CALIB ((uint16_t) (330))
#define VDD_APPLI ((uint16_t) (300))

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
