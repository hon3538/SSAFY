#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *abc(){
    //pthread_t id 값 얻을 수 있음
    //pthread_t 타입 : unsigned long int
    pthread_t id=pthread_self();
    printf("[%u] \n",id);
    //%u -> 부호없는 10진수
}
int main(){
    pthread_t tid[4];

    for(int i=0;i<3;i++){
        pthread_create(&tid[i],NULL,abc,NULL);
        printf("%u\n",tid[i]);
    }
    for(int i=0;i<3;i++) pthread_join(tid[i],NULL);
    return 0;

}