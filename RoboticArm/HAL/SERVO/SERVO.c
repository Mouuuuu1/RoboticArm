#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SERVO.h"

void SERVO_voidInit(void) {
    // Configure PB0–PB5 as output for 6 servos
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_OUTPUT); // Servo 0
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_OUTPUT); // Servo 1
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_OUTPUT); // Servo 2
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT); // Servo 3
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_OUTPUT); // Servo 4
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN5, DIO_u8_OUTPUT); // Servo 5
}

void SERVO_SetAngle(u8 servo_id, u16 angle) {
    if (angle > 180) angle = 180;

    // Map angle (0–180) to pulse width (1000–2000us)
    u16 pulse_us = 1000 + ((u32)angle * 1000) / 180;

    u8 port = DIO_u8_PORTB;
    u8 pin;

    switch (servo_id) {
        case 0: pin = DIO_u8_PIN0; break;
        case 1: pin = DIO_u8_PIN1; break;
        case 2: pin = DIO_u8_PIN2; break;
        case 3: pin = DIO_u8_PIN3; break;
        case 4: pin = DIO_u8_PIN4; break;
        case 5: pin = DIO_u8_PIN5; break;
        default: return; // Invalid ID
    }

    // Send repeated pulses for 1 second (~50Hz)
    for (u8 i = 0; i < 50; i++) {
        DIO_voidSetPinValue(port, pin, DIO_u8_HIGH);
        _delay_us(pulse_us);          // Pulse duration for angle
        DIO_voidSetPinValue(port, pin, DIO_u8_LOW);
        _delay_ms(18);                // Remaining time for 20ms frame
    }
}
