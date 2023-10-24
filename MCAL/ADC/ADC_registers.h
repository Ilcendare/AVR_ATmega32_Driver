/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_registers.h
 *  Created on	: Sep 16, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_REGISTERS_H
#define MCAL_ADC_REGISTERS_H
/** ========================================================================= */



/** ========================= Defining ADC Registers ======================== */
#define ADMUX		*((volatile u8 *) 0x27)
#define ADCSRA		*((volatile u8 *) 0x26)
#define ADCH		*((volatile u8 *) 0x25)
#define ADCL		*((volatile u8 *) 0x24)
#define ADCLH		*((volatile u16 *)0x24)
#define SFIOR		*((volatile u8 *) 0x50)
/** ========================================================================= */




#endif /* MCAL_ADC_REGISTERS_H */
/** ============================== END of File ============================== */
