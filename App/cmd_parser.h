#ifndef __CMD_PARSER_H
#define __CMD_PARSER_H

#include <stdint.h>

#define CMD_BUF_SIZE 16 // 单条命令最大长度

void CmdParser_Init(void);
void CmdParser_Process(void);   // 主循环中非阻塞调用

#endif
