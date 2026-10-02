#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H

#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    uint16_t size;
    volatile uint16_t head;
    volatile uint16_t tail;
} RingBuffer_t;

void RingBuffer_Init(RingBuffer_t *ringBuffer, uint8_t *buffer, uint16_t size);
uint8_t RingBuffer_Put(RingBuffer_t *ringBuffer, uint8_t data);
uint8_t RingBuffer_Get(RingBuffer_t *ringBuffer, uint8_t *data);
uint16_t RingBuffer_Available(RingBuffer_t *ringBuffer);

#endif
