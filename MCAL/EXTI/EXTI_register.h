/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: EXTI_register.h
 *  Created on	: Oct 23, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_EXTI_REGISTER_H
#define MCAL_EXTI_REGISTER_H
/** ========================================================================= */




/** ======================== Defining EXTI Registers ======================== */
#define MCUCR		*((volatile u8 *)0x55)
#define MCUCSR		*((volatile u8 *)0x54)
#define GIFR		*((volatile u8 *)0x5A)
#define GICR		*((volatile u8 *)0x5B)
#define SREG 		*((volatile u8 *)0x5F)
/** ========================================================================= */




#endif /* MCAL_EXTI_REGISTER_H */
/** ============================== END of File ============================== */
