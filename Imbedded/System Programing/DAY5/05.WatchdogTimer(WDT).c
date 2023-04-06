#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gogo(){
    printf("WAKE UP!\n");
    exit(1);
}

int main(){
    signal(SIGALRM,gogo);
    alarm(3); // 3초 뒤에 SIGALRM signal 이 발생한다.
    //alarm을 다시 울리면 갱신 된다.
    alarm(3); //여기서부터 다시 0초부터 셈

    printf("3 seconds\n");
    printf("wait...\n");
    while(1) sleep(1);
    return 0;
}