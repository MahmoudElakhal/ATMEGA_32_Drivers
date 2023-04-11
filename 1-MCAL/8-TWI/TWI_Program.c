/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : TWI		             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_Register.h"
#include "TWI_Config.h"
#include "TWI_Private.h"
#include "TWI_Interface.h"

/*Pass 0 in the slave address argument if master will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set Clock freq to 400kbps*/
	/*Set TWBR to 2 we get this value from equation in datasheet*/
	TWDR = 2;
	/*Clear bits of TWPS*/
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);
	/*Initialize the node address*/
	if(Copy_u8SlaveAddress !=0)
	{
		TWAR = Copy_u8SlaveAddress<<1;
	}
	/*Enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);
}
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node address*/
	TWAR = Copy_u8SlaveAddress<<1;

	/*Enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);
}
TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send Start Condition on the bus*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrStatus = StartConditionError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send Start Condition on the bus*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus = RepeatedStartError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set The slave Address in the seven  MSB in Data register*/
	TWDR = Copy_u8SlaveAddress<<1;
	/*For Write request*/
	CLR_BIT(TWDR,0);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != SLAVE_ADDR_AND_WR_ACK)
	{
		Local_ErrStatus = SlaveAddressWithWriteError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set The slave Address in the seven  MSB in Data register*/
	TWDR = Copy_u8SlaveAddress<<1;
	/*For Read request*/
	SET_BIT(TWDR,0);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != SLAVE_ADDR_AND_RD_ACK)
	{
		Local_ErrStatus = SlaveAddressWithReadError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}
TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Write the data byte*/
	TWDR = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus = MasterWriteByteError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}
TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Enable master generating acknowledge bit after receiving data*/
	SET_BIT(TWCR, TWCR_TWEA);

	/*Clear the interrupt flag to allow slave to send data*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while((GET_BIT(TWCR, TWCR_TWINT))==0);

	/*Check The operation status in the status register*/
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrStatus = MasterReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR;
	}
	return Local_ErrStatus;
}
void TWI_SendStopCondition(void)
{
	/*Generate stop condition on the bus*/
	SET_BIT(TWCR, TWCR_TWSTO);

	/*Clear the interrupt flag to start teh previous operation*/
	SET_BIT(TWCR, TWCR_TWINT);
}
