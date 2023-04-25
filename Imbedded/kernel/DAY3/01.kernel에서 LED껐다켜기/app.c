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
	
	printf("input 4 number : ");
	scanf("%d %d %d %d", &t.a, &t.b, &t.c, &t.d);
	
	ioctl(fd, _IO(0,5), &t);
	
	int sum;
	ioctl(fd, _IO(0,6), &sum);
	printf("sum : %d\n", sum);

	for(int i=0; i<sum; i++){
		printf("led on!\n");
		ioctl(fd, _IO(0,3), 0);
		usleep(500*1000);
		printf("led off!\n");
		ioctl(fd, _IO(0,4), 0);
		usleep(500*1000);
	}
	printf("Success!\n");

	close(fd);
    return 0;
}

