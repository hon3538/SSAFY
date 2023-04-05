#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t t[100];
int sum=0;
int head=0;
int tail=0;
int del=-1;
//같으면 비어있음
void* coin(int index){
    int coins=0;
    while(1){
        usleep(1000*100);
        //printf("[index:%d] coins:%d\n",index,coins);
        coins++;
        sum++;
        if(del==index) break;
    }
}
void (*p[100])(int);
int idx[100];
int main(){

    char buf[50];
    while(1){
        memset(buf,0,sizeof(buf));
        printf("TShell>");
        scanf("%s",buf);

        if(strcmp("show",buf)==0){
            printf("coins:%d\n",sum);
        }else if(strcmp("add",buf)==0){
            int idx=tail;

            pthread_create(&t[tail++],NULL,coin,idx);
        }else if(strcmp("del",buf)==0){
            if(head==tail) continue;
            del=head++;
            pthread_join(t[del],NULL);
        }else if(strcmp("exit",buf)==0){
            break;
        }
    }


    return 0;
}
