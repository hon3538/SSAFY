//mutex_lock 객체 = 화장실 열쇠
//mutex락을 얻어 화장실 이용
//mutex락을 가게 주인 (kernel)에게 돌려줌
//mutex락을 얻은 쓰레드 만이 share Resource를 사용 가능

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mlock;
pthread_t t[4];
int cnt;
void* run(){
    //mutex lock(화장실키)을 요청하여 얻는다.
    //얻을 수 있을 때 까지 block 된다.
    //따라서, mutex는 한번에 하나씩의 스레드밖에 사용할 수 없다.
    pthread_mutex_lock(&mlock);
    for(int i=0;i<10000;i++) cnt++; //화장실을 잠그고 사용하므로 다른 스레드가 못사용
    pthread_mutex_unlock(&mlock);
}
int main(){
    //pthread_mutex_init(&mutex,attr)
    //mutex 객체 초기화, attr에 NULL을 넣으면 기본 값으로 처리
    pthread_mutex_init(&mlock,NULL);
    for(int i=0;i<4;i++){
        pthread_create(&t[i],NULL,run,NULL);
        usleep(100);
    }
    for(int i=0;i<4;i++) pthread_join(t[i],NULL);
    printf("%d",cnt);
    return 0;
}