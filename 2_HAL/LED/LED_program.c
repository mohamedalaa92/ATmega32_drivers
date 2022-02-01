/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: LED_program.h              ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"

#include "LED_interface.h"


u8 LED_u8TurnOn (LED_init *LED_Color)
{
	/*make error state be 1 if the user entered the wrong input to the function*/
	u8 Local_u8ErrorState = 0;
	if(LED_Color->CONNECTING_TYPE ==  LED_SOURCE_CONNECTION)
	{
		DIO_u8SetPinValue(LED_Color->PORT,LED_Color->PIN,DIO_u8PIN_HIGH);
	}
	else if (LED_Color->CONNECTING_TYPE ==  LED_SINK_CONNECTION)
	{
		DIO_u8SetPinValue(LED_Color->PORT,LED_Color->PIN,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState =1;
	}

	return Local_u8ErrorState;
}

u8 LED_u8TurnOff (LED_init *LED_Color)
{
	/*make error state be 1 if the user entered the wrong input to the function*/
	u8 Local_u8ErrorState = 0;
	if(LED_Color->CONNECTING_TYPE ==  LED_SOURCE_CONNECTION)
	{
		DIO_u8SetPinValue(LED_Color->PORT,LED_Color->PIN,DIO_u8PIN_LOW);
	}
	else if (LED_Color->CONNECTING_TYPE ==  LED_SINK_CONNECTION)
	{
		DIO_u8SetPinValue(LED_Color->PORT,LED_Color->PIN,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState =1;
	}

	return Local_u8ErrorState;
}

