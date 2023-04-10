/*
 * UART_Interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Softlaptop
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void USART_Init(void);

void USART_voidSend(u8 Copy_u8Data);

u8 USART_u8Receive(void);

#endif /* UART_UART_INTERFACE_H_ */
