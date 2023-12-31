/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: KEYPAD_config.h
 *  Created on	: Created on: Oct 22, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef HAL_KEYPAD_CONFIG_H
#define HAL_KEYPAD_CONFIG_H
/** ========================================================================= */




/** ============================= Configuration ============================= */
/* Rows order:    {row1 , row2, row3, row4} */
#define ROW_PINS	{PIN5,PIN4,PIN3,PIN2}
#define ROW_PORTS	{DIOC,DIOC,DIOC,DIOC}

/* Columns order: {col1 , col2, col3, col4} */
#define COL_PINS	{PIN7,PIN6,PIN5,PIN3}
#define COL_PORTS	{DIOD,DIOD,DIOD,DIOD}
/** ========================================================================= */




#endif /* HAL_KEYPAD_CONFIG_H */
/** ============================== END of File ============================== */
