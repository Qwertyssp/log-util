/*-------------------------------------------------------------------------
    > File Name :	 test.c
    > Author :		shang
    > Mail :		shangshipei@gmail.com 
    > Description :	shang 
    > Created Time :	2017年01月10日 星期二 14时59分54秒
    > Rev :		0.1
 ------------------------------------------------------------------------*/
#define MODULE_NAME	"test"

#include "debug.h"

#define DEBUG
#define DEBUG_LEVEL	5

int test(void)
{
	int i ;
	for (i = 0; i < 3; i++) {
		LOGERROR_R("logerror_r %d\n", i);
		LOGERROR("logerror %d\n", i);
		LOGDEBUG_R("logdebug_r %d\n", i);
		LOGDEBUG("logdebug %d\n", i);
		LOGDEBUG_LV(DEBUG_LEVEL, "logdebug_lv %d\n", i);
		LOGDEBUG_R_LV(DEBUG_LEVEL, "logdebug_lv %d\n", i);
		LOGINFO_R("loginfo_r %d\n", i);
		LOGINFO("loginfo %d\n", i);
	}
	ASSERT( i >  3, "assert %d\n", i); 
	return 0;
}

int main(void)
{
	printf("main begin\n");
	test();
	printf("main end\n");
}
