#include "bsp_uart.h"
#include "ring_buffer.h"
#include "usart.h"
#include <string.h>

extern UART_HandleTypeDef huart1;

static RingBuffer_t uart_rb;
static uint8_t uart_rx_buffer[UART_RX_BUFFER_SIZE];
static uint8_t rx_byte; // 单字节接收缓存

/**
 * @brief 串口初始化，启动第一次接收中断
 */
void Bsp_Uart_Init(void)
{
    RingBuffer_Init(&uart_rb, uart_rx_buffer, UART_RX_BUFFER_SIZE);
    HAL_UART_Receive_IT(&huart1, &rx_byte, 1); // 启动第一次接收中断
}

/**
 * @brief 串口接收中断回调函数
 * @param huart UART句柄
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) {
        RingBuffer_Put(&uart_rb, rx_byte); // 将接收到的字节放入环形缓冲区
        HAL_UART_Receive_IT(&huart1, &rx_byte, 1); // 重新启动接收中断
    }
}

/**
 * @brief 串口错误回调函数,发生错误时重新启用接收
 * @param huart UART句柄
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) {
        // 重新启动接收中断
        HAL_UART_Receive_IT(&huart1, &rx_byte, 1);
    }
}

/**
 * @brief 返回缓冲区中可读字节数
 * @return uint16_t 
 */
uint16_t Bsp_Uart_Available(void)
{
    return RingBuffer_Available(&uart_rb);
}

/**
 * @brief 从缓冲区读一个字节，空则返回 0
 * @return uint8_t 
 */
uint8_t Bsp_Uart_ReadChar(void)
{
    uint8_t data = 0;
    RingBuffer_Get(&uart_rb, &data);
    return data;
}

/**
 * @brief 发送字符串，用于回复 OK/ERR/STATE 等指令
 * @param str 
 */
void Bsp_Uart_SendString(const char *str)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen(str), 100);
}
