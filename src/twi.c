// #include "twi.h"

// void TWI_init(void) {
//     //set SCL to 400kHz
//     TWSR = 0x00;
//     TWBR = 0x0C;
//     //enable TWI
//     TWCR = (1<<TWEN);
// }

// void TWI_start(void) {
//     TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
//     while ((TWCR & (1<<TWINT)) == 0);
// }

// uint8_t TWI_read_ACK(void) {
//     TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
//     while ((TWCR & (1<<TWINT)) == 0);
//     return TWDR;
// }
// //read byte with NACK
// uint8_t TWI_read_NACK(void) {
//     TWCR = (1<<TWINT)|(1<<TWEN);
//     while ((TWCR & (1<<TWINT)) == 0);
//     return TWDR;
// }

// void TWI_write(uint8_t data) {
//     TWDR = data;
//     TWCR = (1<<TWINT)|(1<<TWEN);
//     while ((TWCR & (1<<TWINT)) == 0);
// }

// void TWI_stop(void) {
//     TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
// }

// uint8_t TWI_get_status(void) {
//     uint8_t status;
//     //mask status
//     status = TWSR & 0xF8;
//     return status;
// }