/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define OUT0_Pin GPIO_PIN_0
#define OUT0_GPIO_Port GPIOA
#define OUT1_Pin GPIO_PIN_1
#define OUT1_GPIO_Port GPIOA
#define OUT2_Pin GPIO_PIN_2
#define OUT2_GPIO_Port GPIOA
#define OUT3_Pin GPIO_PIN_3
#define OUT3_GPIO_Port GPIOA
#define OUT4_Pin GPIO_PIN_4
#define OUT4_GPIO_Port GPIOA
#define OUT5_Pin GPIO_PIN_5
#define OUT5_GPIO_Port GPIOA
#define OUT6_Pin GPIO_PIN_6
#define OUT6_GPIO_Port GPIOA
#define OUT7_Pin GPIO_PIN_7
#define OUT7_GPIO_Port GPIOA
#define BUTTON_Pin GPIO_PIN_0
#define BUTTON_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_1
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_2
#define BUTTON2_GPIO_Port GPIOB
#define OUT2_12_Pin GPIO_PIN_12
#define OUT2_12_GPIO_Port GPIOB
#define OUT2_13_Pin GPIO_PIN_13
#define OUT2_13_GPIO_Port GPIOB
#define OUT2_14_Pin GPIO_PIN_14
#define OUT2_14_GPIO_Port GPIOB
#define OUT2_15_Pin GPIO_PIN_15
#define OUT2_15_GPIO_Port GPIOB
#define OUT8_Pin GPIO_PIN_8
#define OUT8_GPIO_Port GPIOA
#define OUT9_Pin GPIO_PIN_9
#define OUT9_GPIO_Port GPIOA
#define OUT10_Pin GPIO_PIN_10
#define OUT10_GPIO_Port GPIOA
#define OUT11_Pin GPIO_PIN_11
#define OUT11_GPIO_Port GPIOA
#define OUT12_Pin GPIO_PIN_12
#define OUT12_GPIO_Port GPIOA
#define OUT13_Pin GPIO_PIN_13
#define OUT13_GPIO_Port GPIOA
#define OUT14_Pin GPIO_PIN_14
#define OUT14_GPIO_Port GPIOA
#define OUT15_Pin GPIO_PIN_15
#define OUT15_GPIO_Port GPIOA
#define OUT2_3_Pin GPIO_PIN_3
#define OUT2_3_GPIO_Port GPIOB
#define OUT2_4_Pin GPIO_PIN_4
#define OUT2_4_GPIO_Port GPIOB
#define OUT2_5_Pin GPIO_PIN_5
#define OUT2_5_GPIO_Port GPIOB
#define OUT2_6_Pin GPIO_PIN_6
#define OUT2_6_GPIO_Port GPIOB
#define OUT2_7_Pin GPIO_PIN_7
#define OUT2_7_GPIO_Port GPIOB
#define OUT2_8_Pin GPIO_PIN_8
#define OUT2_8_GPIO_Port GPIOB
#define OUT2_9_Pin GPIO_PIN_9
#define OUT2_9_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
