#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
void error(){
    printf("\nSYSTEM ERROR\n");
    exit(1);
}
void* check(){
    signal(SIGALRM,error);
}
int main(){
   // pthread_t t;
   // pthread_create(&t,NULL,check,NULL);
   // 스레드 없이 구현할 수 있구나..
    signal(SIGALRM,error);
    char buf[20];
    char command[50];
    while(1){
        alarm(5);
        memset(command,0,sizeof(command));
        printf("shell>");
        scanf("%s",buf);

        sprintf(command,"echo %s",buf);
        system(command);
    }


    return 0;
}
