/************************************************************************************************/
/************************************************************************************************/
/**********************************	  Author  : Mahmoud ELakhal *********************************/
/**********************************	  Layer   : HAL   		*************************************/
/**********************************	  SWC  	  : SSD   		*************************************/
/**********************************	  Version : 1.00   		*************************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define Zero  0b00111111
#define One  0b00000110
#define Two  0b01011011
#define Three  0b01001111
#define Four  0b01100110
#define Five  0b01101101
#define Six  0b01111101
#define Seven  0b00000111
#define Eight  0b01111111
#define Nine  0b01101111

#define COM_ANODE      1
#define COM_CATHODE    0



typedef struct
{
		u8 COM_Type ;
		u8 Copy_u8PORT_ID;
		u8 Copy_u8EnablePort;
		u8 Copy_u8EnablePin ;
		u16 Delay;
}SSD_Type;

//void SSD_INIT(SSD_Type *SSD);
u8 SSD_u8CountUp( SSD_Type *SSD );
u8 SSD_u8CountDown( SSD_Type *SSD );
u8 SSD_u8SetNumber( SSD_Type *SSD );


#endif /* SSD_INTERFACE_H_ */
