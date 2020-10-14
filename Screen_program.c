#include <stdio.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "Screen_interface.h"

/* ************************************************************************* */

void Screen_vGotoXY(u32 Copy_u32x,u32 Copy_u32y)
{
    /* Initialize the coordinates of the screen */
	COORD coord;
	coord.X = Copy_u32x;
	coord.Y = Copy_u32y;
	/* Get the console handle */
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	/* set the cursor position using the console handle and the initialized coordinates */
	SetConsoleCursorPosition(consoleHandle,coord);
}


void Screen_vErase(void)
{
    u8 u8Index   = 0;
    u8 u8Index_2 = 0;
    for(u8Index = 0; u8Index < SCREEN_Y_END_LIMIT ; u8Index++)
    {
        for(u8Index_2 = 0;u8Index_2 <= SCREEN_X_END_LIMIT; u8Index_2++)
        {
            Screen_vGotoXY(u8Index_2,u8Index);
            printf(" ");
        }
    }
}
