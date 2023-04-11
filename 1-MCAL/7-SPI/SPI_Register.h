/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : SPI		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_
#define SPDR        	*((volatile u8*)0x2F)  /*SPI Data register*/

#define SPSR        	*((volatile u8*)0x2E)	/*SPI Status Register*/
#define SPSR_SPIF		7						/*SPI interrupt flag*/
#define SPSR_SPI2X		0						/*Prescaler but 2*/

#define SPCR        	*((volatile u8*)0x2D)	/*SPI Control register*/
#define SPCR_SPE		6						/*SPI Enable*/
#define SPCR_MSTR		4						/*Master BIT*/
#define SPCR_SPR1   	1						/*Prescaler Bit1*/
#define SPCR_SPR0   	0						/*Prescaler Bit0*/
#endif /* SPI_REGISTER_H_ */
