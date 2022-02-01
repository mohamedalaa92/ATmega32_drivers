/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SWITCH_program.c           ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SWITCH_interface.h"
#include "util/delay.h"


u8 SWITCH_u8GetState (SWITCH_init *SWITCH, u8 *Copy_pu8Value)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8ReadingGet = 0;
	if(SWITCH->PULL_TYPE == SWITCH_PULLUP)
	{
		if(SWITCH->SELFLOCKING_TYPE == SWITCH_MOMENTARY)
		{
			Local_u8ErrorState = DIO_u8GetPinValue(SWITCH->PORT,SWITCH->PIN,&Local_u8ReadingGet);
			if( Local_u8ReadingGet==0)
			{
				_delay_ms (150);
				*Copy_pu8Value = 1;
			}
			else
			{
				_delay_ms (150);
				*Copy_pu8Value = 0;
			}
		}
		else if (SWITCH->SELFLOCKING_TYPE == SWITCH_MAINTAINED)
		{
			Local_u8ErrorState = DIO_u8GetPinValue(SWITCH->PORT,SWITCH->PIN,&Local_u8ReadingGet);
			if( Local_u8ReadingGet==1)
			{
				*Copy_pu8Value = 1;
			}
			else
			{
				*Copy_pu8Value = 0;
			}
		}
		else
		{
			Local_u8ErrorState =1;
		}
	}
	else if (SWITCH->PULL_TYPE == SWITCH_PULLDOWN)
	{
		if(SWITCH->SELFLOCKING_TYPE == SWITCH_MOMENTARY)
		{
			Local_u8ErrorState = DIO_u8GetPinValue(SWITCH->PORT,SWITCH->PIN,&Local_u8ReadingGet);
			if( Local_u8ReadingGet==1)
			{
				_delay_ms (150);
				*Copy_pu8Value = 1;
			}
			else
			{
				_delay_ms (150);
				*Copy_pu8Value = 0;
			}
		}
		else if (SWITCH->SELFLOCKING_TYPE == SWITCH_MAINTAINED)
		{
			Local_u8ErrorState = DIO_u8GetPinValue(SWITCH->PORT,SWITCH->PIN,&Local_u8ReadingGet);
			if( Local_u8ReadingGet==1)
			{
				*Copy_pu8Value = 1;
			}
			else
			{
				*Copy_pu8Value = 0;
			}
		}
		else
		{
			Local_u8ErrorState =1;
		}
	}
	else
	{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState ;
}
