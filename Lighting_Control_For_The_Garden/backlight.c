#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
/****************************************************************
 * Constants
 ****************************************************************/
 
#define Backlight "/sys/class/backlight/backlight" 
#define MAX_BUF 64



/****************************************************************
 * Set  brightness 0 to 100
 ****************************************************************/
int Backlight_Backlight(unsigned int brightness)
{
	int fd, len;
	char buf[MAX_BUF];
 
	fd = open(Backlight "/brightness", O_WRONLY);
	if (fd < 0) {
		perror("/sys/class/backlight/backlight/brightness");
		return fd;
	}
 
	len = snprintf(buf, sizeof(buf), "%d", brightness);
	write(fd, buf, len);
	close(fd);
 
	return 0;
}

/**************************************************************************
 * actual_brightness
 ******************************************************************************/
int Gat_actual_brightness()
{
	int fd, len;
	char buf[MAX_BUF];
	char ch;
	unsigned int actual_brightness;
	len = snprintf(buf, sizeof(buf), Backlight "/actual_brightness", actual_brightness);
 
	fd = open(buf, O_RDONLY);
	if (fd < 0) {
		perror("actual_brightness");
		return fd;
	}
 
	read(fd, &ch, 3);

	if (ch != '0') {
		printf("actual_brightness is : %d\n", ch);
	}
	
 
	close(fd);
	return actual_brightness;
}
