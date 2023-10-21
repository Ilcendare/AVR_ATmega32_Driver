/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: main.c
 *  Created on	: Aug 14, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "HAL/SEVEN_SEG/SEVEN_SEG_interface.h"
/** ========================================================================= */




/** ===================== User-defined global variables ===================== */

/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
void Initialize_System(void);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	Initialize_System();

	while(1)
	{
		for(u8 i = 0; i < 10; i++)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1,i);
			_delay_ms(1000);
		}

		MCAL_DIO_voidWritePin(DIOA,PIN3,High);

		for(u8 i = 0; i < 10; i++)
		{
			HAL_SEVEN_SEG_voidDisplay(COM2,i);
			_delay_ms(1000);
		}

		MCAL_DIO_voidWritePin(DIOA,PIN2,High);

		for(u8 i = 0; i < 10; i++)
		{
			HAL_SEVEN_SEG_voidDisplay(COM3,i);
			_delay_ms(1000);
		}

		MCAL_DIO_voidWritePin(DIOB,PIN5,High);

		for(u8 i = 0; i < 10; i++)
		{
			HAL_SEVEN_SEG_voidDisplay(COM4,i);
			_delay_ms(1000);
		}

		MCAL_DIO_voidWritePin(DIOB,PIN6,High);
	}
}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */

/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	MCAL_DIO_voidSetPinMode(DIOA,PIN3,Output);
	MCAL_DIO_voidSetPinMode(DIOA,PIN2,Output);
	MCAL_DIO_voidSetPinMode(DIOB,PIN5,Output);
	MCAL_DIO_voidSetPinMode(DIOB,PIN6,Output);

	MCAL_DIO_voidWritePin(DIOA,PIN3,High);
	MCAL_DIO_voidWritePin(DIOA,PIN2,High);
	MCAL_DIO_voidWritePin(DIOB,PIN5,High);
	MCAL_DIO_voidWritePin(DIOB,PIN6,High);

	/* Set all the A, B, C, and D pins as Output */
	MCAL_DIO_voidSetPinMode(DIOB, PIN0, Output); // Set A as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN1, Output); // Set B as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN2, Output); // Set C as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN4, Output); // Set D as output
}
/** ========================================================================= */

