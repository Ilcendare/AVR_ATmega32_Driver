/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_program.c
 *  Created on	: Sep 16, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "ADC_interface.h"
#include "ADC_registers.h"
#include "ADC_private.h"
#include "ADC_config.h"
/** ========================================================================= */




/** ======================= Defining global variables ======================= */
void (*ADC_ISR)(void) = NULL;
/** ========================================================================= */




/** ====================== ADC Functions Implementation ===================== */
void MCAL_ADC_Init(void)
{
	/* Set the ADC VREF */
	MASK(ADMUX,ADC_VREF_MASK);
	SET_REG(ADMUX,ADC_VOLTAGE_REFERENCE);

	/* Enable/Disable the ADC left adjust */
#if	(ADC_LEFT_ADJUST == 1)
	SET_BIT(ADMUX,5);
#else
	CLR_BIT(ADMUX,5);
#endif

	/* Enable/Disable the ADC Auto trigger mode */
#if (ADC_AUTO_TRIGGER_ENABLE == 1)
	/* Enable the ADC Auto trigger mode */
	SET_BIT(ADCSRA,5);

	/* Set the Auto trigger mode source */
	MASK(SFIOR,ADC_ATS_MASK);
	SET_REG(SFIOR,ADC_AUTO_TRIG_SOURCE);
#else
	CLR_BIT(ADCSRA,5);
	MASK(SFIOR,ADC_ATS_MASK);
#endif

	/* Set the ADC clock division */
	MASK(ADCSRA,ADC_CLK_MASK);
	SET_REG(ADCSRA,ADC_CLK_DIV_FACTOR);

	/* Enable the ADC */
	SET_BIT(ADCSRA,7);
}


void MCAL_ADC_Deinit(void)
{
	/* Disable the ADC */
	CLR_BIT(ADCSRA,7);

	/* Clear all ADC registers */
	ADMUX = 0x00;
	ADCSRA = 0x00;
	MASK(SFIOR,ADC_ATS_MASK);
}


void MCAL_ADC_SelectChannel(ADC_Channel_t Channel)
{
	/* Set the channel selection */
	MASK(ADMUX,ADC_CHANNEL_MASK);
	SET_REG(ADMUX,Channel);
}


void MCAL_ADC_StartConversion_PollingMode(void)
{
	/* Make sure the ADC Interrupt is disabled */
	if(GET_BIT(ADCSRA,3) == 1)
	{
		SET_BIT(ADCSRA,4);	// Clear the ADC Interrupt flag (ADIF)
		CLR_BIT(ADCSRA,3);	// Clear ADIE
		if(ADC_ISR != NULL)
		{
			ADC_ISR = NULL;
		}
	}

	/* Start the ADC conversion */
	SET_BIT(ADCSRA,6);

	/* Poll for the ADC conversion */
	while(GET_BIT(ADCSRA,6) == 0);
}


void MCAL_ADC_StartConversion_InterruptMode(void(*CallbackFunction)(void))
{
	/* Enable the ADC Interrupt */
	SET_BIT(ADCSRA,4);	// Clear the ADC Interrupt flag (ADIF)
	SET_BIT(ADCSRA,3);	// Set ADIE

	/* Set the callback function */
	if(CallbackFunction != NULL)
	{
		ADC_ISR = CallbackFunction;
	}

	/* Start the ADC conversion */
	SET_BIT(ADCSRA,6);
}


u16	MCAL_ADC_ReadConversionResult(void)
{
#if	(ADC_LEFT_ADJUST == 1)
	uint16 result;
	result = (ADCL >> 6);
	result |= (ADCH << 2);
	return result;
#else
	return ADCLH;
#endif
}
/** ========================================================================= */




/** ===================== ADC ISRs Implementation ========================== */
/* ADC Conversion Complete ISR */
void __vector_16(void)	__attribute__((signal, used));
void __vector_16(void)
{
	if(ADC_ISR != NULL)
	{
		ADC_ISR();
	}
}
/** ========================================================================= */
