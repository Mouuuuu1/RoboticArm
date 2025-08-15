#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void EEPROM_voidWriteByte(u16 address, u8 data);
u8 EEPROM_u8ReadByte(u16 address);
void EEPROM_voidWriteBlock(u16 startAddr, u8 *data, u8 length);
void EEPROM_voidReadBlock(u16 startAddr, u8 *data, u8 length);

#endif
