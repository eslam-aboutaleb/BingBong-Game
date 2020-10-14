#ifndef KEYBOAR_INTERFACE_H
#define KEYBOAR_INTERFACE_H

#define N_KBOARD_KEYS				30

#define RIGHT_UP_KEY 						'8'
#define RIGHT_DOWN_KEY 						'2'
#define LEFT_UP_KEY 						'w'
#define LEFT_DOWN_KEY 						's'

/* ************************************************************************* */

typedef struct{
	u8 KEY;
	void(*Key_CallBackPtr)(void);
}KeyFunc_t;

/* ************************************************************************* */

/* Public functions prototypes */
void Keyboard_vAssginKey(KeyFunc_t *Key_Cnfg);
void Keyboard_vCheck(void);
#endif
