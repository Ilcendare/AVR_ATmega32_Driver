/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: SEVEN_SEG_interface.h
 *  Created on	: Oct 20, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef HAL_SEVEN_SEG_INTERFACE_H
#define HAL_SEVEN_SEG_INTERFACE_H
/** ========================================================================= */




/** =============== Defining enums for Common Anode Selection =============== */
typedef enum COM_enum {COM1,COM2,COM3,COM4} COM_t;
/** ========================================================================= */




/** ================== Seven Segment Function Declaration =================== */
void HAL_SEVEN_SEG_voidDisplay(COM_t Copy_COM_tCOMn,u8 Copy_u8BCDNumber);
/** ========================================================================= */




#endif /* HAL_SEVEN_SEG_INTERFACE_H */
/** ============================== END of File ============================== */
