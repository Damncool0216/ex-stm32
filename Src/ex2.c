#include "ex2.h"

/* 实验2 蜂鸣器 */
void run()
{
    led_init();
    beep_init();
    while (1) {
        LED0(0);
        BEEP(0);
        delay_ms(300);
        LED0(1);
        BEEP(1);
        delay_ms(300);
    }
}