#include "ex5.h"

void run(void)
{
    uint8_t len;
    uint16_t times = 0;

    usart_init(115200);
    led_init();
    printf("please input data(End with <CR>)\r\n");
    while (1) {
        if (g_usart_rx_sta & 0x8000) {
            len = g_usart_rx_sta & 0x3FFF;
            printf("\r\n receive message:\r\n");
            HAL_UART_Transmit(&g_uart1_handle, g_usart_rx_buf, len, 1000);
            while (__HAL_UART_GET_FLAG(&g_uart1_handle, UART_FLAG_TC) != SET)
                ;
            printf("\r\n\r\n"); /* 插入换行 */
            g_usart_rx_sta = 0;
        } else {
            times++;
            if (times % 5000 == 0) {
                printf("\r\n Stm32xixixix\r\n");
            }
            if (times % 1000 == 0)
                printf("please input data(End with <CR>)\r\n");
            if (times % 30 == 0)
                LED0_TOGGLE(); /* 闪烁 LED,提示系统正在运行. */
            delay_ms(10);
        }
    }
}