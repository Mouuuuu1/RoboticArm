#ifndef  DIO_INTERFACE_H
#define  DIO_INTERFACE_H

///Protypes_Functions
#include "DIO_Register.h"
/* Port Defines */
#define DIO_u8_PORTA    0
#define DIO_u8_PORTB    1
#define DIO_u8_PORTC    2
#define DIO_u8_PORTD    3

/* PIN Defines */
#define DIO_u8_PIN0   0
#define DIO_u8_PIN1   1
#define DIO_u8_PIN2   2
#define DIO_u8_PIN3   3
#define DIO_u8_PIN4   4
#define DIO_u8_PIN5   5
#define DIO_u8_PIN6   6
#define DIO_u8_PIN7   7

/* PIN Directions */
#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1

#define DIO_u8_HIGH   1
#define DIO_u8_LOW    0

#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1

void DIO_voidSetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);
u8 DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);
void DIO_voidSetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* IO Ports */
void DIO_voidSetPortDirection(u8 u8PortId, u8 u8PortDir);
void DIO_voidSetPortValue(u8 u8PortId, u8 u8PortVal);
void DIO_voidTogglePinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);


#endif



