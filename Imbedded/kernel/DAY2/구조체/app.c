#include <stdlib.h>
#include <sys/ioctl.h>
struct Node{
        char n;
        char buf[100];
};
int main(){
    
    int fd = open("/dev/nobrand", O_RDWR);
    if(fd<0){
        printf("ERROR\n");
        exit(1);
    }
    struct Node t={10, "STRUCT MESSAGE!"};
    ioctl(fd, _IO(0,3), &t);
    printf("struct complete\n");

    close(fd);
    return 0;
}
