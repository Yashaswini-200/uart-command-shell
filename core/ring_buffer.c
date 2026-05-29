#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#define RING_BUFFER_SIZE 128U

typedef struct{
    uint8_t buffer[RING_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
} RingBuffer;

void rb_init(RingBuffer *rb){
    rb->head=0;
    rb->tail=0;
}
bool rb_empty(RingBuffer *rb){
    return rb->head==rb->tail;
}
bool rb_full(RingBuffer *rb){
    return (rb->head+1)&(RING_BUFFER_SIZE-1)==rb->tail;
}
bool rb_push(RingBuffer *rb, uint8_t data){
    if(rb_full(rb)){
        return false;
    }
    rb->buffer[rb->head]=data;
    rb->head=(rb->head+1)&(RING_BUFFER_SIZE-1);
    return true;
}
bool rb_pop(RingBuffer *rb , uint8_t *data){
    if(rb_empty(rb)){
        return false;
    }
    data=rb->buffer[rb->tail];
    rb->tail=(rb->tail+1)&(RING_BUFFER_SIZE-1);
    return true;
}