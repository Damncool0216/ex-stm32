#include "ex4.h"
/* 实验4 外部中断 */
void run(void) 
{
    led_init();
    beep_init();
    key_init();
    exti_init();
    while(1) {
    }
}