/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Softlaptop
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

void RTOS_voidStart(void);

u8 RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif /* RTOS_RTOS_INTERFACE_H_ */
