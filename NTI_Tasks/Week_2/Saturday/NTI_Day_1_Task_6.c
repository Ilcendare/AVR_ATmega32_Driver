/** ========================= The file information ========================== */
/**
 *  Project		: Binary Search Algorithm
 * 	File name	: NTI_Day_1_Task_6.c
 *  Created on	: Oct 21, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include <stdio.h>
/** ========================================================================= */




/** ========================== User-defined Macros ========================== */

/** ========================================================================= */




/** ===================== User-defined global variables ===================== */

/** ========================================================================= */




/** ======================== Functions prototypes =========================== */
int binary_search(int array[], int size, int val);
/** ========================================================================= */




/** ========================= The main function ============================= */
int main(void)
{
	int arr[12] = {1,3,6,7,9,12,13,15,17,20,21,25};
	int result = binary_search(arr, 12, 25);
	if(result == -1)
	{
		printf("The value is not found in the array.");
	}
	else
	{
		printf("The value is found in index of %d.",result);
	}

}
/** ========================================================================= */




/** ============== Callback & Normal functions implementation =============== */
int binary_search(int array[], int size, int val)
{
	int ReturnValue = -1, str, end, mid;
	str = 0;
	end = size - 1;
	while(str <= end)
	{
		mid = (str + end) / 2;
		if(array[mid] < val)
		{
			str = mid + 1;
		}
		else if(array[mid] > val)
		{
			end = mid - 1;
		}
		else
		{
			ReturnValue = mid;
			break;
		}
	}
	return ReturnValue;
	
}
/** ========================================================================== */