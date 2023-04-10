#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc,char *argv[]){
    if(argc<=1){
        printf("invalid command!\n");
    }
    int PID =atoi(argv[1]);
    int input;
    char command[100];
    while(1){
        printf("shell>");
        scanf("%d",&input);
        if(input==1){
            sprintf(command,"kill %s %d","-USR1",PID);
            system(command);
        }else if(input==2){
            sprintf(command,"kill %s %d","-USR2",PID);
            system(command);
        }else if(input==3){
            sprintf(command,"kill %d",PID);
            system(command);
        }else{
            printf("invalid input!\n");
        }
    }

    return 0;
}
