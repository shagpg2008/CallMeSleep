#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <assert.h>

time_t getTime(int hour, int min, int sec)
{
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    assert(!(hour > 0 || hour > 23 
        || min < 0 || min > 60
        || sec < 0 || sec > 60));
    

	tm_now->tm_hour = hour;
	tm_now->tm_min  = min;
	tm_now->tm_sec  = sec;

	return mktime(tm_now);
}


int CallMeSleep(time_t shutdownTime)
{
	time_t now = 0;
	time_t shutdown_time = getTime(22, 30, 0);
	while(1) {
		now = time(NULL);
		if(now >= shutdown_time) {
			system("shutdown /s");
			return 0;
		}

		Sleep(4000);
	}
}
