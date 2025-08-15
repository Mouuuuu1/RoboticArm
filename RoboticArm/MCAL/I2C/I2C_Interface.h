#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void TWI_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_Write(u8 data);
u8   TWI_Read_NACK(void);

#endif /* I2C_INTERFACE_H_ */
