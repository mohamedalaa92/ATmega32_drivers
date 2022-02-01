/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SSD_program.h            ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SSD_interface.h"

#include <util/delay.h>


u8 SSD_u8SetNumbers (s8 Copy_u8Number ,SSD_init *SSD)
{
	u8 Local_u8ErrorState = 0;

	if(SSD->COM_TYPE == CATHOD)
	{
		if(SSD->ENABLE_STATE == SSD_ENABLE)
		{
			DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_LOW);
			DIO_u8SetPortValue(SSD->PORT,Copy_u8Number);
		}
		else if(SSD->ENABLE_STATE == SSD_DISABLE)
		{
			DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}

	else if (SSD->COM_TYPE == ANODE)
	{
		if(SSD->ENABLE_STATE == SSD_ENABLE)
		{
			DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSD->PORT,(~Copy_u8Number));
		}
		else if(SSD->ENABLE_STATE == SSD_DISABLE)
		{
			DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return  Local_u8ErrorState;
}


u8 SSD_u8RangNumbers (u8 Copy_u8StartNumber, u8 Copy_u8EndNumber,SSD_init *SSD)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8SSD_Counter = 0;
	u8 Local_u8SSD_Array[10] = {SSD_ZERO,SSD_ONE,SSD_TWO,SSD_THREE,SSD_FOUR,SSD_FIVE,SSD_SIX,SSD_SEVEN,SSD_EIGHT,SSD_NINE};
	if (Copy_u8EndNumber <=9)
	{
		for(Local_u8SSD_Counter = Copy_u8StartNumber; Local_u8SSD_Counter<=Copy_u8EndNumber;Local_u8SSD_Counter++)
		{
			SSD_u8SetNumbers(Local_u8SSD_Array[Local_u8SSD_Counter],SSD);
			_delay_ms(1000);
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return  Local_u8ErrorState;
}

void SSD_u8intNumbers (u8 Copy_u8Number, SSD_init *SSD)
{
	u8 Local_u8SSD_Array[10] = {SSD_ZERO,SSD_ONE,SSD_TWO,SSD_THREE,SSD_FOUR,SSD_FIVE,SSD_SIX,SSD_SEVEN,SSD_EIGHT,SSD_NINE};

	SSD_u8SetNumbers(Local_u8SSD_Array[Copy_u8Number],SSD);

}

u8 SSD_u8NumEnableControl (u8 Copy_u8Number,u8 Copy_u8EnableState ,SSD_init *SSD)
{
	u8 Local_u8ErrorState =0 ;
	u8 Local_u8SSD_Array[10] = {SSD_ZERO,SSD_ONE,SSD_TWO,SSD_THREE,SSD_FOUR,SSD_FIVE,SSD_SIX,SSD_SEVEN,SSD_EIGHT,SSD_NINE};

	if(Copy_u8EnableState == SSD_ENABLE)
	{
		DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_LOW);
		SSD_u8SetNumbers(Local_u8SSD_Array[Copy_u8Number],SSD);
	}
	else if (Copy_u8EnableState == SSD_DISABLE)
	{
		DIO_u8SetPinValue(SSD->ENABLE_PORT,SSD->ENABLE_PIN,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;

	}
	return  Local_u8ErrorState;

}

