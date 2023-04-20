#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
    printf("GO\n");

    close(fd);
    return 0;
}
