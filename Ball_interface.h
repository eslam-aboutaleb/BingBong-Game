#ifndef BALL_INTERFACE_H
#define BALL_INTERFACE_H

#define BALL_SHAPE						'O'
#define BALL_START_X					(SCREEN_X_END_LIMIT/2)
#define BALL_START_Y					(RACKET_SIZE/2)

#define BALL_INIT_VELOCITY_X			1
#define BALL_INIT_VELOCITY_Y			1

#define BALL_EDGE_RIGHT					(11)
#define BALL_EDGE_LEFT					(12)

/* ************************************************************************* */

typedef unsigned char 					Ball_State;

/* ************************************************************************* */
/* Public functions prototypes */
void Ball_vDrawBall(void);
void Ball_vDeleteBall(void);
void Ball_vMove(s32 Copy_s32BallIndex_X,s32 Copy_s32BallIndex_Y);
Ball_State Ball_xGetPlace(s32 *Copy_s32BallCoordY);
void Ball_vUpdateWake(void);
void Ball_vUpdateSleep(void);

#endif
