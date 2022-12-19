#include <avr/io.h>

#include "uart.h"

void UART_init(uint16_t ubrr) {
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void UART_putc(unsigned char data) {
    // wait for transmit buffer to be empty
    while(!(UCSR0A & (1 << UDRE0)));

    // load data into transmit register
    UDR0 = data;
}

void UART_print(char* s) {
    // transmit character until NULL is reached
    while(*s > 0) UART_putc(*s++);
}

void UART_clear(void) {
    UART_print("\033[2J\033[H");
}

void UART_scanc(uint8_t* c) {
    // wait for data to be received
    while(!(UCSR0A & (1 << RXC0)));

    // get and return received data from buffer
    *c = UDR0;
}

void UART_scans(char* buf, uint8_t n) {
    uint8_t bufIdx = 0;
    char c;

    // while received character is not carriage return
    // and end of buffer has not been reached
    do {
        // make backspace work
        if (c == '\b') {
            if (bufIdx > 0) {
                bufIdx--;
                UART_putc(' ');
                UART_putc('\b');
            }
            continue;
        }

        // receive character
        UART_scanc(&c);
        UART_putc(c);
        buf[bufIdx++] = c;
        // UART_putc(c);

        // // store character in buffer
        // buf[bufIdx++] = c;
    } while((bufIdx < n) && (c != '\r'));

    UART_putc('\n');

    // ensure buffer is null terminated
    buf[bufIdx] = 0;
}

void UART_printu8(uint8_t val) {
    // extract upper and lower nibbles from input value
    uint8_t upperNibble = (val & 0xF0) >> 4;
    uint8_t lowerNibble = val & 0x0F;

    // convert nibble to its ASCII hex equivalent
    upperNibble += upperNibble > 9 ? 'A' - 10 : '0';
    lowerNibble += lowerNibble > 9 ? 'A' - 10 : '0';

    // print the characters
    UART_putc(upperNibble);
    UART_putc(lowerNibble);
}