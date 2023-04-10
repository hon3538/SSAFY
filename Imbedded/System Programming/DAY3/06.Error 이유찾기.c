#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];

void *run(void *arg){
    int a=*(int*)arg;
    printf("%d",a);
}
int main(){
    for(int i=0;i<4;i++){
        pthread_create(&tid[i],NULL,run,&i);
    }
    for(int i=0;i<4;i++) pthread_join(tid[i],NULL);

    //이렇게만 하면 출력이 이상하게 나옴
    //0123 이 나올거라고 예상되는데.. 뭐 스케쥴러에 의해 순서가 뒤바뀐다고 해도
    //4444는 나오면 안 되는데, 4444가 나옴

    //스케줄러에 의해 for문이 다 끝나고 스레드가 실행되면 i++로 인해서 i=4가 되어버림
    //i값이 주소로 들어가기 때문에, 값이 계속 업데이트 되어 버림..

    return 0;
}
