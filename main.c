/** ========================= The file information ========================== */
/**
 *  Project     : AVR_ATmega32_Driver
 *  File name   : main.c
 *  Created on  : Aug 14, 2023
 *  Author      : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "HAL/SEVEN_SEG/SEVEN_SEG_interface.h"
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

	while(1)
	{
		for(u8 i = 0; i < 10; i++)
		{
			HAL_SEVEN_SEG_voidDisplay(COM1,i);
			_delay_ms(1000);
		}
	}
}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */

/** ========================================================================== */




/**   This function contains all the initialization required for the system   */
void Initialize_System(void)
{

}
/** ========================================================================= */

