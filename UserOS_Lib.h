#ifndef USEROS_LIB_H_
#define USEROS_LIB_H_

#define WINDOWS_USER                            0
#define LINUX_USER                              1

#define CURRENT_OS                               WINDOWS_USER

#if CURRENT_OS == WINDOWS_USER
#include <windows.h>

#elif CURRENT_OS == LINUX_USER
/* Add linux Libs and APIs */
#else
#error The current os is not defined

#endif /* CURRENT_OS */


#endif /* USEROS_LIB_H_ */
