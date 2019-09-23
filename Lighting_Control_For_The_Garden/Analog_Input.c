#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//#include<string.h>
#include "Gpio_set.h"
#define SYS_Analog "/sys/bus/iio/devices/iio:device0/"
#define MAX_BUF 64
#define GpioPin 20
FILE *fptr;
char value_str[7];
float value_int = 0;  
int Number_of_times_to_read = 0, Number=0;
int sum = 0;
unsigned int average = 0;
int sampling[100];
int Current_time1=0;
//unsigned int Waiting_time_new_measurement = 5;
int time_new =0;
int Standby_time;
int fd, len;
int day;
int result;
/****************************************************************
 *in_voltage_raw
 ****************************************************************/

int SET_Anlog_Raw_init(unsigned int in_voltage_raw, unsigned int Number_of_times_to_read)
{
	
	if (!time_new)
	{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		Current_time1 = tm.tm_min; 
		Current_time1  = (Current_time1 + Standby_time) % 60;
		
		time_new = 1;
	}
    		
	
	char buf[MAX_BUF];
	len = snprintf(buf, sizeof(buf), SYS_Analog "in_voltage%d_raw", in_voltage_raw);       ///   in_voltage%_raw
	fd = fopen(buf, "r");
	if (fd < 0) {
		perror("/sys/bus/iio/devices/iio:device0/in_voltage%d_raw");
		return fd;
	}
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (Current_time1 == tm.tm_min)	
	{
		
		for (average = 0; average < Number_of_times_to_read; average++)    //Number of samples, Calculate the average statistical analog complexes
			{
		
				
 				fread(value_str, 6, 6, fd);
				value_int = strtol(value_str, NULL, 0);
					
				sampling[average] = value_int;
				sum += sampling[average]; /*Calculate the average statistical analog complexes*/
				printf("CH 0 Anlog Volt: %f", value_int / 4095); /*Voltage converter*/
				printf("V \n");
				fflush(stdout);
				usleep(5000);
					rewind(fd);
				
			} 
		
		
	            	sum = sum / Number_of_times_to_read; 
		int logic_lvl = gpio_get_value(GpioPin);
	//	int i = 0;
		day = tm.tm_wday;
		switch (day)
		{
		case 0:
			if ( result = mkdir("/home/Sunday", 0777)==0)
			
			fptr = fopen("/home/Sunday/LogsForLight_Garden.txt", "a+");	
		//	fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min+0, tm.tm_sec, sum, logic_lvl, average);
			printf("Logs For Light_Garden Is print \n");
			sleep(1);		
			fclose(fptr);
		
			break;
			
		case 1:
			if (result = mkdir("/home/Monday", 0777)==0)
			{
				fptr = fopen("/home/Monday/LogsForLight_Garden.txt", "a+");		
			}
				
			else
			{
				fptr = fopen("/home/Monday/LogsForLight_Garden.txt", "a+");	
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
			
		
			break;
		case 2:
			
			if (result = mkdir("/home/Tuesda", 0777)==0)
			{
				fptr = fopen("/home/Tuesday/LogsForLight_Garden.txt", "a+");	
			}
				
			else
			{
				fptr = fopen("/home/Thursday/LogsForLight_Garden.txt", "a+");
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
			break;
		case 3:
			
			if (result = mkdir("/home/Wednesday", 0777)==0)
			{
				fptr = fopen("/home/Wednesda/LogsForLight_Garden.txt", "a+");	
			}
									
			else
			{
				fptr = fopen("/home/Wednesday/LogsForLight_Garden.txt", "a+");
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
				
			
			break;
			
		case 4:
			if (result = mkdir("/home/Thursday", 0777) == 0)
		{
			fptr = fopen("/home/Thursday/LogsForLight_Garden.txt", "a+");		
		}
				
			
			else
			{
				fptr = fopen("/home/Thursday/LogsForLight_Garden.txt", "a+");
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
			break;
			
		case 5:
		if (result = mkdir("/home/Friday", 0777)==0)
		{
			fptr = fopen(" /home/Friday/LogsForLight_Garden.txt", "a+");
		}
				
			
			else
			{
				fptr = fopen("/home/Friday/LogsForLight_Garden.txt", "a+");
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday + 1, tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
			break;
		case 6:
			if (result = mkdir("/home/Saturday",0777)==0)
		{
			fptr = fopen("/home/Saturday/LogsForLight_Garden.txt", "a+");
		}
					
			
			else
			{
				fptr = fopen("/home/Saturday/LogsForLight_Garden.txt", "a+");
				fprintf(fptr, "Daet Is:%02d-%02d-%2d Time Is:%02d:%02d:%02d|Sum is:%4d |The logical level=%1d |Number of samples:%2d \n", tm.tm_mday-1 , tm.tm_mon, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
				printf("Logs For Light_Garden Is print \n");
				sleep(1);		
				fclose(fptr);	
			}
			break;
		}
		/************************************************************************************************************************************
		* Generates a log named fptr = fopen ("/ home / debian / Desktop / LogsForLight_Garden.txt", "a"); To check the analog extensions
		*************************************************************************************************************************************/
		/*
		
		fptr = fopen("/home/LogsForLight_Garden.txt", "a+");
		//	if (fptr == NULL)
			{
				printf("Could not create file LogsForLight_Garden.txt ");   
				exit(1);             
			}
		//	int logic_lvl = gpio_get_value(GpioPin);
		//int i = 0;
	
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
		
		//fprintf(fptr, "Daet Is : %02d-%02d-%02d Time Is : %2d:%2d :%2d: | Sum is :  %4d |The logical level  %1d |Number of samples : %2d \n", tm.tm_mday+1, tm.tm_mon, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
		//printf("Logs For Light_Garden Is print \n");
		//sleep(1);		
		fclose(fptr);
			
		//	printf("Average = %d\n", sum);
	    */
		gpio_fd_close(fd);
		time_new = 0;
		return sum; //average;
	
	
	
	}
	
}

