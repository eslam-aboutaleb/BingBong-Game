#include <stdio.h>
#include "STD_TYPES.h"
#include "Screen_interface.h"
#include "Racket_interface.h"
#include "Ball_interface.h"

/* ************************************************************************* */
/* Coordinates of starting point of the ball */
static s32 s32BallCoordX	= BALL_START_X;
static s32 s32BallCoordY	= BALL_START_Y;
/* ************************************************************************* */

void Ball_vDrawBall(void)
{
	printf("%c",BALL_SHAPE);
}

/* ************************************************************************* */

void Ball_vDeleteBall(void)
{
	printf("%c",ERASE_SHAPE);
}

/* ************************************************************************* */

void Ball_vMove(s32 Copy_s32BallIndex_X,s32 Copy_s32BallIndex_Y)
{
	Screen_vGotoXY(Copy_s32BallIndex_X,Copy_s32BallIndex_Y);
}

/* ************************************************************************* */

static void Ball_vUpdatecoord(void)
{
    /* Initialize ball speed */
	static s32 s32BallVelocity_x = BALL_INIT_VELOCITY_X;
	static s32 s32BallVelocity_y = BALL_INIT_VELOCITY_Y;

	/* Invert the direction of the ball if it hit the edges */
	if((s32BallCoordX == SCREEN_X_START_LIMIT) || (s32BallCoordX == SCREEN_X_END_LIMIT))
	{
	   /* Turn velocity variable to negative */
	   s32BallVelocity_x = -1 * s32BallVelocity_x;
	}
	if((s32BallCoordY == SCREEN_Y_START_LIMIT) || (s32BallCoordY == SCREEN_Y_END_LIMIT))
    {
	   /* Turn velocity variable to negative */
	   s32BallVelocity_y = -1 * s32BallVelocity_y;
    }

    /* Update the coordinates of the ball */
	if(!(s32BallCoordY > SCREEN_Y_END_LIMIT))
	{
		if(!(s32BallCoordY < SCREEN_Y_START_LIMIT))
        {
            s32BallCoordY	+= s32BallVelocity_y;
        }
	}
	if(!(s32BallCoordX > SCREEN_X_END_LIMIT))
	{
		if(!(s32BallCoordX < SCREEN_X_START_LIMIT))
        {
            s32BallCoordX	+= s32BallVelocity_x;
        }
	}
}

/* ************************************************************************* */

Ball_State Ball_xGetPlace(s32 *Copy_s32BallCoordY)
{
	*Copy_s32BallCoordY = s32BallCoordY;
	/* Check if the ball at any edge */
	if(s32BallCoordX == SCREEN_X_START_LIMIT)
	{
		return BALL_EDGE_LEFT;
	}
	else if(s32BallCoordX == SCREEN_X_END_LIMIT)
	{
		return BALL_EDGE_RIGHT;
	}
	else
	{
		/* No Action */
	}

	return E_NOK;
}

/* ************************************************************************* */

void Ball_vUpdateWake(void)
{
    /* Move the ball to the new coordinates */
	Ball_vMove(s32BallCoordX,s32BallCoordY);
	/* Draw the ball */
	Ball_vDrawBall();
}

/* ************************************************************************* */

void Ball_vUpdateSleep(void)
{
    /* The arguments of Move API -> The same coordinates of the last move */
	Ball_vMove(s32BallCoordX,s32BallCoordY);
	/* Delete the last ball */
	Ball_vDeleteBall();
	/* Update the coordinates of the ball */
	Ball_vUpdatecoord();
}
