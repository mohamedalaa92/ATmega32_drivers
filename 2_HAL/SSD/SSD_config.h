/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SSD_config.h               ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"


/********************************* 7-Segment initialization ************************************************/
/*
			       Choose:        Choose:          Choose:                 Choose:                  Choose:
		         |SSD_TYPE: |  |SSD_PORT:      | |SSD_ENABLE_PORT:     | |SSD_ENABLE_PIN:      |  |SSD_TYPE:     |
		         |->  CATHOD|  |-> SSD_u8PORTA | |-> SSD_u8ENABLE_PORTA| |-> SSD_u8ENABLE_PIN0 |  |-> SSD_ENABLE |
		         |          |  |               | |                     | |-> SSD_u8ENABLE_PIN1 |  |              |
		         |->  ANODE |  |-> SSD_u8PORTB | |-> SSD_u8ENABLE_PORTB| |-> SSD_u8ENABLE_PIN2 |  |-> SSD_DISABLE|
		         |  	    |  |               | |                     | |-> SSD_u8ENABLE_PIN3 |  |  	         |
		         |          |  |-> SSD_u8PORTC | |-> SSD_u8ENABLE_PORTC| |-> SSD_u8ENABLE_PIN4 |  |              |
		         |          |  |               | |                     | |-> SSD_u8ENABLE_PIN5 |  |              |
		         |          |  |-> SSD_u8PORTD | |-> SSD_u8ENABLE_PORTD| |-> SSD_u8ENABLE_PIN6 |  |              |
		         |          |  |               | |                     | |-> SSD_u8ENABLE_PIN7 |  |              |      */

SSD_init SSD1 = {  CATHOD,   	   SSD_u8PORTA,      SSD_u8ENABLE_PORTA,	 SSD_u8ENABLE_PIN7,	     SSD_ENABLE};


SSD_init SSD2 = {  CATHOD,		   SSD_u8PORTA,	     SSD_u8ENABLE_PORTB,	 SSD_u8ENABLE_PIN0,	     SSD_ENABLE};


/********************************* ADD more 7-segment if you want ******************************************/

#endif /* SSD_CONFIG_H_ */
