#include "ex3.h"

/*实验3 独立按键 */
void run()
{
    uint8_t key;
    led_init();
    beep_init();
    key_init();
    LED0(0);

    while (1) {
        key = key_scan(0);
        if (key) {
            switch (key) {
            case WKUP_PRES:
                BEEP_TOGGLE();
                break;
            case KEY1_PRES:
                LED1_TOGGLE();
                break;
            case KEY0_PRES:
                LED0_TOGGLE();
                LED1_TOGGLE();
            }
        }
    }
}