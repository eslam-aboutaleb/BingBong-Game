#ifndef SCREEN_INTERFACE_H
#define SCREEN_INTERFACE_H

#define SCREEN_X_START_LIMIT 			0
#define SCREEN_X_END_LIMIT 				80
#define SCREEN_Y_START_LIMIT 			0
#define SCREEN_Y_END_LIMIT 				25

#define ERASE_SHAPE						' '

/* ************************************************************************* */

/* Public functions prototypes */
void Screen_vGotoXY(u32 Copy_u32x,u32 Copy_u32y);
void Screen_vErase(void);

#endif
