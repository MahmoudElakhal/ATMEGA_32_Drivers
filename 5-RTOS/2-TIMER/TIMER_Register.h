/*
 * TIMER_Register.h
 *
 *  Created on: Mar 15, 2023
 *      Author: Softlaptop
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53) //Timer0 control register
#define TCCR0_WGM00		6					  //Waveform Generation mode bit0
#define TCCR0_WGM01		3					  //Waveform Generation mode bit1
#define TCCR0_CS02		2					 //Prescaler bit2
#define TCCR0_CS01		1					 //Prescaler bit1
#define TCCR0_CS00		0					//Prescaler bit0

#define OCR0			*((volatile u8*)0x5C)	//output compare register0

#define TIMSK			*((volatile u8*)0x59)	//timer mask
#define TIMSK_OCIE0		1						//output compare 0 interrupt enable
/*Setting Timer 1 for fast PWM */
#define TCCR1A			*((volatile u8*)0x4f) //Timer1 control register
#define TCCR1B			*((volatile u8*)0x4e)

#define ICR1			*((volatile u16*)0x46)
#define OCR1A			*((volatile u16*)0x4a)

#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1

#define TCCR1A_COM1A1		7
#define TCCR1A_COM1A0		6

#define TCCR1B_WGM13		4
#define TCCR1B_WGM12		3

#define PRESCALER_MASK		0b11111000
#define DIVIDE_BY_8			2


#endif /* TIMER_TIMER_REGISTER_H_ */
