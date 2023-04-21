#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
int main(){
    // /dev에 nobrand 만들어도놔야함
    // sudo mknod [name] [디바이스 종류] [major num] [minor num]
    // 디바이스 종류 : c 는 캐릭터 디바이스 라는 뜻
    //  
    // sudo chmod 666 /dev/nobrand
    // -> 장치파일을 통해서 드라이버와 app이 통신함
    int fd = open("/dev/nobrand", O_RDWR);
    if(fd<0){
        printf("ERROR\n");
        exit(1);
    }   
//  char buf[100];
//  read(fd,buf,100);
    
    while(1){
        int a,b;
        printf("command: 3~6, Age, birth month, birth day,  phone number\n");
        scanf("%d %d",&a,&b);
        if(ioctl(fd, _IO(0,a),b)<0){
            break;
        }
    }   
//  ioctl(fd, _IO(0,3),1234);
//  ioctl(fd, _IO(0,4),9012);
//  ioctl(fd, _IO(0,5),5678);

    printf("Is it now?\n");

    close(fd);
    return 0;
}
