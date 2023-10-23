/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: SEVEN_SEG_program.h
 *  Created on	: Oct 20, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"
#include "DIO_interface.h"
/** ========================================================================= */




/** ================ Seven Segment Functions Implementation ================= */
void HAL_SEVEN_SEG_voidDisplay(COM_t Copy_COM_tCOMn, u8 Copy_u8BCDNumber)
{
	/* Switch for the COMMON Anode selected to turn on */
	switch(Copy_COM_tCOMn)
	{
		case COM1:
			MCAL_DIO_voidWritePin(COMMON1,Low);
			break;
		case COM2:
			MCAL_DIO_voidWritePin(COMMON2,Low);
			break;
		case COM3:
			MCAL_DIO_voidWritePin(COMMON3,Low);
			break;
		case COM4:
			MCAL_DIO_voidWritePin(COMMON4,Low);
			break;
		default:
			break;
	}

	/* Assign the A, B, C, and D pins to the given BCD number */
	MCAL_DIO_voidWritePin(A, GET_BIT(Copy_u8BCDNumber,0));
	MCAL_DIO_voidWritePin(B, GET_BIT(Copy_u8BCDNumber,1));
	MCAL_DIO_voidWritePin(C, GET_BIT(Copy_u8BCDNumber,2));
	MCAL_DIO_voidWritePin(D, GET_BIT(Copy_u8BCDNumber,3));
}
/** ========================================================================= */
