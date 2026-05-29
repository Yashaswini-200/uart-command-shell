#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <avr/io.h>
#include "ring_buffer.h"
static RingBuffer rx_buffer;
void uart_rx_handler(uint8_t data){
    rb_push(&rx_buffer,data);
}
void uart_init(){
    rb_init(&rx_buffer);
    UBRR0 = 103;
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1<< RXCIE0) ;
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
bool uart_available(){
    return !rb_empty(&rx_buffer);
}
bool uart_read_byte(uint8_t *data){
    return rb_pop(&rx_buffer,&data);
}
bool uart_write_byte(uint8_t data){
   while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
    return true;
}
