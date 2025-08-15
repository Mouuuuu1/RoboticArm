#include "../../LIB/STD_TYPES.h"
#include <avr/io.h>

void I2C_voidStart(void) {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_voidStop(void) {
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
}

void I2C_voidSendByte(u8 data) {
    TWDR = data;
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
}

u8 I2C_u8ReceiveByteWithNACK(void) {
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

void I2C_voidRepeatedStart(void) {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_voidSendSlaveAddressWithWrite(u8 address) {
    I2C_voidSendByte(address & ~1);  // LSB = 0 for write
}

void I2C_voidSendSlaveAddressWithRead(u8 address) {
    I2C_voidSendByte(address | 1);   // LSB = 1 for read
}
