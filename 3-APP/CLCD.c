
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HAL/CLCD/CLCD_Interface.h"
#include "HAL/CLCD/CLCD_Config.h"


void main (void)
{
	DIO_u8SetPortDirection( DIO_u8PORTA , DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0 , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1 , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2 , DIO_u8PIN_OUTPUT);
	CLCD_VoidSendString("Rowida");
	u8 arr[8]={0b00000111,0b00000101,0b00000101,0b00001111,0b00001100,0b00001100,0b00001100,0b11101100};
	CLCD_VoidInit();
	CLCD_VoidWriteSpecialCharacter(arr ,0,0,0);



	/*CLCD_VoidSendData('M');
	CLCD_VoidSendData('A');
	CLCD_VoidSendData('H');
	CLCD_VoidSendData('M');
	CLCD_VoidSendData('O');
	CLCD_VoidSendData('U');
	CLCD_VoidSendData('D');*/

	while(1)
	{

	}
}

