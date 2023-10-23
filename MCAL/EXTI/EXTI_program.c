/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: EXTI_program.h
 *  Created on	: Oct 23, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
/** ========================================================================= */




/** ========================= EXTI Global variables ========================= */
void (*INT0fptr)(void);
void (*INT1fptr)(void);
void (*INT2fptr)(void);
/** ========================================================================= */




/** =================== EXTI Functions Implementation ======================= */
/* Enable the External Interrupt 0, 1, or 2 */
void MCAL_EXTI_EnableINTx(INTx_type INT, void(*CallbackFunction)(void))
{
	if(INT == INT0)
	{
		SET_BIT(GICR,6);	//Bit 6 -> INT0

		if(CallbackFunction!=NULL)
		{
			INT0fptr = CallbackFunction;
		}
	}
	else if(INT == INT1)
	{
		SET_BIT(GICR,7);	//Bit 7 -> INT1

		if(CallbackFunction!=NULL)
		{
			INT1fptr = CallbackFunction;
		}
	}
	else if(INT == INT2)
	{
		SET_BIT(GICR,5);	//Bit 5 -> INT2

		if(CallbackFunction!=NULL)
		{
			INT2fptr = CallbackFunction;
		}
	}
	else
	{// Error

	}
}


/* Disable the External Interrupt 0, 1, or 2 */
void MCAL_EXTI_DisableINTx(INTx_type INT)
{
	if(INT == INT0)
	{
		CLR_BIT(GICR,6);	//Bit 6 -> INT0
		INT0fptr = NULL;
	}
	else if(INT == INT1)
	{
		CLR_BIT(GICR,7);	//Bit 7 -> INT1
		INT1fptr = NULL;
	}
	else if(INT == INT2)
	{
		CLR_BIT(GICR,5);	//Bit 5 -> INT2
		INT2fptr = NULL;
	}
	else
	{
		// Error
	}
}


/*
 * If the external interrupt in enabled, decide when the interrupt should
 * happen.
 */
void MCAL_EXTI_SetSenseControl(INTx_type INT, INTx_sense sense)
{

	if(INT == INT0)
	{
		if(sense == Low_Level)
		{
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(sense == Logical_Change)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(sense == Falling_Edge)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(sense == Rising_Edge)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
	}
	else if(INT == INT1)
	{
		if(sense == Low_Level)
		{
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(sense == Logical_Change)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(sense == Falling_Edge)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(sense == Rising_Edge)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
	}
	else if(INT == INT2)
	{
		if(sense == Falling_Edge)
		{
			CLR_BIT(MCUCSR,6);
		}
		else if(sense == Rising_Edge)
		{
			SET_BIT(MCUCSR,6);
		}
	}
	else
	{
		// Error
	}
}
/** ========================================================================= */




/** ===================== EXTI ISRs Implementation ========================== */
/* INT0 ISR Implementation */
void __vector_1(void) __attribute__((signal, used));
void __vector_1(void)
{
	if(INT0fptr != NULL)
	{
		INT0fptr();
	}
}


/* INT1 ISR Implementation */
void __vector_2(void) __attribute__((signal, used));
void __vector_2(void)	//INT1 ISR
{
	if(INT1fptr != NULL)
	{
		INT1fptr();
	}
}


/* INT2 ISR Implementation */
void __vector_3(void) __attribute__((signal, used));
void __vector_3(void)	//INT2 ISR
{
	if(INT2fptr != NULL)
	{
		INT2fptr();
	}
}
/** ========================================================================= */
