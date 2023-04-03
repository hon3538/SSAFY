//저장장치에서 어디까지 읽었는지 Offset 값을 내부적으로 가지고 있다.
//lseek : 기준점에서 offset 만큼 떨어져 있는 곳으로 파일
//offset으로 옮기는 시스템 콜

//off_t lseek(int fd,off_t offset,int wehnce);
//off_t : 정수(long), 음수 가능
//offset : 떨어져있는 곳
//whence : 기준

//whence 기준
//SEEK_CUR : 현재위치에서 부터
//SEEK_SET : 시작점에서 부터
//SEEK_END : 끝 지점에서 부터
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
        //읽기 성공하면 현재 읽은 사이즈 저장
    int n;
    n=lseek(fd,0,SEEK_CUR);
    printf("%d\n",n);
    read(fd,buf,10);
    printf("%s\n",buf);

    n=lseek(fd,0,SEEK_CUR);
    printf("%d\n",n);

    memset(buf,0,10);
    read(fd,buf,5);
    printf("%s\n",buf);
    n=lseek(fd,0,SEEK_CUR);
    printf("%d\n",n);
        //read 수행 시, offset값이 다음 읽어야 하는 곳으로 옮겨간다.
        //이렇게 offset을 옮겨주는 함수가 lseek 함수이다.
    close(fd);

    return 0;
}
