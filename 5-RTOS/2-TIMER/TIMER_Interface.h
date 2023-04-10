/*
 * TIMER_Interface.h
 *
 *  Created on: Mar 15, 2023
 *      Author: Softlaptop
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidINIT(void);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc) (void));

#endif /* TIMER_TIMER_INTERFACE_H_ */
