#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // POSIX API 제공
void* DD1(){
    int i=0;
    while(1){
        printf("[DD1] %c\n",'A'+i);
        i=(i+1)%3;
        usleep(300*1000); //us 단위
    }
    return 0;
}
void* DD2(){
    int i=0;
    while(1){
        printf("[DD2] %d\n",i);
        i=(i+1)%6;
        usleep(1000*200);
    }
    return 0;
}
void* DD3(){
    int i=0;
    while(1){
        printf("[DD3] %c\n",'A'+i);
        i=(i+1)%26;
        usleep(1000*300);
    }
    return 0;
}
int main(){
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,DD1,NULL);
    pthread_create(&t2,NULL,DD2,NULL);
    pthread_create(&t3,NULL,DD3,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    return 0;
}