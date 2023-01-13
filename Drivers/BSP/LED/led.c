#include "./BSP/LED/led.h"

void led_init(void)
{

    GPIO_InitTypeDef gpio_init_struct; /* GPIO��ʼ�������ṹ�� */

    LED0_GPIO_CLK_ENABLE(); /* ʹ��LED0ʱ�� */
    LED1_GPIO_CLK_ENABLE(); /* ʹ��LED1ʱ��*/

    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP; /* �������ģʽ */
    gpio_init_struct.Pin = LED0_GPIO_PIN; /* LED0���� */
    gpio_init_struct.Pull = GPIO_PULLUP; /* ���� */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH; /* ������� */
    HAL_GPIO_Init(LED0_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED1_GPIO_PIN; /* LED1���� */
    HAL_GPIO_Init(LED1_GPIO_PORT, &gpio_init_struct);

    /* LED��ʼϨ�� */
    LED0(1);
    LED1(1);
}