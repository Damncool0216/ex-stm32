#include "ex7.h"


/* 实验7 窗口看门狗 */
void run()
{
    usart_init(115200);
    led_init();
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET) {
        printf("wwdg reset\r\n");
        __HAL_RCC_CLEAR_RESET_FLAGS();
    } else {
        printf("other reset\r\n");
    }
    delay_ms(500);
    wwdg_init(0x7f, 0x5f, WWDG_PRESCALER_8, WWDG_EWI_DISABLE);
    while(1) {
        delay_ms(32);
        HAL_WWDG_Refresh(&g_wwdg_handle);
    }
}