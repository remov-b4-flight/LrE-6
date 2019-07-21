/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define USBD_DEVICE_VER_MAJ	0x00
#define USBD_DEVICE_VER_MIN	0x02
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

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
#define PWM_PERIOD 59
#define PWM_HI 29
#define PWM_LO 14
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
#define WL_EN_Pin GPIO_PIN_15
#define WL_EN_GPIO_Port GPIOB
#define WL_RST_Pin GPIO_PIN_8
#define WL_RST_GPIO_Port GPIOA
#define STM_TX_Pin GPIO_PIN_9
#define STM_TX_GPIO_Port GPIOA
#define STM_RX_Pin GPIO_PIN_10
#define STM_RX_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define BL_ON_Pin GPIO_PIN_15
#define BL_ON_GPIO_Port GPIOA
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

//LrE-6 Ports on Board
#define Mx_GPIO_Port GPIOA
#define ENC1_GPIO_Port GPIOA
#define ENC23S_GPIO_Port GPIOB
#define ENC4_GPIO_Port GPIOC
#define ENC5_GPIO_Port GPIOF
#define KEY_COUNT 16

//Key define structure
#define KEY_DEFINE_COUNT	32

typedef union {
    uint32_t wd;
    struct{
        unsigned char n0:4;
        unsigned char n1:4;
        unsigned char n2:4;
		unsigned char n3:4;
		unsigned char rot1:2;	//Selector
		unsigned char rot2:2;	//Selector
		unsigned char rot3:2;	//Selector
		unsigned char rot4:2;	//Selector
		unsigned char rot5:2;	//Selector
		unsigned char rots:2;	//Selector
        unsigned int  uu:4;	//dummy
    } nb;
} KEYSCAN;

typedef struct {
    uint8_t modifier;
    uint8_t keycode;
    char	*message;
} KEY_DEFINE;

typedef struct {
	uint8_t element[4];
} KEY_MODIFIER;

//Moved From Harmony keyboard.h
typedef struct {
	uint8_t	modifier;
	uint8_t keys[4];
} KEYBOARD_INPUT_REPORT;

//
enum {
	LRE6_RESET,
	LRE6_USB_NOLINK,
	LRE6_USB_LINKUP,
	LRE6_USB_LINKED,
	LRE6_USB_LINK_LOST,
};

//Key matrix lines
enum {
	L0 = 0,
	L1,
	L2,
	L3
};

//
enum {
	MODE_LRLITE = 0,
	MODE_LRE6
};
#define MODE_COUNT	2

#define LxMASK 0x0F
#define MOD_SW_BIT_MASK    0x0fffffff
//
#define PRMASK_R1	0x0030
#define PRMASK_R2	0x0300
#define PRMASK_R3	0x0C00
#define PRMASK_R4	0xC000
#define PRMASK_R5	0x0003
#define PRMASK_RS	0x3000

//other definitions
#define LCD_TIMER_DEFAULT   1000    //4 sec (1tick=4ms)
#define LCD_TIMER_INIT      10      //40m sec initialze time
#define LCD_TIMER_UPDATE	250		//1 sec (LCD update in non HID)

#define ROT_NOT_MOVE        0
#define ROT_MOVE_CW         1
#define ROT_MOVE_CCW        2
#define ROT_MASK			0x03
#define	ROT_COUNT			6

#define HID_RPT_KEY_IDX		1

void Delay_us(uint32_t microsec);
void Start_LCDTimer(uint32_t tick);

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
