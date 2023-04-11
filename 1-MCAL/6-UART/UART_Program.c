/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : UART		         ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Register.h"


void USART_Init(void)
{
	/*We will use this variable to set the value of UCSRC register the passing it the register*/
	u8 Local_u8UCSRC_Value=0 ;
	SET_BIT(Local_u8UCSRC_Value , UCSRC_URSEL);

	/*Asynchronous UART*/
	CLR_BIT(Local_u8UCSRC_Value , UCSRC_UMSEL);

	/*Select Parity zto disabled*/
	CLR_BIT(Local_u8UCSRC_Value , UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRC_Value , UCSRC_UPM1);

	/*1 stop bit*/
	CLR_BIT(Local_u8UCSRC_Value , UCSRC_USBS);
	/*Setting Data size*/
	SET_BIT(Local_u8UCSRC_Value , UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_Value , UCSRC_UCSZ1);

	UCSRC = Local_u8UCSRC_Value;

	UBRRL = 51 ; 			/*Baud Rate 9600 bit per sec*/

	CLR_BIT(UCSRB,	UCSRB_UCSZ2);		/*Character Size with sc0 , sc1*/
	SET_BIT(UCSRB,	UCSRB_RXEN);		/*Enable Receiver*/
	SET_BIT(UCSRB,	UCSRB_TXEN);		/*Enable Transmit*/
}

u8 USART_u8Receive(void)
{
	while(GET_BIT(UCSRA , UCSRA_RXC) ==0);
	return UDR ;
}

void USART_voidSend(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA , UCSRA_UDRE) ==0);  //wait until transmit buffer us empty
	UDR = Copy_u8Data;
}
