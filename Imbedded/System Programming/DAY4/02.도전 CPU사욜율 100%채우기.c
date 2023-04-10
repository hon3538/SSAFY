#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* abc1(){
    while(1){
    }
    return 0;
}

void* abc2(){
    while(1){
    }
    return 0;
}

void* abc3(){
    while(1){
    }
    return 0;
}

void* abc4(){
    while(1){
    }
    return 0;
}
pthread_t t[4];
void (*arr[4])()={abc1,abc2,abc3,abc4};
int main(){
    for(int i=0;i<4;i++)
        pthread_create(&t[i],NULL,arr[i],NULL);

    for(int i=0;i<4;i++){
        pthread_join(t[i],NULL);
    }

}
