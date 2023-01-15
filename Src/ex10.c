#include "ex10.h"

void run()
{
    uint16_t pwm_val = 0;
    uint8_t dir = 1;
    gtim_timx_pwm_init(500 - 1, 72 - 1);
    while(1) {
        delay_ms(10);
        if (dir == 1) {
            pwm_val++;
        } else {
            pwm_val--;
        }
        if (pwm_val > 300) dir = 0;
        if (pwm_val == 0) dir = 1;
        __HAL_TIM_SET_COMPARE(&g_timx_pwm_handler, GTIM_TIMX_PWM_CHY, pwm_val);
    }
}