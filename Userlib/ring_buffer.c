#include "ring_buffer.h"

/**
 * @brief 初始化循环缓冲区
 * @param ringBuffer 循环缓冲区的结构体指针
 * @param buffer Pointer to the buffer array
 * @param size Size of the buffer array
 */
void RingBuffer_Init(RingBuffer_t *ringBuffer, uint8_t *buffer, uint16_t size)
{
    ringBuffer->buffer = buffer;
    ringBuffer->size = size;
    ringBuffer->head = 0;
    ringBuffer->tail = 0;
}

/**
 * @brief 将数据放入循环缓冲区中
 * @param ringBuffer 循环缓冲区的结构体指针
 * @param data Data to be put into the ring buffer
 * @return 1 if data is successfully put, 0 otherwise
 */
uint8_t RingBuffer_Put(RingBuffer_t *ringBuffer, uint8_t data)
{
    // Implementation for putting data into the ring buffer
    return 0;
}

/**
 * @brief 从循环缓冲区中取得数据
 * @param ringBuffer 循环缓冲区的结构体指针
 * @param data Pointer to store the retrieved data
 * @return 1 if data is successfully retrieved, 0 otherwise
 */
uint8_t RingBuffer_Get(RingBuffer_t *ringBuffer, uint8_t *data)
{
    // Implementation for getting data from the ring buffer
    return 0;
}

/**
 * @brief 检查循环缓冲区中的可用空间
 * @param ringBuffer 循环缓冲区的结构体指针
 * @return 循环缓冲区中可用字节数
 */
uint16_t RingBuffer_Available(RingBuffer_t *ringBuffer)
{
    // Implementation for checking available space in the ring buffer
    return 0;
}