/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin|LED10_Pin|LED11_Pin
                          |LED26_Pin|LED25_Pin|LED24_Pin|LED23_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED12_Pin|LED13_Pin|LED14_Pin|LED15_Pin
                          |LED30_Pin|LED29_Pin|LED28_Pin|LED27_Pin
                          |LED22_Pin|LED21_Pin|LED20_Pin|LED19_Pin
                          |LED18_Pin|LED17_Pin|LED16_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED4_Pin LED5_Pin LED6_Pin LED7_Pin
                           LED8_Pin LED9_Pin LED10_Pin LED11_Pin
                           LED26_Pin LED25_Pin LED24_Pin LED23_Pin */
  GPIO_InitStruct.Pin = LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin|LED10_Pin|LED11_Pin
                          |LED26_Pin|LED25_Pin|LED24_Pin|LED23_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED12_Pin LED13_Pin LED14_Pin LED15_Pin
                           LED30_Pin LED29_Pin LED28_Pin LED27_Pin
                           LED22_Pin LED21_Pin LED20_Pin LED19_Pin
                           LED18_Pin LED17_Pin LED16_Pin */
  GPIO_InitStruct.Pin = LED12_Pin|LED13_Pin|LED14_Pin|LED15_Pin
                          |LED30_Pin|LED29_Pin|LED28_Pin|LED27_Pin
                          |LED22_Pin|LED21_Pin|LED20_Pin|LED19_Pin
                          |LED18_Pin|LED17_Pin|LED16_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
