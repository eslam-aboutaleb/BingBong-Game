#ifndef BINGBONG_INTERFACE_H
#define BINGBONG_INTERFACE_H

/* position of score */
#define SCORE_COORD_X				    	    (SCREEN_X_END_LIMIT/2)
#define SCORE_COORD_Y				    	    (SCREEN_Y_END_LIMIT+2)

/* Levels macros */
#define BINGBONG_EASY_LVL_T_MS				    100
#define BINGBONG_MED_LVL_T_MS				    60
#define BINGBONG_HARD_LVL_T_MS				    30

/* Time macros */
#define HIT_PAUSE_MS                            1000
#define START_GAME_PAUSE_MS                     1000

/* Rectangle macros */
#define BINGBON_REC_WIDTH                       50
#define BINGBON_REC_HEIGHT                      15

#define REC_RIGHT_UP_EDGE                      201
#define REC_LEFT_UP_EDGE                       187
#define REC_RIGHT_DOWN_EDGE                    188
#define REC_LEFT_DOWN_EDGE                     200
#define REC_WIDTH_LINE                         205
#define REC_HEIGHT_LINE                        186

/* Welcome messages macros */
#define WELCOME_MSG_COORD_X                    10
#define WELCOME_MSG_COORD_Y                    1


#if CURRENT_OS == WINDOWS_USER
#define SYS_DELAY(DelayMs)                     Sleep(DelayMs)

#elif CURRENT_OS == LINUX_USER
    /* Add linux Libs and APIs */

#else
#error The current os is not defined

#endif /* CURRENT_OS */

/* ************************************************************************* */
typedef unsigned char                          BingBongLvl_t;
/* ************************************************************************* */
/* Public functions prototypes */
void BingBong_vInit(void);
void BingBong_vCheckCollision(void);
void BingBong_vPrintScore(void);
void BingBong_vSleep(void);
void BingBong_vWelcomeMsg(void);
void BingBong_vGameSequence(void);
#endif
