#include "ex8.h"

/* 实验8 基本定时器中断实验 */
void run()
{
    led_init();
    btim_timx_int_init(5000-1, 7200-1);
    while(1) {
        LED0_TOGGLE();
        delay_ms(200);
    }
}