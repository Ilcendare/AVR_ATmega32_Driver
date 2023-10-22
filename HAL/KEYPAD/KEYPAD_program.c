/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: KEYPAD_program.c
 *  Created on	: Created on: Oct 22, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>
/** ========================================================================= */




/** =========================== Defining LCD Macros ========================= */

/** ========================================================================= */




/** ======================== Defining global variables ====================== */
u8 rows[4] = Rows_Pins;
u8 row_ports[4] = Rows_Ports;
/** ========================================================================= */




/** ===================== KEYPAD Functions Implementation =================== */
void HAL_KEYPAD_Init(void)
{
	MCAL_DIO_voidSetPinMode(COL1, Input);
	MCAL_DIO_voidSetPinMode(COL2, Input);
	MCAL_DIO_voidSetPinMode(COL3, Input);
	MCAL_DIO_voidSetPinMode(COL4, Input);

	MCAL_DIO_voidSetPinMode(ROW1, Output);
	MCAL_DIO_voidSetPinMode(ROW2, Output);
	MCAL_DIO_voidSetPinMode(ROW3, Output);
	MCAL_DIO_voidSetPinMode(ROW4, Output);
}



u8 HAL_KEYPAD_ReadData(void)
{
	u8 value = 'Q';

	MCAL_DIO_voidWritePin(row_ports[0], rows[0], High);
	MCAL_DIO_voidWritePin(row_ports[0], rows[1], High);
	MCAL_DIO_voidWritePin(row_ports[0], rows[2], High);
	MCAL_DIO_voidWritePin(row_ports[0], rows[3], High);

	for(u8 i = 0 ; i < 4 ; i++)
	{
		MCAL_DIO_voidWritePin(row_ports[i], rows[i], Low);

		_delay_ms(25);

		if(MCAL_DIO_u8ReadPin(COL1) == Low)
		{
			if(i == 0)
			{
				value = '1';
			}
			else if(i == 1)
			{
				value = '4';
			}
			else if(i == 2)
			{
				value = '7';
			}
			else if(i == 3)
			{
				value = '#';
			}
			break;
		}
		else if(MCAL_DIO_u8ReadPin(COL2) == Low)
		{
			if(i == 0)
			{
				value = '2';
			}
			else if(i == 1)
			{
				value = '5';
			}
			else if(i == 2)
			{
				value = '8';
			}
			else if(i == 3)
			{
				value = '.';
			}
			break;
		}
		else if(MCAL_DIO_u8ReadPin(COL3) == Low)
		{
			if(i == 0)
			{
				value = '3';
			}
			else if(i == 1)
			{
				value = '6';
			}
			else if(i == 2)
			{
				value = '9';
			}
			else if(i == 3)
			{
				value = '*';
			}
			break;
		}
		else if(MCAL_DIO_u8ReadPin(COL4) == Low)
		{
			if(i == 0)
			{
				value = '+';
			}
			else if(i == 1)
			{
				value = '-';
			}
			else if(i == 2)
			{
				value = '*';
			}
			else if(i == 3)
			{
				value = '/';
			}
			break;
		}

		MCAL_DIO_voidWritePin(row_ports[i], rows[i], High);
	}

	return value;
}





/** ========================================================================= */

