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
		/************************************************************************************************************************************
		* Generates a log named fptr = fopen ("/ home / debian / Desktop / LogsForLight_Garden.txt", "a"); To check the analog extensions
		*************************************************************************************************************************************/
		system("mkdir /home/my_dir");
		FILE *fptr;
		fptr = fopen("/home/LogsForLight_Garden.txt", "a+");
			if (fptr == NULL)
			{
				printf("Could not create file LogsForLight_Garden.txt ");   
				exit(1);             
			}
			int logic_lvl = gpio_get_value(20);
		int i = 0;
	
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
		
		fprintf(fptr, "Time Is : %d:%d :%d: | Sum is :  %d |The logical level  %d |Number of samples : %d \n", tm.tm_hour, tm.tm_min, tm.tm_sec, sum, logic_lvl, average);
		printf("Logs For is print Light_Garden\n");
		sleep(5);		
		fclose(fptr);
			
		//	printf("Average = %d\n", sum);
	    
		gpio_fd_close(fd);
		time_new = 0;
		return sum; //average;
	
	
	
	}
	
}
