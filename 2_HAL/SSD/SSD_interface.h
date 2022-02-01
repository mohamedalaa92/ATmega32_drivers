/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: SSD_interface.h            ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	u8 COM_TYPE;
	u8 PORT;
	u8 ENABLE_PORT;
	u8 ENABLE_PIN;
	u8 ENABLE_STATE;
}SSD_init;

#define CATHOD                             0
#define ANODE                              1

#define SSD_DISABLE                        0
#define SSD_ENABLE                         1


#define SSD_ZERO   			   	           0b0111111
#define SSD_ONE    			   	           0b0000110
#define SSD_TWO    			   	           0b1011011
#define SSD_THREE  			   	           0b1001111
#define SSD_FOUR   			   	           0b1100110
#define SSD_FIVE   			   	           0b1101101
#define SSD_SIX    			   	           0b1111101
#define SSD_SEVEN  			   	           0b0000111
#define SSD_EIGHT  			   	           0b1111111
#define SSD_NINE   			   	           0b1101111


#define  SSD_u8ENABLE_PIN0                 DIO_u8PIN0
#define  SSD_u8ENABLE_PIN1                 DIO_u8PIN1
#define  SSD_u8ENABLE_PIN2                 DIO_u8PIN2
#define  SSD_u8ENABLE_PIN3                 DIO_u8PIN3
#define  SSD_u8ENABLE_PIN4                 DIO_u8PIN4
#define  SSD_u8ENABLE_PIN5                 DIO_u8PIN5
#define  SSD_u8ENABLE_PIN6                 DIO_u8PIN6
#define  SSD_u8ENABLE_PIN7                 DIO_u8PIN7

#define  SSD_u8PORTA                       DIO_u8PORTA
#define  SSD_u8PORTB                       DIO_u8PORTB
#define  SSD_u8PORTC                       DIO_u8PORTC
#define  SSD_u8PORTD                       DIO_u8PORTD

#define  SSD_u8ENABLE_PORTA                DIO_u8PORTA
#define  SSD_u8ENABLE_PORTB                DIO_u8PORTB
#define  SSD_u8ENABLE_PORTC                DIO_u8PORTC
#define  SSD_u8ENABLE_PORTD                DIO_u8PORTD



u8 SSD_u8SetNumbers (s8 Copy_u8Number ,SSD_init *SSD);
u8 SSD_u8RangNumbers (u8 Copy_u8StartNumber, u8 Copy_u8EndNumber,SSD_init *SSD);
void SSD_u8intNumbers (u8 Copy_u8Number, SSD_init *SSD);
u8 SSD_u8NumEnableControl (u8 Copy_u8Number,u8 Copy_u8EnableState ,SSD_init *SSD);
#endif /* SSD_INTERFACE_H_ */
