#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct Node{
    int y,x;
    int lev;
};
int main(){
    int fd=open("./test.txt",O_RDWR |O_TRUNC,0);
    if(fd<0){
        printf("FILE OPEN ERROR\n");
        exit(1);
    }
    struct Node temp ={3,5,99};
    //void * 은 모든 타입을 뜻함
    write(fd,(void*)&temp,sizeof(temp));
    close(fd);
    fd=open("./test.txt",O_RDWR,0);
    //다시 열어준 이유는 fd로 쓰면은 fd 포인터가 가리키는 값이 맨 뒤로 향한다
    //따라서 fd를 초기화 해주기 위해 다시 열어줬다..
    //근데 지정된 위치부터 읽는 syscall 함수 있겠지..
    struct Node r={0};
    read(fd,&r,sizeof(r));
    printf("%d %d %d\n",r.y,r.x,r.lev);
    return 0;
}
