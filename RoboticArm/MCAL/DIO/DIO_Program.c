#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_math.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"

void DIO_voidInit(void)
{
    // === PORTA: Not used, set as INPUT ===
//    DIO_voidSetPortDirection(DIO_u8_PORTA, DIO_u8_INPUT);
  //  DIO_voidSetPortValue(DIO_u8_PORTA, DIO_u8_LOW); // Optional

    // === PORTB: Servo Outputs (PB0–PB5) ===
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN5, DIO_u8_OUTPUT);

    // === PORTC: KEYPAD ===
    // Rows (PC0–PC3): INPUT with pull-up
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_INPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_INPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_INPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN3, DIO_u8_INPUT);

    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_HIGH);
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH);
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN3, DIO_u8_HIGH);

    // Cols (PC4–PC7): OUTPUT
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN4, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN5, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN7, DIO_u8_OUTPUT);

    // === PORTD: LCD in 4-bit mode (PD0–PD5 used) ===
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_OUTPUT); // RS
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN1, DIO_u8_OUTPUT); // E
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_OUTPUT); // D4
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_OUTPUT); // D5
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN4, DIO_u8_OUTPUT); // D6
    DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN5, DIO_u8_OUTPUT); // D7
}

void DIO_voidSetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
	if(u8PinValCopy)
	{
		switch(u8PortIdCopy)
		{
		case DIO_u8_PORTA:SET_BIT(PORTA,u8PinIdCopy);break;
		case DIO_u8_PORTB:SET_BIT(PORTB,u8PinIdCopy);break;
		case DIO_u8_PORTC:SET_BIT(PORTC,u8PinIdCopy);break;
		case DIO_u8_PORTD:SET_BIT(PORTD,u8PinIdCopy);break;
		}
	}
	else{
		switch(u8PortIdCopy)
		{
		case DIO_u8_PORTA:CLR_BIT(PORTA,u8PinIdCopy);break;
		case DIO_u8_PORTB:CLR_BIT(PORTB,u8PinIdCopy);break;
		case DIO_u8_PORTC:CLR_BIT(PORTC,u8PinIdCopy);break;
		case DIO_u8_PORTD:CLR_BIT(PORTD,u8PinIdCopy);break;
		}


	}

}

u8 DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	u8 pin_value=0;
	switch(u8PortIdCopy)
	{
	case DIO_u8_PORTA :pin_value=GET_BIT(PINA,u8PinIdCopy);
	return pin_value;break;
	case DIO_u8_PORTB:pin_value=GET_BIT(PINB,u8PinIdCopy);
	return pin_value;break;
	case DIO_u8_PORTC:pin_value=GET_BIT(PINC,u8PinIdCopy);
	return pin_value;break;
	case DIO_u8_PORTD:pin_value=GET_BIT(PIND,u8PinIdCopy);
	return pin_value;break;
	}

}

void DIO_voidSetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	if(u8PinDirCopy){
		switch(u8PortIdCopy)
		{
		case DIO_u8_PORTA:SET_BIT(DDRA,u8PinIdCopy);break;
		case DIO_u8_PORTB:SET_BIT(DDRB,u8PinIdCopy);break;
		case DIO_u8_PORTC:SET_BIT(DDRC,u8PinIdCopy);break;
		case DIO_u8_PORTD:SET_BIT(DDRD,u8PinIdCopy);break;
		}
	}
	else {
		switch(u8PortIdCopy)
		{
		case DIO_u8_PORTA:CLR_BIT(DDRA,u8PinIdCopy);break;
		case DIO_u8_PORTB:CLR_BIT(DDRB,u8PinIdCopy);break;
		case DIO_u8_PORTC:CLR_BIT(DDRC,u8PinIdCopy);break;
		case DIO_u8_PORTD:CLR_BIT(DDRD,u8PinIdCopy);break;
		}
	}

}
/* IO Ports */
void DIO_voidSetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	switch(u8PortId)
	{
	case  DIO_u8_PORTA: DDRA=u8PortDir; break;
	case  DIO_u8_PORTB: DDRB=u8PortDir; break;
	case  DIO_u8_PORTC: DDRC=u8PortDir; break;
	case  DIO_u8_PORTD: DDRD=u8PortDir; break;

	}

}

void DIO_voidSetPortValue (u8 u8PortId, u8 u8PortVal)
{
	switch(u8PortId)
	{
	case  DIO_u8_PORTA: PORTA=u8PortVal; break;
	case  DIO_u8_PORTB: PORTB=u8PortVal; break;
	case  DIO_u8_PORTC: PORTC=u8PortVal; break;
	case  DIO_u8_PORTD: PORTD=u8PortVal; break;

	}
}

void DIO_voidTogglePinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
 switch(u8PortIdCopy)
  {
    case DIO_u8_PORTA :TOG_BIT(PORTA,u8PinIdCopy);break;
    case DIO_u8_PORTB :TOG_BIT(PORTB,u8PinIdCopy);break;
    case DIO_u8_PORTC :TOG_BIT(PORTC,u8PinIdCopy);break;
    case DIO_u8_PORTD :TOG_BIT(PORTD,u8PinIdCopy);break;
 }

}


