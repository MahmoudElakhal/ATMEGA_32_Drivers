/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : ADC		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX  *((volatile u8*)0x27)// ADC multiplexer selection register
#define ADMUX_REFS1			7		//Reference Selection BIT1
#define ADMUX_REFS0			6		//Reference Selection BIT0
#define ADMUX_ADLAR			5		//ADC Left Adjust result

#define ADCSRA	*((volatile u8*)0x26)	//ADC Control and status register A
#define ADCSRA_ADEN				7		//ADC Enable
#define ADCSRA_ADSC				6		//Start conversion
#define ADCSRA_ADATE			5		//Auto trigger enable
#define ADCSRA_ADIF				4		//Interrupt flag
#define ADCSRA_ADIE				3		//interrupt enable
#define ADCSRA_ADPS2			2		//Prescaler bit2
#define ADCSRA_ADPS1			1		//Prescaler bit1
#define ADCSRA_ADPS0			0		//Prescaler bit0

#define ADCH	*((volatile u8*)0x25)	//ADC High register
#define ADCL	*((volatile u8*)0x24)	//ADC Low  register

#endif /* ADC_ADC_REGISTER_H_ */
