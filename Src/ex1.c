#include "ex1.h"

/* 实验1 跑马灯 */
void run()
{
    led_init();
    while (1) {
        LED0(0);
        LED1(1);
        delay_ms(500);
        LED0(1);
        LED1(0);
        delay_ms(500);
    }
}
