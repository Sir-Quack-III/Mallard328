#include <string.h>
#include <avr/eeprom.h>
#include "term.h"

void term_init(void) {
    UART_init(103);
    UART_clear();
    UART_print("UART initialized\r\n");
    UART_clear();
    UART_print("Welcome to Mallard328!\r\n");
}

void term_run(void) {
    while (1) {
        char command[0xFF];

        UART_print("> ");
        UART_scans(&command, 0xFF);

        char* com_split;
        com_split = strtok(command, " ");

        if (strcmp(command, "quit\r") == 0) {
            UART_print("Goodbye!\r\n");
            break;
        } else if (strcmp(command, "clr\r") == 0) {
            UART_clear();
            continue;
        } else if (strcmp(com_split, "echo") == 0) {
            com_split = strtok(NULL, " ");
            UART_print(com_split);
            UART_print("\r\n");
            continue;
        } else if (strcmp(com_split, "write") == 0) {
            // write to eeprom
            eeprom_busy_wait();

            char* addr_str;
            char* data_str;

            com_split = strtok(NULL, " ");
            uint8_t addr = atoi(com_split);
            com_split = strtok(NULL, " ");
            uint8_t data = atoi(com_split);
            eeprom_write_byte((uint8_t*)addr, data);
            UART_print("Wrote 0x");
            UART_print(itoa(data, data_str, 16));
            UART_print(" to 0x");
            UART_print(itoa(addr, addr_str, 16));
            UART_print("\r\n");
            continue;
        } else if (strcmp(com_split, "read") == 0) {
            // read from eeprom

            eeprom_busy_wait();

            com_split = strtok(NULL, " ");
            UART_print(com_split);
            UART_print("\r\n");
            char* data_str;
            uint8_t addr = atoi(com_split);
            uint8_t data = eeprom_read_byte((uint8_t*)addr);
            UART_print("0x");
            UART_print(itoa(data, data_str, 16));
            UART_print("\r\n");
            continue;
        }
        // else if (strcmp(com_split), "clear") == 0) {
        //     // clear eeprom

        //     eeprom_busy_wait();

        //     eeprom_write_byte((uint8_t*)0, 0);
        //     UART_print("Cleared EEPROM\r\n");
        //     continue;
        // }

        UART_print(command);
        UART_print("\r\n");
    }

    return;
}