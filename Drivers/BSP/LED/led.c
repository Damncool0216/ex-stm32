#include "./BSP/LED/led.h"

void led_init(void)
{

    GPIO_InitTypeDef gpio_init_struct; /* GPIO初始化参数结构体 */

    LED0_GPIO_CLK_ENABLE(); /* 使能LED0时钟 */
    LED1_GPIO_CLK_ENABLE(); /* 使能LED1时钟*/

    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP; /* 推挽输出模式 */
    gpio_init_struct.Pin = LED0_GPIO_PIN; /* LED0引脚 */
    gpio_init_struct.Pull = GPIO_PULLUP; /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH; /* 高速输出 */
    HAL_GPIO_Init(LED0_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED1_GPIO_PIN; /* LED1引脚 */
    HAL_GPIO_Init(LED1_GPIO_PORT, &gpio_init_struct);

    /* LED初始熄灭 */
    LED0(1);
    LED1(1);
}