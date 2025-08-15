#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KDP_Interface.h"
#include "../HAL/SERVO/SERVO.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"

#define NUM_SERVOS 3
#define EEPROM_START_ADDR 0x00

u8 angles[NUM_SERVOS] = {90, 90, 90};  // Default anglesk`

int main(void) {
    DIO_voidInit();
    LCD_voidInit();
    LCD_voidSetCursor(2,2);


    LCD_voidWriteString("Robotic Arm Ready");
    KPD_voidInit();
    SERVO_voidInit();


    u8 key;
    while (1) {
        key = KPD_u8GetPressedKey();
        if (key != 0xFF) {
            LCD_voidClear();
            LCD_voidWriteString("Pressed: ");
            LCD_voidSendData(key);

            switch (key) {
                case '1': // Servo 1 +
                    if (angles[0] < 180) angles[0] += 10;
                    SERVO_SetAngle(0, angles[0]);
                    break;
                case '4': // Servo 1 -
                    if (angles[0] > 0) angles[0] -= 10;
                    SERVO_SetAngle(0, angles[0]);
                    break;
                case '2': // Servo 2 +
                    if (angles[1] < 180) angles[1] += 10;
                    SERVO_SetAngle(1, angles[1]);
                    break;
                case '5': // Servo 2 -
                    if (angles[1] > 0) angles[1] -= 10;
                    SERVO_SetAngle(1, angles[1]);
                    break;
                case '3': // Servo 3 +
                    if (angles[2] < 180) angles[2] += 10;
                    SERVO_SetAngle(2, angles[2]);
                    break;
                case '6': // Servo 3 -
                    if (angles[2] > 0) angles[2] -= 10;
                    SERVO_SetAngle(2, angles[2]);
                    break;
                case 'C': // Save to EEPROM
                    EEPROM_voidWriteBlock(EEPROM_START_ADDR, angles, NUM_SERVOS);
                    LCD_voidSetCursor(1, 0);
                    LCD_voidWriteString("Saved to EEPROM");
                    _delay_ms(1000);
                    LCD_voidSetCursor(1, 0);
                    LCD_voidWriteString("                ");
                    break;
                case 'D': // Load from EEPROM
                    EEPROM_voidReadBlock(EEPROM_START_ADDR, angles, NUM_SERVOS);
                    for (u8 i = 0; i < NUM_SERVOS; i++) {
                        SERVO_SetAngle(i, angles[i]);
                        _delay_ms(100);
                    }
                    LCD_voidSetCursor(1, 0);
                    LCD_voidWriteString("Loaded from EEPROM");
                    _delay_ms(1000);
                    LCD_voidSetCursor(1, 0);
                    LCD_voidWriteString("                   ");
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
