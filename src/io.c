#include <avr/io.h>
#include <stdint.h>

uint8_t read_bit(uint8_t byte, uint8_t idx) { return ((byte >> idx) & 1); }
uint8_t set_bit(uint8_t byte, uint8_t idx) { return byte | (1 << idx); }
uint8_t clear_bit(uint8_t byte, uint8_t idx) { return byte & ~(1 << idx); }
