#include "ring_buffer.h"

/**
 * @brief 初始化循环缓冲区
 * @param rb 循环缓冲区的结构体指针
 * @param buffer 环形缓冲区的存储数组首地址
 * @param size 存储数组的大小
 */
void RingBuffer_Init(RingBuffer_t *rb, uint8_t *buffer, uint16_t size)
{
    rb->buffer = buffer;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
}

/**
 * @brief 将数据放入循环缓冲区中
 * @param rb 循环缓冲区的结构体指针
 * @param data 要放入缓冲区的数据
 * @return 成功返回 1， 缓冲区满失败返回 0 
 */
uint8_t RingBuffer_Put(RingBuffer_t *rb, uint8_t data)
{
    uint16_t next = (rb->head + 1) % rb->size;//若将数据写入，head接下来要到达的位置(next)
    if (next == rb->tail) {
        return 0;   //head的下一个位置等于tail，说明要满了，丢弃该字节
    }
    rb->buffer[rb->head] = data;//未满就将数据写入到head的当前位置
    rb->head = next;//后将head移动到next位置
    return 1;
}

/**
 * @brief 从循环缓冲区中取得数据
 * @param rb 循环缓冲区的结构体指针
 * @param data Pointer to store the retrieved data
 * @return 成功返回 1， 缓冲区满失败返回 0
 */
uint8_t RingBuffer_Get(RingBuffer_t *rb, uint8_t *data)
{
    if (rb->head == rb->tail) {
        return 0;   // 空
    }
    *data = rb->buffer[rb->tail];//若非空，读取tail位置的数据
    rb->tail = (rb->tail + 1) % rb->size;//读完后将tail移动到下一个位置
    return 1;
}

/**
 * @brief 检查循环缓冲区中的可用空间
 * @param rb 循环缓冲区的结构体指针
 * @return 循环缓冲区中可用字节数(tail到head之间的字节数)
 */
uint16_t RingBuffer_Available(RingBuffer_t *rb)
{
    return (rb->head - rb->tail + rb->size) % rb->size;
}