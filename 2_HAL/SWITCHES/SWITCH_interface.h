/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SWITCH_interface.h         ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/
#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

typedef struct {
	u8 PORT;
	u8 PIN;
	u8 SELFLOCKING_TYPE;   // is it Momentary or maintained .....because momentary SW need delay(to solve bouncing)
	u8 PULL_TYPE;
}SWITCH_init;



#define SWITCH_MAINTAINED          0
#define SWITCH_MOMENTARY           1    //need a delay(debouncing)

#define SWITCH_PULLDOWN            0
#define SWITCH_PULLUP              1


#define  SWITCH_u8PORTA            DIO_u8PORTA
#define  SWITCH_u8PORTB            DIO_u8PORTB
#define  SWITCH_u8PORTC            DIO_u8PORTC
#define  SWITCH_u8PORTD            DIO_u8PORTD

#define  SWITCH_u8PIN0             DIO_u8PIN0
#define  SWITCH_u8PIN1             DIO_u8PIN1
#define  SWITCH_u8PIN2             DIO_u8PIN2
#define  SWITCH_u8PIN3             DIO_u8PIN3
#define  SWITCH_u8PIN4             DIO_u8PIN4
#define  SWITCH_u8PIN5             DIO_u8PIN5
#define  SWITCH_u8PIN6             DIO_u8PIN6
#define  SWITCH_u8PIN7             DIO_u8PIN7

u8 SWITCH_u8GetState (SWITCH_init *SWITCH, u8 *Copy_pu8Value);

#endif /* SWITCH_INTERFACE_H_ */
