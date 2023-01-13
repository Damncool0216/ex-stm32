#include "ex6.h"
/* 实验6 独立看门狗 */
void run()
{
    usart_init(115200);
    iwdg_init(IWDG_PRESCALER_32, 1250);
    printf("please feed the dog\r\n");
    while(1) {
        delay_ms(1050);
        iwdg_feed();
        printf("have fed the dog\r\n");
    }
}