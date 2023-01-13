
#include "./BSP/WDG/wdg.h"

IWDG_HandleTypeDef g_iwdg_handle;
WWDG_HandleTypeDef g_wwdg_handle;

void iwdg_init(uint8_t prer, uint16_t rld)
{
    g_iwdg_handle.Instance = IWDG;
    g_iwdg_handle.Init.Prescaler = prer;
    g_iwdg_handle.Init.Reload = rld;
    HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed()
{
    HAL_IWDG_Refresh(&g_iwdg_handle);
}

void wwdg_init(uint8_t ctr, uint8_t wd, uint32_t prer, uint32_t mode)
{
    g_wwdg_handle.Instance = WWDG;
    g_wwdg_handle.Init.Counter = ctr;
    g_wwdg_handle.Init.Window = wd;
    g_wwdg_handle.Init.Prescaler = prer;
    g_wwdg_handle.Init.EWIMode = mode;
    HAL_WWDG_Init(&g_wwdg_handle);
}

void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();
    HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

void WWDG_IRQHandler()
{
    HAL_WWDG_IRQHandler(&g_wwdg_handle);
}


void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    HAL_WWDG_Refresh(hwwdg);
    LED0_TOGGLE();
}

