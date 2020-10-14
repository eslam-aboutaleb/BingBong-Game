#include <stdio.h>
#include "STD_TYPES.h"
#include <conio.h>
#include "Keyboard_interface.h"

/* ************************************************************************* */
static u32 u32KeyIndex = 0;
static KeyFunc_t Keyboard_keys[N_KBOARD_KEYS];
/* ************************************************************************* */

void Keyboard_vAssginKey(KeyFunc_t *Key_Cnfg)
{
    /* Assign keys to their functions */
	Keyboard_keys[u32KeyIndex].KEY 				= Key_Cnfg->KEY;
	Keyboard_keys[u32KeyIndex].Key_CallBackPtr 	= Key_Cnfg->Key_CallBackPtr;
	/* Increase the index */
	u32KeyIndex++;
}

/* ************************************************************************* */

void Keyboard_vCheck(void)
{
	/* If keyboard flag is set */
	if(_kbhit())
	{
		u8 u8Index = 0;
		/* Scan the last entered key */
		u8 u8Key = _getch();

		/* Check if the key is found in assigned keys and execute its function */
		for(u8Index = 0;u8Index<=u32KeyIndex;u8Index++)
		{
			if(Keyboard_keys[u8Index].KEY == u8Key)
			{
				Keyboard_keys[u8Index].Key_CallBackPtr();
				break;
			}
		}
	}
}
