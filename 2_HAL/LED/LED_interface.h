/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: LED_interface.h            ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


typedef struct{
	u8 PORT;
	u8 PIN;
	u8 CONNECTING_TYPE;
}LED_init;


#define  LED_SINK_CONNECTION       0
#define  LED_SOURCE_CONNECTION     1

#define  LED_u8PIN0                 DIO_u8PIN0
#define  LED_u8PIN1                 DIO_u8PIN1
#define  LED_u8PIN2                 DIO_u8PIN2
#define  LED_u8PIN3                 DIO_u8PIN3
#define  LED_u8PIN4                 DIO_u8PIN4
#define  LED_u8PIN5                 DIO_u8PIN5
#define  LED_u8PIN6                 DIO_u8PIN6
#define  LED_u8PIN7                 DIO_u8PIN7

#define  LED_u8PORTA                DIO_u8PORTA
#define  LED_u8PORTB                DIO_u8PORTB
#define  LED_u8PORTC                DIO_u8PORTC
#define  LED_u8PORTD                DIO_u8PORTD








#endif /* LED_INTERFACE_H_ */
