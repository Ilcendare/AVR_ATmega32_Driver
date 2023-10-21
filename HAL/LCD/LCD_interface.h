/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef HAL_LCD_INTERFACE_H
#define HAL_LCD_INTERFACE_H


#define LCD_16x2 	(0)
#define LCD_40x2 	(1)


#if  LCD_16x2 == 1
	#define COL_MAX 16
	#define ROW_MAX 2
#elif LCD_40x2 == 1
	#define COL_MAX 40
	#define ROW_MAX 2
#endif


#define CLR_DISPLAY 					HAL_LCD_SendCommand(0x01)
#define HOME_POS						HAL_LCD_SendCommand(0x02)
#define DIR_TO_RIGHT					HAL_LCD_SendCommand(0x06)
#define DIR_TO_LEFT						HAL_LCD_SendCommand(0x04)
//#define SHIFT_DISPLAY_ALONE_TO_LEFT 	HAL_LCD_SendCommand(0x07)
//#define SHIFT_DISPLAY_ALONE_TO_RIGHT 	HAL_LCD_SendCommand(0x05)
#define DISPLAY_ON						HAL_LCD_SendCommand(0x0C)
#define DISPLAY_OFF						HAL_LCD_SendCommand(0x08)
#define SHIFT_CURSOR_TO_LEFT			HAL_LCD_SendCommand(0x10)
#define SHIFT_CURSOR_TO_RIGHT			HAL_LCD_SendCommand(0x14)
#define SHIFT_DISPLAY_TO_LEFT 			HAL_LCD_SendCommand(0x18)
#define SHIFT_DISPLAY_TO_RIGHT 			HAL_LCD_SendCommand(0x1C)


void HAL_LCD_Init();
void HAL_LCD_SendCommand(u8 cmd);
void HAL_LCD_WriteData(u8 ch);
void HAL_LCD_WriteString(u8 *string,u8 row, u8 col);
void HAL_LCD_ChangePos(u8 row, u8 col);
void HAL_LCD_AddPattern(u8 *Pattern, u8 CGRAM_index);

#endif /* HAL_LCD_INTERFACE_H */
