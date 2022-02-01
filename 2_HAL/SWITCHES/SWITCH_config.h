/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SWITCH_config.h            ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#include "DIO_interface.h"
#include "SWITCH_interface.h"




/********************************* Switch initialization ************************************************/
/*
			          Choose:               Choose:              Choose:                 Choose:
		           |SWITCH_PORT:      |   |SWITCH_PIN:      |  |SELF_LOCKING_TYPE:  |  |PULL_TYPE:         |
		           |-> SWITCH_u8PORTA |   |-> SWITCH_u8PIN0 |  |-> SWITCH_MAINTAINED|  |-> SWITCH_PULLUP   |->external pullup
		           |                  |   |-> SWITCH_u8PIN1 |  |                    |  |                   |
		           |-> SWITCH_u8PORTB |   |-> SWITCH_u8PIN2 |  |-> SWITCH_MOMENTARY |  |-> SWITCH_PULLDOWN |->external pulldown
		           |                  |   |-> SWITCH_u8PIN3 |  |  	                |  |  	               |
		           |-> SWITCH_u8PORTC |   |-> SWITCH_u8PIN4 |  |                    |  |                   |
		           |                  |   |-> SWITCH_u8PIN5 |  |                    |  |                   |
		           |-> SWITCH_u8PORTD |   |-> SWITCH_u8PIN6 |  |                    |  |                   |
		           |                  |   |-> SWITCH_u8PIN7 |  |                    |  |                   | */

SWITCH_init  SW1 = {   SWITCH_u8PORTD,        SWITCH_u8PIN0,      SWITCH_MOMENTARY,         SWITCH_PULLUP  };

/********************************* ADD more Switches if you want ******************************************/



#endif /* SWITCH_CONFIG_H_ */
