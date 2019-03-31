/*A variable that accepts two values PIN Number & Several times per sample
 * SET_Anlog_Raw_init(0,100);
 *
 **/



#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "Reading_Analog.h"
#include "Gpio_set.h"
#include <term.h>
#include <unistd.h>
int Night_mode = 0;

int  main() {
	while (1)
	{
		
	
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	  SET_Anlog_Raw_init(0, 10);
	}
}
