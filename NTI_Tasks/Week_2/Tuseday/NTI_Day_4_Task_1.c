/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 *  File name	        : main.c
 *  Created on	        : Oct 24, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include <stdio.h>
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "GINT_interface.h"
#include "EXTI_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
/** ========================================================================= */




/** ========================== User-defined Macros ========================== */

/** ========================================================================= */




/** ===================== User-defined global variables ===================== */
u32 result = 0, lastResult = 0;
char read[10];
/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
void Initialize_System(void);
u32 map(u32 x, u32 x1, u32 x2, u32 y1, u32 y2);
void GetADCResult(void);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	Initialize_System();
	HAL_LCD_WriteString((u8*)"Resistor value:", 0, 0);
	MCAL_ADC_StartConversion_InterruptMode(GetADCResult);

	while(1)
	{

	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */
void GetADCResult(void)
{
	result = MCAL_ADC_ReadConversionResult();
	result = map(result, 0, 1023, 2500, 5000);

	if(result != lastResult){
		sprintf(read,"%ld",result);
		HAL_LCD_WriteString((u8*)read, 1, 0);
		lastResult = result;
	}
}

u32 map(u32 x, u32 x1, u32 x2, u32 y1, u32 y2)
{
	return (((x - x1) * (y2 - y1) / (x2 - x1)) + y1);
}
/** ========================================================================= */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	MCAL_GINT_SetGIE();
	MCAL_ADC_Init();
	MCAL_ADC_SelectChannel(ADC1);
	HAL_LCD_Init();
	MCAL_EXTI_EnableINTx(INT0, NULL);
	MCAL_EXTI_SetSenseControl(INT0, Rising_Edge);
}
/** ========================================================================= */
