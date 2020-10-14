/* ************************************************************ */
/* Author: Eslam Ehab Aboutaleb									*/
/* Date	 : 13/10/2020                                           */
/* ************************************************************ */

#include <stdio.h>
#include "STD_TYPES.h"
#include "Racket_interface.h"
#include "Ball_interface.h"
#include "BingBong_interface.h"
#include "Keyboard_interface.h"

/* Bing bong game base on C programing language:
    Right racket keys: 8 and 2
    Left racket keys : w and s

    the game have three levels every level is faster than the previous.
    Games levels: Easy and medium and hard.
    To adjust keyboard keys check BingBong_program.c as it the program
    manger.

    Game start:
    1- Enter names of the players.
    2- Enter level of the game (if you chose invalid choice the game
                                automatically start at easy level)
    3- Enjoy the game.

    Tips:
    Try to catch the ball with the racket if you missed it the other player
    will win a point
*/

void main()
{
    /* Welcome messages */
    BingBong_vWelcomeMsg();
    /* Initialize the game */
	BingBong_vInit();
	while(1)
	{
	    /* Start the game */
	    BingBong_vGameSequence();
	}
}
