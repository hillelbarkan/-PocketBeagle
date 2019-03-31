#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "Reading_Analog.h"
#include "Gpio_set.h"
#include <signal.h>
int Current_time;
int Screen = 0;

void sigintHandler(int sig_num) 
{ 
	/* Reset handler to catch SIGINT next time. 
	   Refer http://en.cppreference.com/w/c/program/signal */
	//signal(SIGTERM, gpio_set_value_0(20)); 
	printf("\n terminated using Ctrl+C \n"); 
	fflush(stdout); 
} 

void Clear_Screen()
{
	printf("\033[H\033[J\n\r");
}
int main(int argc , char *argv[])
{
	signal(SIGTERM, gpio_set_value_0(20));
	printf("Enter standby time between analogue radiation and valuesy from 1 to 60 \n ");
	
	scanf("%d", &Standby_time);
	printf("Time Standby_time : %d\n", Standby_time);
	//Current_time = str1;
	gpio_set_active_low(20, 1);
	gpio_set_dir(20, 1);
	gpio_set_value_0(20);
	fflush(stdout);
	while (1)
	{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		printf("Time is : %d:%d:%d\n\r", tm.tm_hour, tm.tm_min, tm.tm_sec);
		
	//	Screen++;
		/*if (Screen == 2)
		{
			Clear_Screen();
			Screen = 0;
		}*/
		sleep(1);
		//time_t t = time(NULL);
		//struct tm tm = *localtime(&t);
	//	printf("Time is : %d-%d-%d \n %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		//printf("Time is : %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	//	printf("\033[H\033[J");
		
		//fflush(stdout);		
		//int myt = tm.tm_hour;
		/****************************************************************
		* Set ON The light in the garden works Night mode\n Logic = "0"
		****************************************************************/
		if ((tm.tm_hour <= 5 && tm.tm_hour >= 0) || (tm.tm_hour >= 17 && tm.tm_hour <= 23))
		{
			printf("Light is ON Night mode :  %d \n\r ", gpio_get_value(20));
			SET_Anlog_Raw_init(0, 20);
			printf("Sum is :  %d \n\r ", sum);
			if (sum < 2000)
			{
				if (!gpio_get_value(20))   /*provide writing gpio mode more than one time*/
				{
					gpio_set_value_1(20);
					printf("Light is ON :  %d \n\r", gpio_get_value(20));
					
				}
			}
		}
	
		/***********************************************************************
		*  Set OFF Day mode The light in the garden does not work Logic = "1"
		************************************************************************/	
		
		if (tm.tm_hour >= 6 && tm.tm_hour <= 17)
		{
			SET_Anlog_Raw_init(0, 20);
			printf("Sum is :  %d \n\r ", sum);
			//system("cls");
			printf("Light is OFF Day mode :  %d \n\r ", gpio_get_value(20));
			if (sum > 750)
			{
			
				if (gpio_get_value(20)) /*provide writing gpio mode more than one timeq*/
				{
					gpio_set_value_0(20);
					printf("Light is OFF :  %d \n\r", gpio_get_value(20));
					
				}
			}
						
		}
		
		
	}
	
}