/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: NTI_Day_1_Task_3.c
 *  Created on	: Oct 21, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "HAL/SEVEN_SEG/SEVEN_SEG_interface.h"
#include "DIO_interface.h"
/** ========================================================================= */




/** ========================== User-defined Macros ========================== */
#define DCOM1	DIOA,PIN3
#define DCOM2	DIOA,PIN2
#define DCOM3	DIOB,PIN5
#define DCOM4	DIOB,PIN6
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
	u16 s = 0;
	s8 d2 = 0 , d1 = 0, d3 = 9, d4 = 9;

	while(1)
	{
		if(s == 1000)
		{
			s = 0;
			d1++;
			if(d1 > 9)
			{
				d1 = 0;
				d2++;
				if(d2 > 9)
				{
					d2 = 0;
				}
			}

			d3--;
			if(d3 < 0)
			{
				d3 = 9;
				d4--;
				if(d4 < 0)
				{
					d4 = 9;
				}
			}
		}

		/* First digit */
		HAL_SEVEN_SEG_voidDisplay(COM1, d1);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM1, High);

		/* Second digit */
		HAL_SEVEN_SEG_voidDisplay(COM2, d2);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM2, High);

		/* Third digit */
		HAL_SEVEN_SEG_voidDisplay(COM3, d3);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM3, High);

		/* Forth digit */
		HAL_SEVEN_SEG_voidDisplay(COM4, d4);
		_delay_ms(1);
		s++;
		MCAL_DIO_voidWritePin(DCOM4, High);
	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */

/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	MCAL_DIO_voidSetPinMode(DCOM1,Output);	// Set Common 1 as Output
	MCAL_DIO_voidSetPinMode(DCOM2,Output);	// Set Common 2 as Output
	MCAL_DIO_voidSetPinMode(DCOM3,Output);	// Set Common 3 as Output
	MCAL_DIO_voidSetPinMode(DCOM4,Output);	// Set Common 4 as Output

	MCAL_DIO_voidWritePin(DCOM1,High);
	MCAL_DIO_voidWritePin(DCOM2,High);
	MCAL_DIO_voidWritePin(DCOM3,High);
	MCAL_DIO_voidWritePin(DCOM4,High);

	/* Set all the A, B, C, and D pins as Output */
	MCAL_DIO_voidSetPinMode(DIOB, PIN0, Output); // Set A as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN1, Output); // Set B as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN2, Output); // Set C as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN4, Output); // Set D as output
}
/** ========================================================================= */

