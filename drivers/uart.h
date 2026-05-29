#include <stdint.h>
#include <stdbool.h>
#include "ring_buffer.h"
static RingBuffer rx_buffer;
void uart_rx_handler(uint8_t data);
void uart_init();
bool uart_available();
bool uart_read_byte(uint8_t *data);
bool uart_write_byte(uint8_t data);