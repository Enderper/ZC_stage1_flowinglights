#include "cmd_parser.h"
#include "bsp_uart.h"
#include "app_state.h"
#include "bsp_led.h"
#include "bsp_soft_pwm.h"
#include "effect.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char     cmd_buf[CMD_BUF_SIZE];
static uint16_t cmd_index;
static uint8_t  cmd_overflow;   // 1=当前命令过长，丢弃直到\r\n

static void CmdParser_Execute(const char *cmd);

/**
 * @brief 初始化串口命令处理
 * 
 */
void CmdParser_Init(void)
{
    cmd_index = 0;
    cmd_overflow = 0;
    memset(cmd_buf, 0, sizeof(cmd_buf));
}

/**
 * @brief 串口命令进程
 * 
 */
void CmdParser_Process(void)
{
    while (Bsp_Uart_Available() > 0)
    {
        uint8_t ch = Bsp_Uart_ReadChar();

        // 遇到'\r'或'\n'表示一条命令结束
        if (ch == '\r' || ch == '\n')
        {
            if (cmd_index > 0 && !cmd_overflow)
            {
                cmd_buf[cmd_index] = '\0';  // 添加字符串结束符
                CmdParser_Execute(cmd_buf); // 解析并执行
            }

            // 无论命令是否有效，都清空
            cmd_index = 0;
            cmd_overflow = 0;
            continue;
        }

        // 遇到普通字符，存入缓存区
        if (cmd_overflow)
        {
            continue; // 当前命令过长，丢弃字符
        }

        if (cmd_index < CMD_BUF_SIZE - 1)
        {
            cmd_buf[cmd_index++] = (char)ch;
        }
        else
        {
            cmd_overflow = 1; // 缓存区已满，标记溢出
        }

    }
}

/**
 * @brief 解析并执行命令
 * 
 */
static void CmdParser_Execute(const char *cmd)
{
    // RUN:启动基础流水，从LED1开始
    if (strcmp(cmd, "RUN") == 0)
    {
        g_app_state.run_state = 1;
        Effect_Reset(); // 从LED1重新开始
        Bsp_Uart_SendString("OK\r\n");
        return;
    }

    // STOP：停止并熄灭全部LED
    if (strcmp(cmd, "STOP") == 0)
    {
        g_app_state.run_state = 0;
        Bsp_SoftPwm_SetMask(0); // 掩码清零
        Bsp_Led_AllOff(); // 关闭所有LED
        Bsp_Uart_SendString("OK\r\n");
        return;
    }

    // GET：查询当前运行状态
    if (strcmp(cmd, "GET") == 0)
    {
        char response[32];
        snprintf(response, sizeof(response), "STATE,RUN=%d,BRI=%d,MODE=%d\r\n",
                 g_app_state.run_state,
                 g_app_state.brightness,
                 g_app_state.mode);
        Bsp_Uart_SendString(response);
        return;
    }

    // BRI,n:设置统一亮度，n=0～100
    if (strncmp(cmd, "BRI,", 4) == 0)
    {
        int n;
        char extra;

        // 恰好有一个整数，其后不能再有字符
        if (sscanf(cmd + 4, "%d%c", &n, &extra) != 1)
        {
            Bsp_Uart_SendString("ERR\r\n");
            return;
        }

        if (n < 0 || n > 100)
        {
            Bsp_Uart_SendString("ERR\r\n");
            return;
        }

        g_app_state.brightness = (uint8_t)n;
        Bsp_SoftPwm_SetBrightness((uint8_t)n);
        Bsp_Uart_SendString("OK\r\n");
        return;
    }

    // MODE,n:选择基础/加分模式
    if (strncmp(cmd, "MODE,", 5) == 0)
    {
        int n;
        char extra;

        if (sscanf(cmd + 5, "%d%c", &n, &extra) != 1)
        {
            Bsp_Uart_SendString("ERR\r\n");
            return;
        }

        // 假设已实现模式 0~5，超出范围返回 ERR
        if (n < 0)
        {
            Bsp_Uart_SendString("ERR\r\n");
            return;
        }

        if (Effect_SetMode((uint8_t)n) != 0)
        {
            Bsp_Uart_SendString("ERR\r\n");
            return;
        }

        Bsp_Uart_SendString("OK\r\n");
        return;
    }

    // 未知命令
    Bsp_Uart_SendString("ERR\r\n");
}
