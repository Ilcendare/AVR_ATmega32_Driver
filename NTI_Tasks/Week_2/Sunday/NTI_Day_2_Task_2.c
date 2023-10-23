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
#include "SEVEN_SEG_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "DIO_interface.h"
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
u8 data_read[4] = {0};
/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
void Initialize_System(void);
void PrintOnLCD(u8 data);
void PrintOn7Seg();
void Backspace(void);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	Initialize_System();
	u8 Data, i = 0, j = 0;

	while(1)
	{
		_delay_ms(20);
		Data = HAL_KEYPAD_ReadData();
//		if(Data >= '0' && Data <= '9')
//		{
//			for(u8 j = 0; j < 3; j++)
//			{
//				data_read[j] = data_read[j+1];
//			}
//			data_read[3] = Data - 48;
//			while(HAL_KEYPAD_ReadData() != 'Q');
//		}
//		PrintOn7Seg();


		if(Data >= '0' && Data <= '9')
		{
			switch(Data)
			{
			case '0':
				if(20 - j >= 7)
				{
					HAL_LCD_WriteString((u8 *)"Mahmoud", i, j);
					j += 7;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Mahmoud", i, j);
					j += 7;
				}
				break;
			case '1':
				if(20 - j >= 6)
				{
					HAL_LCD_WriteString((u8 *)"Khaled", i, j);
					j += 6;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Khaled", i, j);
					j += 6;
				}
				break;
			case '2':
				if(20 - j >= 5)
				{
					HAL_LCD_WriteString((u8 *)"Ahmed", i, j);
					j += 5;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Ahmed", i, j);
					j += 5;
				}
				break;
			case '3':
				if(20 - j >= 8)
				{
					HAL_LCD_WriteString((u8 *)"Mohammed", i, j);
					j += 8;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Mohammed", i, j);
					j += 8;
				}
				break;
			case '4':
				if(20 - j >= 5)
				{
					HAL_LCD_WriteString((u8 *)"Qasem", i, j);
					j += 5;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Qasem", i, j);
					j += 5;
				}
				break;
			case '5':
				if(20 - j >= 4)
				{
					HAL_LCD_WriteString((u8 *)"Omar", i, j);
					j += 4;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Omar", i, j);
					j += 4;
				}
				break;
			case '6':
				if(20 - j >= 5)
				{
					HAL_LCD_WriteString((u8 *)"Ayoub", i, j);
					j += 5;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Ayoub", i, j);
					j += 5;
				}
				break;
			case '7':
				if(20 - j >= 5)
				{
					HAL_LCD_WriteString((u8 *)"Hamed", i, j);
					j += 5;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Hamed", i, j);
					j += 5;
				}
				break;
			case '8':
				if(20 - j >= 4)
				{
					HAL_LCD_WriteString((u8 *)"Adam", i, j);
					j += 4;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Adam", i, j);
					j += 4;
				}
				break;
			case '9':
				if(20 - j >= 6)
				{
					HAL_LCD_WriteString((u8 *)"Nasser", i, j);
					j += 6;
					if(j > 19)
					{
						j = 0;
						i++;
						if(i > 3)
						{
							i = 0;
						}
					}
				}
				else
				{
					j = 0;
					i++;
					if(i > 3)
					{
						i = 0;
					}
					HAL_LCD_WriteString((u8 *)"Nasser", i, j);
					j += 6;
				}
				break;
			}
		}
		else if(Data == '.')
		{
			Backspace();
		}
		else if(Data == '#')
		{
			CLR_DISPLAY;
			HAL_LCD_ChangePos(0, 0);
			j = 0;
			i = 0;
		}
		while(HAL_KEYPAD_ReadData() != 'Q');

	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */
void Backspace(void)
{
	DIR_TO_LEFT;
	SHIFT_CURSOR_TO_LEFT;
	HAL_LCD_WriteData(' ');
	SHIFT_CURSOR_TO_RIGHT;
	DIR_TO_RIGHT;
	while(HAL_KEYPAD_ReadData() != 'Q');
}


void PrintOnLCD(u8 data)
{
	if(data != 'Q') HAL_LCD_WriteData(data);
	while(HAL_KEYPAD_ReadData() != 'Q');
}


void PrintOn7Seg()
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
/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	HAL_LCD_Init();
	HAL_KEYPAD_Init();

//	MCAL_DIO_voidSetPinMode(COMMON1, Output);
//	MCAL_DIO_voidSetPinMode(COMMON2, Output);
//	MCAL_DIO_voidSetPinMode(COMMON3, Output);
//	MCAL_DIO_voidSetPinMode(COMMON4, Output);
//
//	MCAL_DIO_voidSetPinMode(A, Output);
//	MCAL_DIO_voidSetPinMode(B, Output);
//	MCAL_DIO_voidSetPinMode(C, Output);
//	MCAL_DIO_voidSetPinMode(D, Output);
//
//	MCAL_DIO_voidWritePin(COMMON1, High);
//	MCAL_DIO_voidWritePin(COMMON2, High);
//	MCAL_DIO_voidWritePin(COMMON3, High);
//	MCAL_DIO_voidWritePin(COMMON4, High);
}
/** ========================================================================= */
