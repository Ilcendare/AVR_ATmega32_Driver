/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: main.c
 *  Created on	: Aug 14, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "HAL/SEVEN_SEG/SEVEN_SEG_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
/** ========================================================================= */




/** ========================== User-defined Macros ========================== */

/** ========================================================================= */




/** ===================== User-defined global variables ===================== */

/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
void Initialize_System(void);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	Initialize_System();
	HAL_LCD_WriteString((u8 *)"Hello World!", 0, 0);

	while(1)
	{

	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */

/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{
	HAL_LCD_Init();
}
/** ========================================================================= */

