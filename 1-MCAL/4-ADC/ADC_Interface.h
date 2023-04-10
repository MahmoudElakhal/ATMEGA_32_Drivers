/*
 * ADC_Interface.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Softlaptop
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidINIT(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading);

u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading , void (*Copy_pvNotificationFunc)(void));

#endif /* ADC_ADC_INTERFACE_H_ */
