#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct Node{
	int a;
	int b;
	int c;
	int d;
}t;

int main()
{
    int fd = open("/dev/nobrand", O_RDWR);
    if (fd < 0)
    {
        printf("ERROR\n");
		exit(1);
    }
	int lev;
	while(1){
		ioctl(fd, _IO(0,7), &lev);
		printf("Btn Read lev : %d\n", lev);
		usleep(300*1000);
	}
    
	printf("Success!\n");

	close(fd);
    return 0;
}
