/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: KEYPAD_interface.h
 *  Created on	: Created on: Oct 22, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef HAL_KEYPAD_INTERFACE_H
#define HAL_KEYPAD_INTERFACE_H
/** ========================================================================= */




/** ========================= Defining KEYPAD Macros ======================== */
void HAL_KEYPAD_Init(void);
u8 HAL_KEYPAD_ReadData(void);

/** ========================================================================= */




#endif /* HAL_KEYPAD_INTERFACE_H */
/** ============================== END of File ============================== */
