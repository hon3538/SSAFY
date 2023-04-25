#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main(){
	int fd=open("/dev/nobrand",O_RDWR);
	if(fd<0){
		printf("error\n");
		exit(1);
	}
	struct But{
		int b1;
		int b2;
	}but;
	while(1){
		//check buttons
		ioctl(fd, _IO(0,1),&but);
		//blink
		if(but.b1==1&&but.b2==1){
			for(int i=0;i<3;i++){
				//led1,2 on
				loctl(fd, _IO(0,2),0);
				loctl(fd, _IO(0,3),0);
				usleep(500*1000);
				loctl(fd, _IO(0,4),0);
				loctl(fd, _IO(0,5),0);
				usleep(500*1000);
			}
		}else if(but.b1==1){
			//1 on 2 off
			loctl(fd, _IO(0,2),0);
			loctl(fd, _IO(0,5),0);
		}else if(but.b2==1){
			//1 off 2 on
			loctl(fd, _IO(0,3),0);
			loctl(fd, _IO(0,4),0);
		}else {
			//both off
			loctl(fd, _IO(0,4),0);
			loctl(fd, _IO(0,5),0);
		}
		usleep(300*1000);
	}
	return 0;
}
