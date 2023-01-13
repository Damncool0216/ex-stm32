#ifndef __EXTI_H
#define __EXTI_H

#include "./BSP/BEEP/beep.h"
#include "./BSP/KEY/key.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/sys/sys.h"


#define KEY0_INT_GPIO_PORT GPIOE
#define KEY0_INT_GPIO_PIN GPIO_PIN_4

#define KEY0_INT_GPIO_CLK_ENABLE      \
    do {                              \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY0_INT_IRQn EXTI4_IRQn
#define KEY0_INT_IRQHandler EXTI4_IRQHandler

#define KEY1_INT_GPIO_PORT GPIOE
#define KEY1_INT_GPIO_PIN GPIO_PIN_3

#define KEY1_INT_GPIO_CLK_ENABLE      \
    do {                              \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY1_INT_IRQn EXTI3_IRQn
#define KEY1_INT_IRQHandler EXTI3_IRQHandler

#define WKUP_INT_GPIO_PORT GPIOA
#define WKUP_INT_GPIO_PIN GPIO_PIN_0

#define WKUP_INT_GPIO_CLK_ENABLE      \
    do {                              \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)
#define WKUP_INT_IRQn EXTI0_IRQn
#define WKUP_INT_IRQHandler EXTI0_IRQHandler

void exti_init(void);

#endif