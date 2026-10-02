/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_0
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_1
#define LED5_GPIO_Port GPIOA
#define LED6_Pin GPIO_PIN_2
#define LED6_GPIO_Port GPIOA
#define LED7_Pin GPIO_PIN_3
#define LED7_GPIO_Port GPIOA
#define LED8_Pin GPIO_PIN_4
#define LED8_GPIO_Port GPIOA
#define LED9_Pin GPIO_PIN_5
#define LED9_GPIO_Port GPIOA
#define LED10_Pin GPIO_PIN_6
#define LED10_GPIO_Port GPIOA
#define LED11_Pin GPIO_PIN_7
#define LED11_GPIO_Port GPIOA
#define LED12_Pin GPIO_PIN_0
#define LED12_GPIO_Port GPIOB
#define LED13_Pin GPIO_PIN_1
#define LED13_GPIO_Port GPIOB
#define LED14_Pin GPIO_PIN_10
#define LED14_GPIO_Port GPIOB
#define LED15_Pin GPIO_PIN_11
#define LED15_GPIO_Port GPIOB
#define LED30_Pin GPIO_PIN_12
#define LED30_GPIO_Port GPIOB
#define LED29_Pin GPIO_PIN_13
#define LED29_GPIO_Port GPIOB
#define LED28_Pin GPIO_PIN_14
#define LED28_GPIO_Port GPIOB
#define LED27_Pin GPIO_PIN_15
#define LED27_GPIO_Port GPIOB
#define LED26_Pin GPIO_PIN_8
#define LED26_GPIO_Port GPIOA
#define LED25_Pin GPIO_PIN_11
#define LED25_GPIO_Port GPIOA
#define LED24_Pin GPIO_PIN_12
#define LED24_GPIO_Port GPIOA
#define LED23_Pin GPIO_PIN_15
#define LED23_GPIO_Port GPIOA
#define LED22_Pin GPIO_PIN_3
#define LED22_GPIO_Port GPIOB
#define LED21_Pin GPIO_PIN_4
#define LED21_GPIO_Port GPIOB
#define LED20_Pin GPIO_PIN_5
#define LED20_GPIO_Port GPIOB
#define LED19_Pin GPIO_PIN_6
#define LED19_GPIO_Port GPIOB
#define LED18_Pin GPIO_PIN_7
#define LED18_GPIO_Port GPIOB
#define LED17_Pin GPIO_PIN_8
#define LED17_GPIO_Port GPIOB
#define LED16_Pin GPIO_PIN_9
#define LED16_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
