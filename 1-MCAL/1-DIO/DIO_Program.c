/************************************************************************************************/
/************************************************************************************************/
/**********************************	  Author  :  Mahmoud ELakhal ********************************/
/**********************************	  Layer   : MCAL   		*************************************/
/**********************************	  SWC  : DIO   		*****************************************/
/**********************************	  Version : 1.00   		*************************************/
/************************************************************************************************/
/************************************************************************************************/

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "DIO_Config.h"
#include "DIO_Private.h"

u8 DIO_u8SetPortValue(u8 Copy_u8PORT_ID , u8 Copy_u8Value )
{
	u8 Local_u8ErrorState = 0 ;
	switch(Copy_u8PORT_ID)
	{
	case DIO_u8PORTA : PORTA = Copy_u8Value ; break ;
	case DIO_u8PORTB : PORTB = Copy_u8Value ; break ;
	case DIO_u8PORTC : PORTC = Copy_u8Value ; break ;
	case DIO_u8PORTD : PORTD = Copy_u8Value ; break ;
	default : Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PORT_ID , u8 Copy_u8Pin_ID  ,u8 Copy_u8Value )
{
	u8 Local_u8ErrorState = 0 ;
	if(Copy_u8Pin_ID >= DIO_u8PIN0 && Copy_u8Pin_ID <=DIO_u8PIN7)
	{
		if( Copy_u8Value == DIO_u8PIN_LOW )
		{
			switch(Copy_u8PORT_ID)
			{
			case DIO_u8PORTA   :  CLR_BIT(PORTA , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTB   :  CLR_BIT(PORTB , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTC   :  CLR_BIT(PORTC , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTD   :  CLR_BIT(PORTD , Copy_u8Pin_ID) ; break ;
			default : Local_u8ErrorState = 1 ;
			}
		}
		else if( Copy_u8Value ==DIO_u8PIN_HIGH )
		{
			switch(Copy_u8PORT_ID)
			{
			case DIO_u8PORTA   :  SET_BIT(PORTA , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTB   :  SET_BIT(PORTB , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTC   :  SET_BIT(PORTC , Copy_u8Pin_ID) ; break ;
			case DIO_u8PORTD   :  SET_BIT(PORTD , Copy_u8Pin_ID) ; break ;
			default : Local_u8ErrorState = 1 ;
			}
		}
		else
		{
			Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
u8 DIO_u8ReadPort(u8 Copy_u8PORT_ID  , u8 * Copy_u8PortReading)
{
	u8 Local_u8ErrorState = 0 ;
	if( (Copy_u8PortReading != NULL ) && (Copy_u8PORT_ID <= DIO_u8PORTA) && (Copy_u8PORT_ID <= DIO_u8PORTD) )
	{
		switch(Copy_u8PORT_ID)
		{
		case DIO_u8PORTA   : * Copy_u8PortReading = PINA ; break ;
		case DIO_u8PORTB   : * Copy_u8PortReading = PINB ; break ;
		case DIO_u8PORTC   : * Copy_u8PortReading = PINC ; break ;
		case DIO_u8PORTD   : * Copy_u8PortReading = PIND ; break ;
		default : Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
u8 DIO_u8ReadPin(u8 Copy_u8PORT_ID  , u8 Copy_u8Pin_ID , u8 * Copy_u8PinReading)
{
	u8 Local_u8ErrorState = 0 ;
	if( (Copy_u8PinReading != NULL ) && (Copy_u8Pin_ID >= DIO_u8PIN0) && (Copy_u8Pin_ID<=DIO_u8PIN7) )
	{
		switch(Copy_u8PORT_ID)
		{
		case DIO_u8PORTA   : * Copy_u8PinReading =  GET_BIT(PINA , Copy_u8Pin_ID) ; break ;
		case DIO_u8PORTB   : * Copy_u8PinReading =  GET_BIT(PINB , Copy_u8Pin_ID) ; break ;
		case DIO_u8PORTC   : * Copy_u8PinReading =  GET_BIT(PINC , Copy_u8Pin_ID) ; break ;
		case DIO_u8PORTD   : * Copy_u8PinReading =  GET_BIT(PIND , Copy_u8Pin_ID) ; break ;
		default : Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

