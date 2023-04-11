/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : TWI		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR			*((volatile u8*)0x20)		/*Bit Rate Register*/

#define TWCR			*((volatile u8*)0x56)
#define TWCR_TWINT		7	/*TWI Interrupt flag*/
#define TWCR_TWEA		6	/*Enable Acknowledge Bit*/
#define TWCR_TWSTA		5	/*TWI START CONDITION BIT*/
#define TWCR_TWSTO		4	/*TWI Stop Condition bit*/
#define TWCR_TWWC		3	/*TWI Write Collision Flag*/
#define TWCR_TWEN		2	/*TWI Enable BIT*/
#define TWCR_TWIE		0	/*TWI INterrupt Enable*/

#define TWSR			*((volatile u8*)0x21	)
#define TWSR_TWS7		7	/*TWI Status Bit*/
#define TWSR_TWS6		6
#define TWSR_TWS5		5
#define TWSR_TWS4		4
#define TWSR_TWS3		3
#define TWSR_TWPS1		1	/*Prescaler Bit1*/
#define TWSR_TWPS0		0	/*Prescaler bit 0*/

#define TWDR			*((volatile u8*)0x23)

#define TWAR			*((volatile u8*)0x22)
#define TWAR_TWGCE		0


#endif /* TWI_REGISTER_H_ */
