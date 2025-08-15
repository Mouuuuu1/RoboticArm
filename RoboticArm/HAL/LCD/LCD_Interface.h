#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidWriteString(const char *str);
void LCD_voidSetCursor(u8 row, u8 col);
void LCD_voidClear(void);
void LCD_voidWriteNumber(s32 num);

#endif
