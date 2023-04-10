#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "TIMER_Interface.h"
#include "TIMER_Register.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidINIT(void)
{
	/*Choose CTC Mode */
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	/* Set COmpare match value to 250*/
	OCR0 = 125 ;

	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK ,TIMSK_OCIE0);

	/*Prescaler division by 64*/
	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLR_BIT(TCCR0 , TCCR0_CS00);



}
u8 TIMER0_u8SetCallBack(void (* Copy_pvCallBackFunc) (void))
{
	u8 Local_u8ErrorStatus = OK;
	if(Copy_pvCallBackFunc !=NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc !=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}

