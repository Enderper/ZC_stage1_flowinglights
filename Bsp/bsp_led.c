#include "bsp_led.h"

const LedPin_t led_pins[LED_NUM] = {
    {GPIOC, LED1_Pin},
    {GPIOC, LED2_Pin},
    {GPIOC, LED3_Pin},
    {GPIOA, LED4_Pin},
    {GPIOA, LED5_Pin},
    {GPIOA, LED6_Pin},
    {GPIOA, LED7_Pin},
    {GPIOA, LED8_Pin},
    {GPIOA, LED9_Pin},
    {GPIOA, LED10_Pin},
    {GPIOA, LED11_Pin},
    {GPIOB, LED12_Pin},
    {GPIOB, LED13_Pin},
    {GPIOB, LED14_Pin},
    {GPIOB, LED15_Pin},
    {GPIOB, LED16_Pin},
    {GPIOB, LED17_Pin},
    {GPIOB, LED18_Pin},
    {GPIOB, LED19_Pin},
    {GPIOB, LED20_Pin},
    {GPIOB, LED21_Pin},
    {GPIOB, LED22_Pin},
    {GPIOA, LED23_Pin},
    {GPIOA, LED24_Pin},
    {GPIOA, LED25_Pin},
    {GPIOA, LED26_Pin},
    {GPIOB, LED27_Pin},
    {GPIOB, LED28_Pin},
    {GPIOB, LED29_Pin},
    {GPIOB, LED30_Pin}
};

/**
 * @brief  初始化LED引脚,cubemx已生成，留空
 * @retval None
 */
void LED_Init(void) 
{
    return;
}

/**
 * @brief  点亮指定LED
 * @param  led_index: LED索引，与label一致
 * @retval None
 */
void Bsp_Led_On(uint8_t led_index)
{
    if (led_index >= LED_NUM) {
        return; // 索引超出范围，直接返回
    }
    HAL_GPIO_WritePin(led_pins[led_index-1].port, led_pins[led_index-1].pin, GPIO_PIN_RESET);
}

/**
 * @brief  熄灭指定LED
 * @param  led_index: LED索引，与label一致
 * @retval None
 */
void Bsp_Led_Off(uint8_t led_index)
{
    if (led_index >= LED_NUM) {
        return; // 索引超出范围，直接返回
    }
    HAL_GPIO_WritePin(led_pins[led_index-1].port, led_pins[led_index-1].pin, GPIO_PIN_SET);
}

/**
 * @brief  熄灭所有LED
 * @retval None
 */
void Bsp_Led_AllOff(void)
{
    for (uint8_t i = 0; i < LED_NUM; i++) {
        HAL_GPIO_WritePin(led_pins[i].port, led_pins[i].pin, GPIO_PIN_SET);
    }
}

/**
 * @brief  根据掩码设置LED状态
 * @param  mask: LED掩码
 * @retval None
 * @note   LED的点亮熄灭可以直接操作寄存器，更快
 */
void Bsp_Led_SetMask(uint32_t mask)
{
    for (uint8_t i = 0; i < LED_NUM; i++) {
        if (mask & (1UL << i)) { //检查掩码的第i位是否为 1，如果是则点亮第i个LED
            // 低电平点亮
            HAL_GPIO_WritePin(led_pins[i].port, led_pins[i].pin, GPIO_PIN_RESET);
        } else {
            // 高电平熄灭
            HAL_GPIO_WritePin(led_pins[i].port, led_pins[i].pin, GPIO_PIN_SET);
        }
    }
}
