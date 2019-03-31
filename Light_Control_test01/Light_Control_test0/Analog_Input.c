#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SYS_Analog "/sys/bus/iio/devices/iio:device0/"
#define MAX_BUF 64

/****************************************************************
 *in_voltage_raw
 ****************************************************************/

//float tt = 0.0;
char value_str[7];
long int value_int = 0; 
int Number_of_times_to_read = 0, Number=0;
int sum = 0;
int average = 0;
int sampling[100];
 int SET_Anlog_Raw_init(unsigned int in_voltage_raw, unsigned int Number_of_times_to_read)
{
	int fd, len;
	char buf[MAX_BUF];
	//unsigned int siz = sizeof((int)Number_of_times_to_read);
	
	len = snprintf(buf, sizeof(buf), SYS_Analog "in_voltage%d_raw", in_voltage_raw);    ///   in_voltage%_raw
	fd = fopen(buf,"r");
	if (fd < 0) {
		perror("/sys/bus/iio/devices/iio:device0/in_voltage%d_raw");
		return fd;
	}
	for (average = 0; average < Number_of_times_to_read; average++)    //Number of samples
	{
		
		
		fread(value_str, 6, 6, fd);
		value_int = strtol(value_str, NULL, 0);
		// ((float)value_int / 2274.4)/Number_of_times_to_read;
		
		sampling[average] = value_int;
		sum += sampling[average];
		printf("CH 0 Anlog Volt: %f",(float) value_int / 4095);
		printf("V \n");
		fflush(stdout);
	//	usleep(5000);
		rewind(fd);
		Number++;
	}                    
	 average = sum / Number_of_times_to_read;   //average calculation
	printf("Average = %d\n", average);
	fclose(fd);
	return average; //( average/2274.444);
	
	
}


