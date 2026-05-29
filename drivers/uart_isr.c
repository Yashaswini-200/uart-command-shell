#include <stdint.h>
#include "ring_buffer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
ISR(USART_RX_vect){
  uint8_t data=UDR0;
  uart_rx_handler(data);
}