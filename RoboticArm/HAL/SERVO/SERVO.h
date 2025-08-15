#define Servo1_Group_1 DIO_u8_PORTD
#define Servo_Group_2 DIO_u8_PORTC

#define servo1conrtorldegree_D     DIO_u8_PIN4
#define servo2conrtorldegree_D     DIO_u8_PIN5
#define servo3conrtorldegree_D     DIO_u8_PIN7
#define servo4conrtorldegree_C     DIO_u8_PIN0
#define servo5conrtorldegree_C     DIO_u8_PIN1
#define servo6conrtorldegree_C     DIO_u8_PIN2


////
void SERVO_voidInit(void);
void SERVO_SetAngle(u8 servo_id, u16 angle);  // angle from 0 to 180




