/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#define Button3_Pin GPIO_PIN_13
#define Button3_GPIO_Port GPIOC
#define Button1_Pin GPIO_PIN_0
#define Button1_GPIO_Port GPIOA
#define Button2_Pin GPIO_PIN_1
#define Button2_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define WALK_Xb_Pin GPIO_PIN_10
#define WALK_Xb_GPIO_Port GPIOB
#define WALK_Ya_Pin GPIO_PIN_7
#define WALK_Ya_GPIO_Port GPIOC
#define LEDY1_A_Pin GPIO_PIN_8
#define LEDY1_A_GPIO_Port GPIOA
#define LEDY1_B_Pin GPIO_PIN_9
#define LEDY1_B_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LEDX1_A_Pin GPIO_PIN_3
#define LEDX1_A_GPIO_Port GPIOB
#define WALK_Xa_Pin GPIO_PIN_4
#define WALK_Xa_GPIO_Port GPIOB
#define LEDX1_B_Pin GPIO_PIN_5
#define LEDX1_B_GPIO_Port GPIOB
#define WALK_Yb_Pin GPIO_PIN_6
#define WALK_Yb_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
