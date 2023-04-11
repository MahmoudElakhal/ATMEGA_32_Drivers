/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : TWI		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK				0x08 /*Start Has been Sent*/
#define REP_START_ACK			0x10 /*Repeated start*/
#define SLAVE_ADDR_AND_WR_ACK	0x18 /*Master Transmit (slave address + write request ) ack*/
#define SLAVE_ADDR_AND_RD_ACK	0x40 /*Master Transmit (slave address + read request ) ack*/
#define MSTR_WR_BYTE_ACK		0x28 /*Master transmit data ack*/
#define MSTR_RD_BYTE_WITH_ACK	0x50 /*Master received data with ack*/
#define MSTR_RD_BYTE_WITH_NACK	0x58 /*Master received data with not ack*/
#define SLAVE_ADDR_RCVD_RD_REQ	0xA8 /*means that slave address is received with read request*/
#define SLAVE_ADDR_RCVD_WR_REQ	0x60 /*means that slave address is received with write request*/
#define SLAVE_DATA_RECEIVED		0x80 /*means that a bute is received */
#define SLAVE_BYTE_TRANSMITTED	0xB8 /*means that the written byre is transmitted*/

#endif /* TWI_PRIVATE_H_ */
