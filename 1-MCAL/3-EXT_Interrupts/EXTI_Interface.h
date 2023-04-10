/*
 * EXTI_Interface.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Softlaptop
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE	3
#define RISING_EGDE		4

#define ENABLED			1
#define DISABLED		2

void EXTI_voidInt0_INIT(void);

void EXTI_voidInt1_INIT(void);

void EXTI_voidInt2_INIT(void);

/* Description : A Function to set the required sense control of int0 using post build configuration
   Input : Copy_u8Sense , Options are : 1- LOW_LEVEL
                                        2- ON_CHANGE
                                        3- FALLING_EDGE
                                        4- RISING_EGDE
   Output : Error status with type u8
   */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void));

#endif /* EXTI_INTERFACE_H_ */
