/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
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
#ifndef __STM32F0xx_IT_H
#define __STM32F0xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

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

 //! LrE-6 Ports on Board
#define Mx_GPIO_Port GPIOA
#define ENC0_GPIO_Port GPIOB
#define ENC1_GPIO_Port GPIOA
#define ENC2_GPIO_Port GPIOB
#define ENC3_GPIO_Port GPIOB
#define ENC4_GPIO_Port GPIOC
#define ENC5_GPIO_Port GPIOF

// Definitions for Encoders
#define PRMASK_E0	0x3000
#define PRMASK_E1	0x0030
#define PRMASK_E2	0x0300
#define PRMASK_E3	0x0C00
#define PRMASK_E4	0xC000
#define PRMASK_E5	0x0003

enum enc_move_t {
	ENC_STOPPED = 0,
	ENC_MOVE_CW,
	ENC_MOVE_CCW,
	ENC_INVALID,
};

#define ENC_MASK	0x03

// Definitions for Matrix
#define LxMASK	0x0F

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_1_IRQHandler(void);
void EXTI4_15_IRQHandler(void);
void DMA1_Channel4_5_6_7_IRQHandler(void);
void TIM1_BRK_UP_TRG_COM_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);
void I2C1_IRQHandler(void);
void USB_IRQHandler(void);
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F0xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
