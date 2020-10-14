#include <stdio.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "Keyboard_interface.h"
#include "Racket_interface.h"
#include "Screen_interface.h"
#include "Ball_interface.h"
#include "BingBong_interface.h"

/* ************************************************************************* */
static u32 u32LeftScore  = 0;
static u32 u32RightScore = 0;
static u32 u32Speed      = 0;
static u8  u8PlayeroneName[50];
static u8  u8PlayerTwoName[50];
/* ************************************************************************* */
#define BINGBONG_SET_SPEED(Speed)                 u32Speed = Speed
/* ************************************************************************* */

/* Local function prototypes */
static void BingBong_vUpRightRacket(void);
static void BingBong_vDownRightRacket(void);
static void BingBong_vUpLeftRacket(void);
static void BingBong_vDownLeftRacket(void);
static void BingBong_vWelcomMsgPrintRec(void);
static void BingBong_vChooseLvl(BingBongLvl_t Copy_u8Levl);
/* ************************************************************************* */

static void BingBong_vUpRightRacket(void)
{
	Racket_vChangeDirection(RACKET_STATE_UP,RACKET_RIGHT);
}

/* ************************************************************************* */

static void BingBong_vDownRightRacket(void)
{
	Racket_vChangeDirection(RACKET_STATE_DOWN,RACKET_RIGHT);
}

/* ************************************************************************* */

static void BingBong_vUpLeftRacket(void)
{
	Racket_vChangeDirection(RACKET_STATE_UP,RACKET_LEFT);
}

/* ************************************************************************* */

static void BingBong_vDownLeftRacket(void)
{
	Racket_vChangeDirection(RACKET_STATE_DOWN,RACKET_LEFT);
}

/* ************************************************************************* */

static void BingBong_vWelcomMsgPrintRec(void)
{
    u8 u8Index = 0;
    u8 u8Index_2 = 0;
    /* Draw the rectangle */
    printf("%c",REC_RIGHT_UP_EDGE);
    for(u8Index = 0; u8Index < BINGBON_REC_WIDTH-2 ; u8Index++)
    {
        printf("%c",REC_WIDTH_LINE);
    }
    printf("%c\n",REC_LEFT_UP_EDGE);
    for(u8Index = 0; u8Index < BINGBON_REC_HEIGHT ; u8Index++)
    {
        for(u8Index_2 = 0;u8Index_2 < BINGBON_REC_WIDTH; u8Index_2++)
        {
            if(u8Index_2 == BINGBON_REC_WIDTH-1 || u8Index_2 == 0)
            {
                if(u8Index != BINGBON_REC_HEIGHT-1){
                    printf("%c",REC_HEIGHT_LINE);
                }
                else if(u8Index == BINGBON_REC_HEIGHT-1)
                {
                    if(u8Index_2 != 0)
                    {
                        printf("%c",REC_RIGHT_DOWN_EDGE);
                    }
                    else
                    {
                        printf("%c",REC_LEFT_DOWN_EDGE);
                    }
                }
                else
                {
                    /* No Action */
                }
            }
            else if(u8Index == BINGBON_REC_HEIGHT-1 )
            {
                if(u8Index_2 != 0)
                {
                    printf("%c",REC_WIDTH_LINE);
                }
            }
            else
            {
                printf("%c",ERASE_SHAPE);
            }
        }
        if(u8Index != BINGBON_REC_HEIGHT-1)
        printf("\n");
    }

}

/* ************************************************************************* */

static void BingBong_vChooseLvl(BingBongLvl_t Copy_u8Levl)
{
    switch(Copy_u8Levl)
    {
    case 1:
        BINGBONG_SET_SPEED(BINGBONG_EASY_LVL_T_MS);
        printf("You chose easy level\n");
        break;
    case 2:
        BINGBONG_SET_SPEED(BINGBONG_MED_LVL_T_MS);
        printf("You chose medium level\n");
        break;
    case 3:
        BINGBONG_SET_SPEED(BINGBONG_HARD_LVL_T_MS);
        printf("You chose hard level\n");
        break;
    default:
        BINGBONG_SET_SPEED(BINGBONG_EASY_LVL_T_MS);
        printf("Invalid choice game will start as easy level\n");
        break;
    }

}

/* ************************************************************************* */
void BingBong_vInitKeyboard(void)
{
    /* Assign keys to their functions */
	KeyFunc_t RightUp;
	KeyFunc_t RightDown;
	KeyFunc_t LeftUp;
	KeyFunc_t LeftDown;

	RightUp.KEY 				= RIGHT_UP_KEY;
	RightDown.KEY				= RIGHT_DOWN_KEY;

	LeftUp.KEY 					= LEFT_UP_KEY;
	LeftDown.KEY				= LEFT_DOWN_KEY;

	RightUp.Key_CallBackPtr 	= BingBong_vUpRightRacket;
	RightDown.Key_CallBackPtr 	= BingBong_vDownRightRacket;

	LeftUp.Key_CallBackPtr 		= BingBong_vUpLeftRacket;
	LeftDown.Key_CallBackPtr 	= BingBong_vDownLeftRacket;

	Keyboard_vAssginKey(&RightUp);
	Keyboard_vAssginKey(&RightDown);
	Keyboard_vAssginKey(&LeftUp);
	Keyboard_vAssginKey(&LeftDown);
}

/* ************************************************************************* */

void BingBong_vSleep(void)
{
	/* Sleep is a windows API to slow down the loop*/
	Sleep(u32Speed);
}

/* ************************************************************************* */

void BingBong_vPrintScore(void)
{
	Screen_vGotoXY(SCORE_COORD_X,SCORE_COORD_Y);
	printf("%s score: %d, %s score: %d",u8PlayeroneName,u32LeftScore,u8PlayerTwoName,u32RightScore);
}

/* ************************************************************************* */

void BingBong_vCheckCollision(void)
{
	Racket_State Local_xRacketState = 0;
	s32 Local_s32BallCord_Y = 0;
	/* Get place of the ball */
	Ball_State BallPlace = Ball_xGetPlace(&Local_s32BallCord_Y);

	/* Check if the ball at the left edge or the right edge */
	if(BallPlace == BALL_EDGE_LEFT)
	{
		/* Check racket place */
		Local_xRacketState = Racket_xCheckPlace(RACKET_LEFT,Local_s32BallCord_Y);
		/* Check if the ball touched the racket */
		if(Local_xRacketState == RACKET_LEFT_HIT)
		{
			u32RightScore++;
		}

	}
	else if(BallPlace == BALL_EDGE_RIGHT)
	{
		/* Check racket place */
		Local_xRacketState = Racket_xCheckPlace(RACKET_RIGHT,Local_s32BallCord_Y);
		/* Check if the ball touched the racket */
		if(Local_xRacketState == RACKET_RIGHT_HIT)
		{
			u32LeftScore++;
		}
	}
	else
	{
		/* No Action */
	}
}

/* ************************************************************************* */

void BingBong_vInit(void)
{
	/* Initialize keyboard */
	BingBong_vInitKeyboard();
}

/* ************************************************************************* */

void BingBong_vWelcomeMsg(void)
{
    u8 u8Player1Name[50];
    u8 u8Player2Name[50];
    u8 u8Level =0;
    u8 u8WelMsgCoordX = WELCOME_MSG_COORD_X;
    u8 u8WelMsgCoordY = WELCOME_MSG_COORD_Y;

    /* Draw a rectangle */
    BingBong_vWelcomMsgPrintRec();

    /* Print welcome messages */
    /* Scan names of the players */
    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    printf("Enter player 1's name\n");
    u8WelMsgCoordY++;

    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    scanf(" %s",u8Player1Name);
    strcpy(u8PlayeroneName,u8Player1Name);
    u8WelMsgCoordY++;

    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    printf("Enter player 2's name\n");
    u8WelMsgCoordY++;

    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    scanf(" %s",u8Player2Name);
    strcpy(u8PlayerTwoName,u8Player2Name);
    u8WelMsgCoordY++;

    /* scan game level */
    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    printf("Enter Level:Easy 1,Med 2, Hard 3\n");
    u8WelMsgCoordY++;

    Screen_vGotoXY(u8WelMsgCoordX,u8WelMsgCoordY);
    scanf(" %d",&u8Level);
    u8WelMsgCoordY++;

    Screen_vGotoXY(u8WelMsgCoordX/2,u8WelMsgCoordY);

    /* Choose level */
    BingBong_vChooseLvl(u8Level);

    /* Wait till the user gets ready */
    Sleep(START_GAME_PAUSE_MS);
    /* Erase the screen */
    Screen_vErase();


}

/* ************************************************************************* */

void BingBong_vGameSequence(void)
{
    /* Time line before sleep */

		/* Draw the ball and start its animation */
		Ball_vUpdateWake();
		/* Check if any key has been pressed */
		Keyboard_vCheck();
		/* Draw and move the rackets */
		Racket_vMove();

		/* Sleep */
		BingBong_vSleep();

		/* Time line after sleep */

		/* Update the ball place and delete its last place */
		Ball_vUpdateSleep();
		BingBong_vCheckCollision();
		/* If any event occurd from the keyboard update Rackets */
		Racket_vUpdateCoord();

		/* Print score */
		BingBong_vPrintScore();
}

