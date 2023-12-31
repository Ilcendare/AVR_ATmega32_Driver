/** ========================= The file information ========================== */
/**
 *  Project      : AVR_ATmega32_Driver
 * 	File name    : DIO_registers.h
 *  Created on   : Aug 12, 2023
 *  Author       : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_DIO_REGISTERS_H
#define MCAL_DIO_REGISTERS_H
/** ========================================================================= */




/** ========================= Defining DIO Registers ======================== */
#define PORTA 	*((volatile u8 *)0x3B)
#define DDRA 	*((volatile u8 *)0x3A)
#define PINA 	*((volatile u8 *)0x39)

#define PORTB	*((volatile u8 *)0x38)
#define DDRB 	*((volatile u8 *)0x37)
#define PINB	*((volatile u8 *)0x36)

#define PORTC 	*((volatile u8 *)0x35)
#define DDRC 	*((volatile u8 *)0x34)
#define PINC 	*((volatile u8 *)0x33)

#define PORTD	*((volatile u8 *)0x32)
#define DDRD 	*((volatile u8 *)0x31)
#define PIND 	*((volatile u8 *)0x30)
/** ========================================================================= */




#endif /* MCAL_DIO_REGISTERS_H */
/** ============================== END of File ============================== */
