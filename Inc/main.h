/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "stm32f1xx_hal.h"

#define __EX 10

#ifdef __EX

#if (__EX == 1) /* 实验1 跑马灯 */
#include "ex1.h"
#elif (__EX == 2) /*实验2 蜂鸣器 */
#include "ex2.h"
#elif (__EX == 3) /*实验3 独立按键 */
#include "ex3.h"
#elif (__EX == 4) /*实验4 外部中断 */
#include "ex4.h"
#elif (__EX == 5) /*实验5 串口通信 */
#include "ex5.h"
#elif (__EX == 6) /*实验6 独立看门狗 */
#include "ex6.h"
#elif (__EX == 7) /*实验7 窗口看门狗 */
#include "ex7.h"
#elif (__EX == 8) /*实验8 基本定时器中断实验 */
#include "ex8.h"
#elif (__EX == 9) /*实验9 通用定时器中断实验 */
#include "ex9.h"
#elif (__EX == 10) /*实验10 通用定时器PWM实验 */
#include "ex10.h"
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
