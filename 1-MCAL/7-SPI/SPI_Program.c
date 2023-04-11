/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : SPI		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Register.h"


void SPI_voidInitMaster(void)
{
	/*Master Initialization*/
	SET_BIT(SPCR, SPCR_MSTR);

	/*CLock Prescaler divide by 16*/
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/*Data Order is default*/

	/*CLK Polarity and phase is left as default*/

	/*SPI Enable*/
	SET_BIT(SPCR, SPCR_SPE);

}
void SPI_voidInitSlave(void)
{
	/*Master Initialization*/
	CLR_BIT(SPCR, SPCR_MSTR);
	/*Data Order is default*/
	/*SPI Enable*/
	SET_BIT(SPCR, SPCR_SPE);
}
u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send The Data once data is placed in register its starts sending
	 * no start bits*/
	SPDR = Copy_u8Data;

	/*Next two commands clear the flag by HW*/
	/*Polling until transmitting is complete*/
	while(GET_BIT(SPSR, SPSR_SPIF)==0);
	/*Get The exchanged data*/
	return SPDR ;
}
