#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include <stdlib.h>

#ifndef DEFAULT_DEBUG_LEVEL
#define DEFAULT_DEBUG_LEVEL	5
#endif


#ifndef MODULE_NAME
#define _MODULE_NAME	""
#else
#define _MODULE_NAME	MODULE_NAME ":"
#endif

/* 1) The higher the debug_level, the less chance log information
 * 	will be printed
 * 2) LOGDEBUG*() whill disapperar if DEBUG is turned off
 */

#define LOGERROR_R(fmt, arg...) fprintf(stderr, fmt, ##arg)
#define LOGERROR(fmt, arg...) 	LOGERROR_R("[E] " _MODULE_NAME fmt,  ##arg)


#ifndef DEBUG
#define LOGDEBUG_R(fmt, arg...) 	((void)0)
#define LOGDEBUG(fmt, arg...) 		((void)0)
#define LOGDEBUG_LV(lv, fmt, arg...) 	((void)0)
#define LOGDEBUG_R_LV(lv, fmt, arg...) 	((void)0)

#else /* !DEBUG */

#define 

#define LOGDEBUG_R(fmt, arg...) 	fprintf(stderr, fmt, ##arg)
#define LOGDEBUG(fmt, arg...) 		LOGDEGBU_R("[D] " _MODULE_NAME fmt, ##arg)

#define LOGDEBUG_LV(lv, fmt, arg...) \
do { \
	if (DEFAULT_DEBUG_LEVEL >= lv) \
		LOGDEBUG(fmt , ##arg); \
} while (0)

#define LOGDEBUG_R_LV(lv, fmt, arg...) \
do { \
	if (DEFAULT_DEBUG_LEVEL >= lv) \
		LOGDEBUG_R(fmt, ##arg); \
} while (0)

#endif /* DEBUG */


#define LOGINFO_R(fmt, arg...) 		fprintf(stderr, fmt, ##arg)
#define LOGINFO(fmt, arg...) 		LOGINFO_R("[I] " _MODULE_NAME fmt, ##arg)

#define PANIC(fmt, arg...) \
	do { \
		LOGERROR(fmt, ##arg); \
		abort(); \
	} while (0)

#define ASSERT(cond, fmt, arg...) \
	do { \
		if (!(cond)) \
		PANIC(fmt, ##arg); \
	} while (0)


#endif /* !_DEBUG_H_ */
