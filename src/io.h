#include <avr/io.h>
#include <stdint.h>

uint8_t read_bit(uint8_t byte, uint8_t idx);
uint8_t set_bit(uint8_t byte, uint8_t idx);
uint8_t clear_bit(uint8_t byte, uint8_t idx);

void dwrite(uint8_t pin, uint8_t val)