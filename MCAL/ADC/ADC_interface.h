/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_interface.h
 *  Created on	: Sep 16, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_INTERFACE_H
#define MCAL_ADC_INTERFACE_H
/** ========================================================================= */




/** ======================== Defining ADC Enumeration ======================= */
typedef enum ADC_Channel_enum
{
ADC0,
ADC1,
ADC2,
ADC3,
ADC4,
ADC5,
ADC6,
ADC7
} ADC_Channel_t;
/** ========================================================================= */




/** ======================= Declaring ADC Functions ========================= */
void MCAL_ADC_Init(void);

void MCAL_ADC_Deinit(void);

void MCAL_ADC_SelectChannel(ADC_Channel_t Channel);

void MCAL_ADC_StartConversion_PollingMode(void);

void MCAL_ADC_StartConversion_InterruptMode(void(*CallbackFunction)(void));

u16	MCAL_ADC_ReadConversionResult(void);
/** ========================================================================= */




#endif /* MCAL_ADC_INTERFACE_H */
/** ============================== END of File ============================== */
