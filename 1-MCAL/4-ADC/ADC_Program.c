/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : ADC		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Register.h"

//we use static because we won`t use these global function in other file
//we declared these global variables to use them values in the reading function in ISR FUNC
static u16 *ADC_pu16Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;
u8 ADC_u8BusyState =IDLE ;
void ADC_voidINIT(void)
{
	/*AVCC as reference voltage */
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLR_BIT(ADMUX , ADMUX_REFS1);

	/*Activate Left Adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Setting Prescaler to divide by 128*/
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);

	/*Enable Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading)
{
	u32 Local_u32Counter = 0;
	u8  Local_u8ErrorState = OK ;
	if (ADC_u8BusyState == IDLE)
	{
		/*ADC is now busy*/
		ADC_u8BusyState = BUSY_FUNC;

		/*Clear The MUX Bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel into the mux bits*/
		ADMUX |= Copy_u8Channel;

		/*Start Conversion*/
		SET_BIT(ADCSRA , ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reach timeout value*/
		while(((GET_BIT(ADCSRA , ADCSRA_ADIF))==0) && (Local_u32Counter !=ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}

		if(Local_u32Counter == ADC_u32TIMEOUT )
		{
			//Loop is broken because the time out is reached
			Local_u8ErrorState = NOTOK;
		}
		else
		{
			/*Loop is broken because flag is raised */
			/*Clear the conversion complete flag*/
			SET_BIT(ADCSRA , ADCSRA_ADIF);

			/*Return the reading value*/
			*Copy_pu16Reading =  ADCH ;

			/*ADC is finished return to idle*/
			ADC_u8BusyState = IDLE ;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC ;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading , void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState == IDLE)
	{
		if((Copy_pu16Reading ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/*Make ADC Busy in order not to work until being idle*/
			ADC_u8BusyState = BUSY ;

			/*Assign values to global variables to be used in ISR functions*/
			/*initialize the reading variables*/
			ADC_pu16Reading = Copy_pu16Reading;
			/*Initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*Clear The MUX Bits in ADMUX register*/
			ADMUX &= 0b11100000;

			/*Set the required channel into the mux bits*/
			ADMUX |= Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA , ADCSRA_ADSC);

			/*ADC interrupt Enable*/
			SET_BIT(ADCSRA , ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	*ADC_pu16Reading = ADCH;

	/*make ADC state idle because it finished*/
	ADC_u8BusyState = IDLE;

	/*INVOKE The call back notification function*/
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC Conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
