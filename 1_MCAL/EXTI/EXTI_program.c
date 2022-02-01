/*
 * EXTI_program.c
 *
 *  Created on: Jan 23, 2022
 *      Author: 20111
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

/*Global pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt0Func)(void) = NULL;
void (*EXTI_pvInt1Func)(void) = NULL;
void (*EXTI_pvInt2Func)(void) = NULL;

void EXTI_voidInit0 (void) // this in PORT PD2
{
#if INT0_INITIAL_STATE == ENABLED
	/*peripheral interrupt enable for INT0 (SIE)*/
	SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
#elif  INT0_INITIAL_STATE == DISABLES
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT0);
#else
#error "wrong INT0 INITIAL_STATE option"
#endif

	/*set sense control for INT0 */
	/* for falLing edge */
#if INT0_SENSE == FALLING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);

	/* for rising edge */
#elif INT0_SENSE == RISING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);

	/* for low level */
#elif INT0_SENSE == LOW_LEVEL
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);

	/* for on change */
#elif INT0_SENSE == ON_CHANGE
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);

#else
#error "wrong INT0_SENSE configuration option"

#endif
}

void EXTI_voidInit1 (void)  // this in PORT PD3
{
#if INT1_INITIAL_STATE == ENABLED
	/*peripheral interrupt enable for INT1 (SIE)*/
	SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
#elif  INT1_INITIAL_STATE == DISABLES
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT1);
#else
#error "wrong INT1 INITIAL_STATE option"
#endif
	/*set sense control for INT1 */
#if INT1_SENSE == FALLING_EDGE
	/* for RISING edge */
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif INT1_SENSE == RISING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif INT1_SENSE == LOW_LEVEL
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif INT1_SENSE == ON_CHANGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#else
#error "wrong INT1_SENSE configuration option"

#endif
}
void EXTI_voidInit2 (void)   // this in PORT PB2
{
#if INT1_INITIAL_STATE == ENABLED
	/*peripheral interrupt enable for INT2 (SIE)*/
	SET_BIT(EXTI_GICR,EXTI_GICR_INT2);
#elif  INT2_INITIAL_STATE == DISABLES
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT2);
#else
#error "wrong INT2 INITIAL_STATE option"

#endif

	/*set sense control for INT2 */
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCSR_ISC2);

#elif INT2_SENSE == RISING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCSR_ISC2);

#else
#error "wrong INT1_SENSE configuration option"

#endif

}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Sense)
	{
	case FALLING_EDGE: SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01); CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00); break;
	case RISING_EDGE:  SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01); SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00); break;
	case LOW_LEVEL:    CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01); CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00); break;
	case ON_CHANGE:    CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01); SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00); break;
	default : Local_u8ErrorState = NOK ; break;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE: CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10); SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11); break;
	case RISING_EDGE:  SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10); SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11); break;
	case LOW_LEVEL:    CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10); CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11); break;
	case ON_CHANGE:    SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10); CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11); break;
	default : Local_u8ErrorState = NOK ; break;
	}
	return Local_u8ErrorState;

}
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE: CLR_BIT(EXTI_MCUCR,EXTI_MCUCSR_ISC2); break;
	case RISING_EDGE:  SET_BIT(EXTI_MCUCR,EXTI_MCUCSR_ISC2); break;
	default : Local_u8ErrorState = NOK ; break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int)
	{
	case EXTI_INT0: SET_BIT(EXTI_GICR,EXTI_GICR_INT0); break;
	case EXTI_INT1:	SET_BIT(EXTI_GICR,EXTI_GICR_INT1); break;
	case EXTI_INT2:	SET_BIT(EXTI_GICR,EXTI_GICR_INT2); break;
	default : Local_u8ErrorState = NOK ; break;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int)
	{
	case EXTI_INT0: CLR_BIT(EXTI_GICR,EXTI_GICR_INT0); break;
	case EXTI_INT1:	CLR_BIT(EXTI_GICR,EXTI_GICR_INT1); break;
	case EXTI_INT2:	CLR_BIT(EXTI_GICR,EXTI_GICR_INT2); break;
	default : Local_u8ErrorState = NOK ; break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt0Func != NULL )
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt1Func != NULL )
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt2Func != NULL )
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
/*ISR INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*do nothing*/
	}
}

/*ISR INT1 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*do nothing*/
	}
}

/*ISR INT2 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*do nothing*/
	}
}
