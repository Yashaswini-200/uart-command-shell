#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#define RING_BUFFER_SIZE 128U
typedef struct{
    uint8_t buffer[RING_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
} RingBuffer;
void rb_init(RingBuffer *rb);
bool rb_empty(RingBuffer *rb);
bool rb_full(RingBuffer *rb);
bool rb_push(RingBuffer *rb, uint8_t data);
bool rb_pop(RingBuffer *rb , uint8_t *data);