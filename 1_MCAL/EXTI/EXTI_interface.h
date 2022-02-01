/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: MCAL                     ***********************/
/*****************    SWC: EXTI_interface.h           ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0                      1
#define EXTI_INT1                      2
#define EXTI_INT2                      3

#define LOW_LEVEL                      1
#define RISING_EDGE                    2
#define FALLING_EDGE                   3
#define ON_CHANGE                      4



void EXTI_voidInit0 (void);
void EXTI_voidInit1 (void);
void EXTI_voidInit2 (void);

/*Description :  a function to set the required sense control for Selected INT0 using post build configuration*/
/*Input : Copy_u8Sense , Options :
 *output: Error status with type u8
 *                             |LOW_LEVEL   |
 *                             |RISING_EDGE |
 *                             |FALLING_EDGE|
 *                             |ON_CHANGE   |
 * */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

/*Description :  a function to set the required sense control for Selected INT1 using post build configuration*/
/*Input : Copy_u8Sense , Options :
 *output: Error status with type u8
 *                             |LOW_LEVEL   |
 *                             |RISING_EDGE |
 *                             |FALLING_EDGE|
 *                             |ON_CHANGE   |
 * */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

/*Description :  a function to set the required sense control for Selected INT2 using post build configuration*/
/*Input : Copy_u8Sense , Options :
 *output: Error status with type u8
 *                             |RISING_EDGE |
 *                             |FALLING_EDGE|
 * */
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

/*/*Description :  a function to set the required peripheral INT Enable of EXTI using post build configuration*/
/*Input : Copy_u8Int , Options :
 *output: Error status with type u8
 *  *                  |EXTI_INT0 |
 *                     |EXTI_INT1 |
 *                     |EXTI_INT2 |
 * */
u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt0Func)(void));
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt0Func)(void));




#endif /* EXTI_INTERFACE_H_ */
