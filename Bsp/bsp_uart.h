#ifndef __BSP_UART_H
#define __BSP_UART_H

#include <stdint.h>

// 串口接收缓存大小，字节
#define UART_RX_BUFFER_SIZE 64

void Bsp_Uart_Init(void);
uint16_t Bsp_Uart_Available(void);
uint8_t Bsp_Uart_ReadChar(void);
void Bsp_Uart_SendString(const char *str);

#endif
