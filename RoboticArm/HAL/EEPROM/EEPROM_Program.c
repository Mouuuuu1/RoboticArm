#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/I2C/I2C_Interface.h"
#include "EEPROM_Interface.h"

#define EEPROM_ADDRESS 0xA0  // Base address for 24Cxx EEPROM

void EEPROM_voidWriteByte(u16 address, u8 data) {
    I2C_voidStart();
    I2C_voidSendSlaveAddressWithWrite(EEPROM_ADDRESS | ((address & 0x0700) >> 7));
    I2C_voidSendByte((u8)address);  // Send lower 8 bits of address
    I2C_voidSendByte(data);         // Send the data byte
    I2C_voidStop();
    _delay_ms(10); // EEPROM write delay
}

u8 EEPROM_u8ReadByte(u16 address) {
    u8 data;

    I2C_voidStart();
    I2C_voidSendSlaveAddressWithWrite(EEPROM_ADDRESS | ((address & 0x0700) >> 7));
    I2C_voidSendByte((u8)address);  // Send lower 8 bits of address

    I2C_voidRepeatedStart();
    I2C_voidSendSlaveAddressWithRead(EEPROM_ADDRESS | ((address & 0x0700) >> 7));
    data = I2C_u8ReceiveByteWithNACK();
    I2C_voidStop();

    return data;
}

void EEPROM_voidWriteBlock(u16 startAddr, u8 *data, u8 length) {
    for (u8 i = 0; i < length; i++) {
        EEPROM_voidWriteByte(startAddr + i, data[i]);
        _delay_ms(10); // Wait for internal write cycle
    }
}

void EEPROM_voidReadBlock(u16 startAddr, u8 *data, u8 length) {
    for (u8 i = 0; i < length; i++) {
        data[i] = EEPROM_u8ReadByte(startAddr + i);
    }
}
