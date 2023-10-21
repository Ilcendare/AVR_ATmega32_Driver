/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 *  File name	: SEVEN_SEG_program.h
 *  Created on	: Oct 20, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "SEVEN_SEG_interface.h"
#include "DIO_interface.h"
/** ========================================================================= */




/** ================ Seven Segment Functions Implementation ================= */
void HAL_SEVEN_SEG_voidDisplay(COM_t Copy_COM_tCOMn, u8 Copy_u8BCDNumber)
{
	/* Switch for the COMMON Anode selected to turn on */
	switch(Copy_COM_tCOMn)
	{
		case COM1:
			MCAL_DIO_voidWritePin(DIOA,PIN3,Low);
			break;
		case COM2:
			MCAL_DIO_voidWritePin(DIOA,PIN2,Low);
			break;
		case COM3:
			MCAL_DIO_voidWritePin(DIOB,PIN5,Low);
			break;
		case COM4:
			MCAL_DIO_voidWritePin(DIOB,PIN6,Low);
			break;
		default:
			break;
	}

	/* Assign the A, B, C, and D pins to the given BCD number */
	MCAL_DIO_voidWritePin(DIOB, PIN0, GET_BIT(Copy_u8BCDNumber,0)); // A
	MCAL_DIO_voidWritePin(DIOB, PIN1, GET_BIT(Copy_u8BCDNumber,1)); // B
	MCAL_DIO_voidWritePin(DIOB, PIN2, GET_BIT(Copy_u8BCDNumber,2)); // C
	MCAL_DIO_voidWritePin(DIOB, PIN4, GET_BIT(Copy_u8BCDNumber,3)); // D
}
/** ========================================================================= */
