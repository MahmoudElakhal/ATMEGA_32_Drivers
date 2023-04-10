/************************************************************************************************/
/************************************************************************************************/
/**********************************	  Author  : Mahmoud ELakhal *********************************/
/**********************************	  Layer   : HAL   		*************************************/
/**********************************	  SWC  	  : SSD   		*************************************/
/**********************************	  Version : 1.00   		*************************************/
/************************************************************************************************/
/************************************************************************************************/
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SSD_Interface.h"
#include "SSD_Config.h"
#include "util/delay.h"
/*void SSD_INIT(SSD_Type *SSD)
{
	DIO_u8SetPortDirection(SSD->Copy_u8PORT_ID , DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_OUTPUT);
}
*/
u8 SSD_u8CountUp( SSD_Type *SSD )
{
	u8 Local_u8ErrorState = 0 ;
	u8 Local_u8Counter ;
	if(SSD->COM_Type==COM_ANODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_HIGH);
		for(Local_u8Counter = StartNum ; Local_u8Counter <=EndNum ; Local_u8Counter++)
		{
			switch(Local_u8Counter)
			{
			case 0 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Zero);break;
			case 1 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~One);break;
			case 2 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Two);break;
			case 3 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Three);break;
			case 4 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Four);break;
			case 5 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Five);break;
			case 6 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Six);break;
			case 7 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Seven);break;
			case 8 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Eight);break;
			case 9 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Nine);break;
			default : Local_u8ErrorState = 1 ;
			}
			_delay_ms(SSD->Delay);
		}
	}
	else if (SSD->COM_Type==COM_CATHODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_LOW);
		for(Local_u8Counter = StartNum ; Local_u8Counter <=EndNum ; Local_u8Counter++)
		{
			switch(Local_u8Counter)
			{
			case 0 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Zero);break;
			case 1 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~One);break;
			case 2 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Two);break;
			case 3 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Three);break;
			case 4 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Four);break;
			case 5 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Five);break;
			case 6 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Six);break;
			case 7 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Seven);break;
			case 8 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Eight);break;
			case 9 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Nine);break;
			default : Local_u8ErrorState = 1 ;
			}
			_delay_ms(SSD->Delay);
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

u8 SSD_u8CountDown( SSD_Type *SSD )
{
	u8 Local_u8ErrorState = 0 ;
	s8 Local_u8Counter ;
	if(SSD->COM_Type==COM_ANODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_HIGH);
		for(Local_u8Counter = EndNum ; Local_u8Counter >=StartNum ; Local_u8Counter--)
		{
			switch(Local_u8Counter)
			{
			case 0 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Zero);break;
			case 1 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~One);break;
			case 2 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Two);break;
			case 3 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Three);break;
			case 4 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Four);break;
			case 5 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Five);break;
			case 6 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Six);break;
			case 7 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Seven);break;
			case 8 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Eight);break;
			case 9 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Nine);break;
			default : Local_u8ErrorState = 1 ;
			}
			_delay_ms(SSD->Delay);
		}
	}
	else if (SSD->COM_Type==COM_CATHODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_LOW);
		for(Local_u8Counter = EndNum ; Local_u8Counter >=StartNum ; Local_u8Counter--)
		{
			switch(Local_u8Counter)
			{
			case 0 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Zero);break;
			case 1 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~One);break;
			case 2 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Two);break;
			case 3 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Three);break;
			case 4 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Four);break;
			case 5 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Five);break;
			case 6 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Six);break;
			case 7 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Seven);break;
			case 8 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Eight);break;
			case 9 : DIO_u8SetPortValue(SSD->Copy_u8PORT_ID,~Nine);break;
			default : Local_u8ErrorState = 1 ;
			}
			_delay_ms(SSD->Delay);
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
u8 SSD_u8SetNumber( SSD_Type *SSD )
{
	u8 Local_u8ErrorState = 0 ;
	if(SSD->COM_Type==COM_ANODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(SSD->Copy_u8PORT_ID , ~SetNum );
	}
	else if (SSD->COM_Type==COM_CATHODE)
	{
		DIO_u8SetPinValue(SSD->Copy_u8EnablePort , SSD->Copy_u8EnablePin , DIO_u8PIN_LOW);
		DIO_u8SetPortValue(SSD->Copy_u8PORT_ID , ~SetNum );
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;

}


