/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: LED_config.h               ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "DIO_interface.h"
#include "LED_interface.h"




/********************************* LED initialization ************************************************/
/*
			              Choose:                Choose:               Choose:
		               |LED_PORT:      |   |   |SSD_ENABLE_PIN:|  |  |LED_TYPE:               |
		               |-> LED_u8PORTA |   |   |-> LED_u8PIN0  |  |  |-> LED_SOURCE_CONNECTION|-> if (LED connected to ground)
		               |               |   |   |-> LED_u8PIN1  |  |  |                        |
		               |-> LED_u8PORTB |   |   |-> LED_u8PIN2  |  |  |-> LED_SINK_CONNECTION  |-> if (LED connected to power )
		               |               |   |   |-> LED_u8PIN3  |  |  |  	                  |
		               |-> LED_u8PORTC |   |   |-> LED_u8PIN4  |  |  |                        |
		               |               |   |   |-> LED_u8PIN5  |  |  |                        |
		               |-> LED_u8PORTD |   |   |-> LED_u8PIN6  |  |  |                        |
		               |               |   |   |-> LED_u8PIN7  |  |  |                        |      */

LED_init LED_RED   = {     LED_u8PORTC,            LED_u8PIN0 ,          LED_SOURCE_CONNECTION};

LED_init LED_GREEN = {     LED_u8PORTC,            LED_u8PIN1 ,          LED_SINK_CONNECTION  };


/********************************* ADD more LEDs if you want ****************************************/
#endif /* LED_CONFIG_H_ */
