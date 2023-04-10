//Thread 간 메모리 공유로 인해 예상치 못한 결과가 나온다.
//이것을 해결해보자

//Race Condition
// -> Thread / Process의 타이밍에 따라 결과 값이 달라질 수 있는 상태

//Critical Section
// -> Thread / Process가 동시에 접근해서 안 되는 곳
// -> HW 장치를 사용하는 곳 / Shared Resource (전역 변수 등)
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_t tid[4];
int cnt;
void *run(){
    //이 부분이 스레드간 공유가 되버림, critical section, race condition이다.
    for(int i=0;i<10000;i++) cnt++;
}
int main(){
    for(int i=0;i<4;i++) {
        pthread_create(&tid[i],NULL,run,&i);
        //usleep(100);
    }
    for(int i=0;i<4;i++) pthread_join(tid[i],NULL);
    printf("%d\n",cnt);
    //전역변수이므로 4번 함수를 돌렸다면 40000이 나와야한다.
    //하지만 40000아래 값이 나온다.

    //cnt==5 일떄
    //만약 첫번째 스레드에서 cnt 메모리에 접근하여 값을 가져오고 증가시킨다음에 다시 업데이트시킨다
    //근데 업데이트 시키기 전에 다른 스레드에서 cnt에 접근한다면, 다른 스레드에서도
    //cnt==5일때의 값을 가져와버린다.. 
    //세번째 스레드가 첫번째 스레드에서 업데이트한 cnt==6을 가져와서 증가시켜서 업데이트하면
    //cnt==7이 돼야하는데, 그 다음에 두번째 스레드에서 값을 메모리에 다시 업데이트 해버리면 cnt==6이 되버린다..
    //엉망이 되어버림.

    //따라서 아주 작은 sleep을 넣어주어 타이밍을 바꾼다.
    //하지만, 함수가 오래걸리면 sleep도 크게 넣어줘야 하기에, 유지 보수 측면에서 좋지 않은 방법이다.
    //-> mutex 사용하면 된다.
    return 0;
}