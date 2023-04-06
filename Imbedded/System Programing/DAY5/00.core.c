#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* abc(){
    while(1);
    return 0;
}
int main(){
    pthread_t t[4];

    //코어는 각각 하나의 스레드 처리를 담당한다.
    //따라서 코어 개수만큼 thread를 만들어 개발할 시에 CPU 최고 효율을 낼 수 있다
    for(int i=0;i<4;i++){
        pthread_create(&t[i],NULL,abc,NULL);
        sleep(3);
    }
    for(int i=0;i<4;i++){
        pthread_join(t[i],NULL);
    }
    return 0;
}
