/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : HAL   		         ********************************/
/*****************************	  SWC     : LED   		         ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LED_INIT(u8 Copy_u8PORT_ID , u8 Copy_u8Pin_ID);
void LED_ON( u8 Copy_u8PORT_ID , u8 Copy_u8Pin_ID );
void LED_OFF(u8 Copy_u8PORT_ID , u8 Copy_u8Pin_ID );

#endif /* LED_INTERFACE_H_ */