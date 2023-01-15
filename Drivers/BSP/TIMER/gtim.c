#include "./BSP/TIMER/gtim.h"

TIM_HandleTypeDef g_timx_int_handler;

void gtim_timx_int_init(uint16_t arr, uint16_t psc)
{
    GTIM_TIMX_INT_CLK_ENABLE();

    g_timx_int_handler.Instance = GTIM_TIMX_INT;
    g_timx_int_handler.Init.CounterMode = TIM_COUNTERMODE_UP;
    g_timx_int_handler.Init.Period = arr;
    g_timx_int_handler.Init.Prescaler = psc;
    HAL_TIM_Base_Init(&g_timx_int_handler);

    HAL_NVIC_SetPriority(GTIM_TIMX_INT_IRQn, 1, 2);
    HAL_NVIC_EnableIRQ(GTIM_TIMX_INT_IRQn);

    HAL_TIM_Base_Start_IT(&g_timx_int_handler);
}

void GTIM_TIMX_INT_IRQHandler(void)
{
    if (__HAL_TIM_GET_FLAG(&g_timx_int_handler, TIM_FLAG_UPDATE) != RESET) {
        LED1_TOGGLE();
        __HAL_TIM_CLEAR_IT(&g_timx_int_handler, TIM_FLAG_UPDATE);
    }
}

TIM_HandleTypeDef g_timx_pwm_handler;
void gtim_timx_pwm_init(uint16_t arr, uint16_t psc)
{
    GTIM_TIMX_PWM_CLK_ENABLE();
    GTIM_TIMX_PWM_CHY_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef gpio_init;
    gpio_init.Mode = GPIO_MODE_AF_PP;
    gpio_init.Pin = GTIM_TIMX_PWM_CHY_GPIO_PIN;
    gpio_init.Pull = GPIO_PULLUP;
    gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GTIM_TIMX_PWM_CHY_CPIO_PORT, &gpio_init);
    GTIM_TIMX_PWM_CHY_GPIO_REMAP();

    g_timx_pwm_handler.Instance = GTIM_TIMX_PWM;
    g_timx_pwm_handler.Init.Period = arr;
    g_timx_pwm_handler.Init.Prescaler = psc;
    g_timx_pwm_handler.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&g_timx_pwm_handler);

    TIM_OC_InitTypeDef oc_init;
    oc_init.OCMode = TIM_OCMODE_PWM1; 
    oc_init.OCPolarity = TIM_OCPOLARITY_LOW;
    oc_init.Pulse = arr / 2;
    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm_handler, &oc_init, GTIM_TIMX_PWM_CHY);

    HAL_TIM_PWM_Start(&g_timx_pwm_handler, GTIM_TIMX_PWM_CHY);
}
