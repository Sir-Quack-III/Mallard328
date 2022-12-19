#include <stdint.h>

void UART_init(uint16_t ubrr);
void UART_putc(unsigned char data);

void UART_clear(void);
void UART_print(char* s);
void UART_printu8(uint8_t val);

void UART_scanc(uint8_t* c);
void UART_scans(char* buf, uint8_t n);