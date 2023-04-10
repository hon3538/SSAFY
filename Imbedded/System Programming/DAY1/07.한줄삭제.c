//한줄 삭제 방법
//1. 모든 내용을 읽는다.
//2. '\n'을 기준으로 줄 단위로 문자열을 보관한다.
//3. 입력받은 Line을 제외하고 파일에 저장한다.

//기본 컨셉은 위와 같지만, 구현방식은 천차 만별.. 쉬운방법은 뭘까

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(){
    int fd=open("./test.txt",O_RDWR,0);
    char buf[200];
    char mem[20][20];
    memset(buf,0,sizeof(buf));
    read(fd,buf,sizeof(buf));
    char *p; 
    int order=0;
    for(p=strtok(buf,"\n");p!=NULL;p=strtok(NULL,"\n")){
//      printf("%s\n",p);
        strcpy(mem[order++],p);
    }   
    close(fd);
    fd=open("./test.txt",O_RDWR |O_TRUNC,0);
    int i=0;
    int input;
    scanf("%d",&input);
    while(i<order){
        if(i++== input-1) continue;
        write(fd,mem[i-1],strlen(mem[i-1]));:
        write(fd,"\n",1); //이거 안해주면 txt 파일에는 한 줄로 표현됨...
//      printf("%s\n",mem[i-1]);
    }   
    close(fd);
    return 0;
}
