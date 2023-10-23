/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: EXTI_interface.h
 *  Created on	: Oct 23, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_EXTI_INTERFACE_H
#define MCAL_EXTI_INTERFACE_H
/** ========================================================================= */




/** ======================= Defining EXTI enumeration ======================= */
typedef enum INTx_enum {
	INT0,
	INT1,
	INT2
} INTx_type;


typedef enum INTSense_enum {
	Low_Level,
	Logical_Change,
	Falling_Edge,
	Rising_Edge
} INTx_sense;
/** ========================================================================= */




/** ======================= Declaring EXTI Functions ======================== */
/* Enable the External Interrupt 0, 1, or 2 */
void MCAL_EXTI_EnableINTx(INTx_type INT, void(*CallbackFunction)(void));


/* Disable the External Interrupt 0, 1, or 2 */
void MCAL_EXTI_DisableINTx(INTx_type INT);


/*
 * If the external interrupt in enabled, decide when the interrupt should
 * happen.
 */
void MCAL_EXTI_SetSenseControl(INTx_type INT, INTx_sense sense);
/** ========================================================================= */




#endif /* MCAL_EXTI_INTERFACE_H */
/** ============================== END of File ============================== */
