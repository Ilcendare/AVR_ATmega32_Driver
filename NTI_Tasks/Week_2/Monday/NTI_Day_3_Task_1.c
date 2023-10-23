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
#include "DIO_interface.h"
#include "GINT_interface.h"
#include "EXTI_interface.h"
#include "SEVEN_SEG_interface.h"
#include <util/delay.h>
/** ========================================================================= */




/** ========================== User-defined Macros ========================== */
#define COMMON1		DIOA, PIN3
#define COMMON2		DIOA, PIN2
#define COMMON3		DIOB, PIN5
#define COMMON4		DIOB, PIN6

#define A	DIOB, PIN0
#define B	DIOB, PIN1
#define C	DIOB, PIN2
#define D	DIOB, PIN4
/** ========================================================================= */




/** ===================== User-defined global variables ===================== */
volatile u8 data_read[4] = {0};
volatile u8 counter = 0;
volatile u8 temp[3] = {1,10,100};
/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
void Initialize_System(void);
void PrintOn7Seg();
void callback_function(void);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	Initialize_System();

	while(1)
	{
		PrintOn7Seg();
	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */
void PrintOn7Seg(void)
{
	HAL_SEVEN_SEG_voidDisplay(COM1, data_read[0]);
	_delay_ms(1);
	MCAL_DIO_voidWritePin(COMMON1,High);


	HAL_SEVEN_SEG_voidDisplay(COM2, data_read[1]);
	_delay_ms(1);
	MCAL_DIO_voidWritePin(COMMON2,High);


	HAL_SEVEN_SEG_voidDisplay(COM3, data_read[2]);
	_delay_ms(1);
	MCAL_DIO_voidWritePin(COMMON3,High);


	HAL_SEVEN_SEG_voidDisplay(COM4, data_read[3]);
	_delay_ms(1);
	MCAL_DIO_voidWritePin(COMMON4,High);
}


void callback_function(void)
{
	_delay_ms(20);
	counter++;

	for(u8 i = 0; i <= 3; i++)
	{
		if(i == 0)
		{
			data_read[i] = counter;
		}
		else
		{
			data_read[i] = counter / (10 * temp[i - 1]);
		}

		data_read[i] %= 10;
	}

	if(counter > 9999)
	{
		counter = 0;
	}
}
/** ========================================================================= */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	MCAL_GINT_SetGIE();
	MCAL_EXTI_EnableINTx(INT1, callback_function);
	MCAL_EXTI_SetSenseControl(INT1, Falling_Edge);

	MCAL_DIO_voidSetPinMode(COMMON1, Output);
	MCAL_DIO_voidSetPinMode(COMMON2, Output);
	MCAL_DIO_voidSetPinMode(COMMON3, Output);
	MCAL_DIO_voidSetPinMode(COMMON4, Output);

	MCAL_DIO_voidSetPinMode(A, Output);
	MCAL_DIO_voidSetPinMode(B, Output);
	MCAL_DIO_voidSetPinMode(C, Output);
	MCAL_DIO_voidSetPinMode(D, Output);

	MCAL_DIO_voidWritePin(COMMON1, High);
	MCAL_DIO_voidWritePin(COMMON2, High);
	MCAL_DIO_voidWritePin(COMMON3, High);
	MCAL_DIO_voidWritePin(COMMON4, High);
}
/** ========================================================================= */
