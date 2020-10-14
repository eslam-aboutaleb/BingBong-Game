#include <stdio.h>
#include "STD_TYPES.h"
#include "Screen_interface.h"
#include "Racket_interface.h"

/* ************************************************************************* */
static s8 s8RightStartIndex	= 0;
static s8 s8LeftStartIndex	= 0;
/* ************************************************************************* */

void Rackets_vDraw(void)
{
	u8 u8Index =0;
	for(u8Index = s8LeftStartIndex;u8Index< RACKET_SIZE;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_START_LIMIT,u8Index);
		printf("%c",RACKET_SHAPE);
	}

	for(u8Index = s8RightStartIndex;u8Index< RACKET_SIZE;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_END_LIMIT,u8Index);
		printf("%c",RACKET_SHAPE);
	}
}

/* ************************************************************************* */

void Racket_vMove(void)
{
	u8 u8Index = 0;
	for(u8Index = s8LeftStartIndex;u8Index< RACKET_SIZE + s8LeftStartIndex;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_START_LIMIT,u8Index);
		printf("%c",RACKET_SHAPE);
	}

	for(u8Index = s8RightStartIndex;u8Index< RACKET_SIZE + s8RightStartIndex;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_END_LIMIT,u8Index);
		printf("%c",RACKET_SHAPE);
	}
}

/* ************************************************************************* */

void Racket_vChangeDirection(Racket_State Copy_xRocketState,Racket_Type Copy_xRacket)
{
    /* Check which racket will change the direction */
	switch(Copy_xRocketState)
	{
	    /* If the racket is going down */
		case RACKET_STATE_DOWN:
		    /* Check which racket and then if it is within the limit of screen
               go down */
			if(Copy_xRacket == RACKET_RIGHT)
			{
				if(s8RightStartIndex < SCREEN_Y_END_LIMIT)
				s8RightStartIndex++;
			}
			else if(Copy_xRacket == RACKET_LEFT)
			{
				if(s8LeftStartIndex < SCREEN_Y_END_LIMIT)
				s8LeftStartIndex++;
			}
		break;
		/* If the racket is going down */
		case RACKET_STATE_UP:
		    /* Check which racket and then if it is within the limit of screen
               go up */
			if(Copy_xRacket == RACKET_RIGHT)
			{
				if(s8RightStartIndex > SCREEN_Y_START_LIMIT)
				s8RightStartIndex--;
			}
			else if(Copy_xRacket == RACKET_LEFT)
			{
				if(s8LeftStartIndex > SCREEN_Y_START_LIMIT)
				s8LeftStartIndex--;
			}
		break;
		default:
			/* No Action */
		break;
	}
}

/* ************************************************************************* */

Racket_State Racket_xCheckPlace(Racket_Type Copy_xRacket,u8 Copy_u8BallCord_Y)
{
	s8 s8Index = 0;
	/* Choose where the index */
	switch(Copy_xRacket)
	{
		case RACKET_LEFT:
			s8Index = s8LeftStartIndex;
			break;
		case RACKET_RIGHT:
			s8Index = s8RightStartIndex;
			break;
		default:
			/* No Action */
			break;
	}

	/* Check if the ball between the limits of the rackets */
	if((s8Index <= Copy_u8BallCord_Y) &&
       (s8Index + RACKET_SIZE >= Copy_u8BallCord_Y))
	{
		/* No Action */
	}
	else
	{
		if(Copy_xRacket == RACKET_LEFT)
		{
			return RACKET_LEFT_HIT;
		}
		else if(Copy_xRacket == RACKET_RIGHT)
		{
			return RACKET_RIGHT_HIT;
		}
		else
		{
			/* No Action */
		}
	}

	return E_NOK;
}

/* ************************************************************************* */

void Racket_vUpdateCoord(void)
{
	u8 u8Index = 0;
	for(u8Index = s8LeftStartIndex;u8Index< RACKET_SIZE + s8LeftStartIndex;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_START_LIMIT,u8Index);
		printf("%c",ERASE_SHAPE);
	}

	for(u8Index = s8RightStartIndex;u8Index< RACKET_SIZE + s8RightStartIndex;u8Index++)
	{
		Screen_vGotoXY(SCREEN_X_END_LIMIT,u8Index);
		printf("%c",ERASE_SHAPE);
	}

}
