#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

#define TWSR    *((volatile u8*)(0x21))
#define TWBR    *((volatile u8*)(0x20))
#define TWCR    *((volatile u8*)(0x56))
#define TWDR    *((volatile u8*)(0x23))

// Control bits
#define TWEN    2
#define TWINT   7
#define TWSTA   5
#define TWSTO   4

#endif /* I2C_PRIVATE_H_ */
