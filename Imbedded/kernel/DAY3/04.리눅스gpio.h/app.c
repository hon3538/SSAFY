#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>


int main()
{
    int fd = open("/dev/nobrand", O_RDWR);
    if (fd < 0)
    {
        printf("ERROR\n");
		exit(1);
    }
	while(1){
		int btn1;
		int btn2;

	
		ioctl(fd, _IO(0,5), &btn1);
		printf("BTN1 =%d\n",btn1);
		ioctl(fd, _IO(0,8),&btn2);
	       	printf("BTN2 =%d\n",btn2);	
		if(btn1==0){
			ioctl(fd, _IO(0,3),0);
		}
		else
			ioctl(fd, _IO(0,4), 0);
		if(btn2==0){
			ioctl(fd, _IO(0,6),0);
		}
		else ioctl(fd, _IO(0,7),0);
		usleep(300*1000);
	}
    
	printf("Success!\n");

	close(fd);
    return 0;
}
