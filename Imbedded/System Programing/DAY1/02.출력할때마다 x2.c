#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    int fd=open("./cal.txt",O_RDWR,0);
    char buf[100];
    read(fd,buf,99);
    int n;
    sscanf(buf,"%d",&n);
    n*=2;
    sprintf(buf,"%d",n);
    lseek(fd,0,SEEK_SET);
    write(fd,buf,strlen(buf));

    close(fd);
    return 0;
}
