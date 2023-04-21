#include <stdlib.h>
#include <sys/ioctl.h>


char buf[30] = "THIS IS APP MEMORT";
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

    //buf는 문자열으로 주소값을 전달한다. 하지만
    //user space와 kernel space에서 같은 공간에 대한 주소값이 서로 다르다
    //user space는 0x0000000부터 시작하는 것처럼 해서 편하게 하기 위함

    //따라서 uaccess.h 의 함수를 사용해서 서로 주소를 맞춰줘야한다.
    ioctl(fd, _IO(0,3), buf);

    close(fd);
    return 0;
}
