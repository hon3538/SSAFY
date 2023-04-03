#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int fd=open("./test.txt",O_RDWR|O_TRUNC,0);
    //O_TRUNC : 파일 내용 제거 후 사용
    char buf[100]="HI SYSTEM CALL\n";
    
    write(fd,buf,strlen(buf));
    //사이즈를 문자열 길이에 맞춰서 넣지 않으면, 뒤에 잉여값까지 write 됨...

    close(fd);

    return 0;

}
