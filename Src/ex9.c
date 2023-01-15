#include "ex9.h"

/* 实验9 通用定时器中断实验 */
void run()
{
    led_init();
    gtim_timx_int_init(5000-1, 7200-1);
    while(1) {
        LED0_TOGGLE();
        delay_ms(200);
    }
}