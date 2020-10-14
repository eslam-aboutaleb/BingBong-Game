#ifndef RACKET_INTERFACE
#define RACKET_INTERFACE

#define RACKET_START_INDEX				0
#define RACKET_SIZE 					8
#define RACKET_SHAPE					178

#define RACKET_STATE_DOWN				0
#define RACKET_STATE_UP					1

#define RACKET_RIGHT					0
#define RACKET_LEFT						1

#define RACKET_LEFT_HIT					(1)
#define RACKET_RIGHT_HIT				(2)

/* ************************************************************************* */

typedef unsigned char					Racket_Type;
typedef unsigned char					Racket_State;

/* ************************************************************************* */

/* Public functions prototypes */
void Rackets_vDraw(void);
void Racket_vChangeDirection(Racket_State Copy_xRocketState,Racket_Type Copy_xRacket);
Racket_State Racket_xCheckPlace(Racket_Type Copy_xRacket,u8 Copy_u8BallCord_Y);
void Racket_vMove(void);
void Racket_vUpdateCoord(void);


#endif
