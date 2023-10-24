/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_private.h
 *  Created on	: Oct 24, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_PRIVATE_H
#define MCAL_ADC_PRIVATE_H
/** ========================================================================= */



/** ==================== Defining ADC Configuration Macros ================== */
/* ADC Voltage Reference Configuration Macros */
#define ADC_VREF_MASK				0b00111111
#define ADC_VREF_AREF				0b00000000
#define ADC_VREF_AVCC				0b01000000
#define ADC_VREF_INTERNAL			0b11000000

/* ADC Auto Trigger Mode Configuration Macros */
#define ADC_ATS_MASK				0b00011111
#define ADC_ATS_FREE_RUNNING		0b00000000
#define	ADC_ATS_ANALOG_COMPARATOR	0b00100000
#define ADC_ATS_EXTI0				0b01000000
#define ADC_ATS_TIM0_COMP			0b01100000
#define ADC_ATS_TIM0_OFV			0b10000000
#define ADC_ATS_TIM1_COMP_B			0b10100000
#define ADC_ATS_TIM1_OVF			0b11000000
#define	ADC_ATS_TIM1_IC				0b11100000

/* ADC Clock Prescaler Configuration Macros */
#define ADC_CLK_MASK				0b11111000
#define ADC_CLK_DIV_2				0b00000001
#define ADC_CLK_DIV_4				0b00000010
#define ADC_CLK_DIV_8				0b00000011
#define ADC_CLK_DIV_16				0b00000100
#define ADC_CLK_DIV_32				0b00000101
#define ADC_CLK_DIV_64				0b00000110
#define ADC_CLK_DIV_128				0b00000111

#define ADC_CHANNEL_MASK			0b11100000
/** ========================================================================= */




#endif /* MCAL_ADC_PRIVATE_H */
/** ============================== END of File ============================== */
