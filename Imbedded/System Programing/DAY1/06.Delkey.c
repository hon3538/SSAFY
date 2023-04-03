#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>
#include <string.h>

int main(){
    //text.txt 에 ABCDEFG 가 적혀 있다

    int fd=open("./test.txt",O_RDWR,0);
    lseek(fd,1,SEEK_SET);
    char buf[10]={0x7F};
    //del key ascii code 를 넣으면 해당 자리 삭제가 됨
    //하지만 실제 txt 내용은 del key ascii code가 남아있음.
    //출력만 안 될뿐 
    int n=strlen(buf);
    write(fd,buf,n);
    //B 가 delete로 대체됨
    //A del CDEFG 므로 -? CDEFG
    lseek(fd,3,SEEK_SET);
    write(fd,buf,n);
    //D가 delete로 대체됨
    //EFG 만 출력됨
    close(fd);

    return 0;

}
