/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: NTI_Day_1_Task_2.c
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
#define LED_RED		DIOB, PIN7
#define LED_GRN		DIOA, PIN4
#define LED_BLU		DIOA, PIN5
#define LED_YEL		DIOA, PIN6
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
		MCAL_DIO_voidWritePin(LED_RED, High);
		for(u8 i = 9; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_RED, Low);


		MCAL_DIO_voidWritePin(LED_YEL, High);
		for(u8 i = 3; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_YEL, Low);


		MCAL_DIO_voidWritePin(LED_GRN, High);
		for(u8 i = 8; i > 0; i--)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1, i);
			_delay_ms(1000);
		}
		MCAL_DIO_voidWritePin(LED_GRN, Low);
	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */

/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	MCAL_DIO_voidSetPinMode(DIOA,PIN3,Output);	// Set Common 1 as Output
	MCAL_DIO_voidSetPinMode(DIOA,PIN2,Output);	// Set Common 2 as Output
	MCAL_DIO_voidSetPinMode(DIOB,PIN5,Output);	// Set Common 3 as Output
	MCAL_DIO_voidSetPinMode(DIOB,PIN6,Output);	// Set Common 4 as Output

	MCAL_DIO_voidWritePin(DIOA,PIN3,High);
	MCAL_DIO_voidWritePin(DIOA,PIN2,High);
	MCAL_DIO_voidWritePin(DIOB,PIN5,High);
	MCAL_DIO_voidWritePin(DIOB,PIN6,High);

	/* Set all the A, B, C, and D pins as Output */
	MCAL_DIO_voidSetPinMode(DIOB, PIN0, Output); // Set A as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN1, Output); // Set B as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN2, Output); // Set C as output
	MCAL_DIO_voidSetPinMode(DIOB, PIN4, Output); // Set D as output

	MCAL_DIO_voidSetPinMode(LED_RED, Output);
	MCAL_DIO_voidSetPinMode(LED_GRN, Output);
	MCAL_DIO_voidSetPinMode(LED_BLU, Output);
	MCAL_DIO_voidSetPinMode(LED_YEL, Output);
}
/** ========================================================================= */

