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
u8 Row_Pin[4] = ROW_PINS;
u8 Row_Port[4] = ROW_PORTS;

u8 Col_Pin[4] = COL_PINS;
u8 Col_Port[4] = COL_PORTS;

typedef enum rows_enum {row1,row2,row3,row4} row_t;
typedef enum cols_enum {col1,col2,col3,col4} col_t;
/** ========================================================================= */




/** ===================== KEYPAD Functions Implementation =================== */
void HAL_KEYPAD_Init(void)
{
	MCAL_DIO_voidSetPinMode(Col_Port[col1], Col_Pin[col1], Input);
	MCAL_DIO_voidSetPinMode(Col_Port[col2], Col_Pin[col2], Input);
	MCAL_DIO_voidSetPinMode(Col_Port[col3], Col_Pin[col3], Input);
	MCAL_DIO_voidSetPinMode(Col_Port[col4], Col_Pin[col4], Input);

	MCAL_DIO_voidSetPinMode(Row_Port[row1], Row_Pin[row1], Output);
	MCAL_DIO_voidSetPinMode(Row_Port[row2], Row_Pin[row2], Output);
	MCAL_DIO_voidSetPinMode(Row_Port[row3], Row_Pin[row3], Output);
	MCAL_DIO_voidSetPinMode(Row_Port[row4], Row_Pin[row4], Output);
}



u8 HAL_KEYPAD_ReadData(void)
{
	u8 value = 'Q';

	MCAL_DIO_voidWritePin(Row_Port[row1], Row_Pin[row1], High);
	MCAL_DIO_voidWritePin(Row_Port[row2], Row_Pin[row2], High);
	MCAL_DIO_voidWritePin(Row_Port[row3], Row_Pin[row3], High);
	MCAL_DIO_voidWritePin(Row_Port[row4], Row_Pin[row4], High);

	for(row_t i = row1 ; i <= row4 ; i++)
	{
		MCAL_DIO_voidWritePin(Row_Port[i], Row_Pin[i], Low);

		_delay_ms(25);

		if(MCAL_DIO_u8ReadPin(Col_Port[col1], Col_Pin[col1]) == Low)
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
		else if(MCAL_DIO_u8ReadPin(Col_Port[col2], Col_Pin[col2]) == Low)
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
		else if(MCAL_DIO_u8ReadPin(Col_Port[col3], Col_Pin[col3]) == Low)
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
		else if(MCAL_DIO_u8ReadPin(Col_Port[col4], Col_Pin[col4]) == Low)
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

		MCAL_DIO_voidWritePin(Row_Port[i], Row_Pin[i], High);
	}

	return value;
}





/** ========================================================================= */

