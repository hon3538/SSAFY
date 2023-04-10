#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd =open("./text.txt",O_RDWR,0);
    if(fd<0){
        printf("OPEN ERROR\n");
        exit(1);
    }
    //10 개씩 읽으므로 마지막 여유 칸을 널문자로 하고, printf 사용하면
    //알아서 개행 해준다.
    char buf[11] ={0};
    while(1){
        //초기화 안 해주면, 마지막에 사이즈가 10보다 작은 경우에도 사이즈 10까지 출력하여
        //이전 값을 같이 불러와버림...(11이 null이기 때문에-문자열을 10까지 출력)
        //사이즈 7이면 7까지만 출력하기 위해..
        memset(buf,0,11); 
        //읽기 성공하면 현재 읽은 사이즈 저장
        ssize_t i =read(fd,buf,10);
        printf("====READ====\n");
        printf("%s\n",buf);
        printf("====END====\n");
        printf("%lu\n",i);
        if(i<10) break;
    }
    close(fd);

    return 0;
}
