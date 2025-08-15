#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include <stdio.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"

// Control Pins
#define LCD_RS_PORT    DIO_u8_PORTA
#define LCD_RS_PIN     DIO_u8_PIN0
#define LCD_E_PORT     DIO_u8_PORTA
#define LCD_E_PIN      DIO_u8_PIN1

// Data Port: Using PD4 to PD7
#define LCD_DATA_PORT  DIO_u8_PORTD
#define LCD_DATA_PORT_ PORTD
static void LCD_voidSend4Bits(u8 data) {
    u8 port_value = LCD_DATA_PORT_;
    port_value &= 0x0F; // clear PD4–PD7
    port_value |= (data & 0xF0); // send high nibble to PD4–PD7
    DIO_voidSetPortValue(LCD_DATA_PORT, port_value);
}

static void LCD_voidLatch(void) {
    DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_u8_LOW);
    _delay_ms(1);
}

void LCD_voidSendCommand(u8 Copy_u8Command) {

		PORTA &= ~ (1<<LCD_RS_PIN);		// RS=0, command reg.
		PORTA &= ~ (1<<1);     //RW -> 0 Writing
		LCD_DATA_PORT_ = (LCD_DATA_PORT_ & 0x0F) | (Copy_u8Command & 0xF0); // sending upper nibble

		PORTA |= (1<<LCD_E_PIN);		// Enable pulse
		_delay_us(1);
		PORTA &= ~ (1<<LCD_E_PIN);

		_delay_us(200);

		LCD_DATA_PORT_ = (LCD_DATA_PORT_ & 0x0F) | (Copy_u8Command << 4);  // sending lower nibble
		PORTA |= (1<<LCD_E_PIN);
		_delay_us(1);
		PORTA &= ~ (1<<LCD_E_PIN);
		_delay_ms(2);
}

void LCD_voidSendData( unsigned char data )
{

	PORTA |= (1<<LCD_RS_PIN);		// RS=1, data reg.
	PORTA &=~ (1<<1);
	///0X1111
	///make to store only first 4 bits
	LCD_DATA_PORT_ = (LCD_DATA_PORT_ & 0x0F) | (data & 0xF0); // sending upper nibble

	PORTA|= (1<<LCD_E_PIN);

	_delay_us(1);
	PORTA &= ~ (1<<LCD_E_PIN);

	_delay_us(200);

	LCD_DATA_PORT_ = (LCD_DATA_PORT_ & 0x0F) | (data << 4); // sending lower nibble
	PORTA |= (1<<LCD_E_PIN);
	_delay_us(1);
	PORTA &= ~ (1<<LCD_E_PIN);
	_delay_ms(2);
}

void LCD_voidInit(void) {
    _delay_ms(20);

    // Set control pins direction
    DIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(LCD_E_PORT, LCD_E_PIN, DIO_u8_OUTPUT);

    // Set data pins direction (PD4–PD7 as output)
    DIO_voidSetPortDirection(LCD_DATA_PORT, 0xF0);

    LCD_voidSendCommand(0x33);
    LCD_voidSendCommand(0x32);
    LCD_voidSendCommand(0x28);
    LCD_voidSendCommand(0x0C);
    LCD_voidSendCommand(0x06);
    LCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void LCD_voidWriteString(const char *str) {
    while (*str) {
        LCD_voidSendData(*str++);
    }
}

void LCD_voidSetCursor(u8 row, u8 col) {
    u8 address[] = {0x00, 0x40};
    if (row < 2 && col < 16) {
        LCD_voidSendCommand(0x80 | (address[row] + col));
    }
}

void LCD_voidClear(void) {
    LCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void LCD_voidWriteNumber(s32 num) {
    char buffer[11];
    sprintf(buffer, "%ld", num);
    LCD_voidWriteString(buffer);
}
