#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>


#define SYSFS_GPIO_DIR "/sys/class/gpio"



/****************************************************************
 * gpio_export
 ****************************************************************/
int gpio_export(unsigned int gpio);
/****************************************************************
 * gpio_unexport
 ****************************************************************/
int gpio_unexport(unsigned int gpio);

/****************************************************************
 * gpio_set_dir
 ****************************************************************/
int gpio_set_dir(unsigned int gpio, unsigned int out_flag);

/****************************************************************
 * gpio_set_active_low Get -> char *active_low
 ****************************************************************/

int gpio_set_active_low(unsigned int gpio, char *active_low);

/****************************************************************
 * gpio_set_value
 ****************************************************************/
int gpio_set_value(unsigned int gpio, unsigned int value);

/****************************************************************
 * gpio_set_Toggle mode if 1 -> 0 if -> 1 Standby_tim =suspension
 * lops_Numbe Repeats
 ****************************************************************/
int gpio_Toggle_mode(unsigned int gpio, unsigned int Standby_time, unsigned int lops_Number);

	
/****************************************************************
 * gpio_set_value_1
 ****************************************************************/
int gpio_set_value_1(unsigned int gpio);

	
/****************************************************************
 * gpio_set_value_0
 ****************************************************************/
int gpio_set_value_0(unsigned int gpio);

/****************************************************************
 * gpio_get_value
 ****************************************************************/
int gpio_get_value(unsigned int gpio);

/****************************************************************
 * gpio_set_edge
 ****************************************************************/

int gpio_set_edge(unsigned int gpio, char *edge);

/****************************************************************
 * gpio_fd_open
 ****************************************************************/

int gpio_fd_open(unsigned int gpio);

/****************************************************************
 * gpio_fd_close
 ****************************************************************/

int gpio_fd_close(int fd);
