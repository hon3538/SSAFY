#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];

void *run(void *arg){
    int a=*(int*)arg;
    printf("%d",a);
}
int main(){
    //해결방법, i값을 담는 배열을 만들어준다 (각각 주소를 다르게 저장)
    int id[4];
    for(int i=0;i<4;i++){
        id[i]=i;
        pthread_create(&tid[i],NULL,run,&id[i]);
    }
    for(int i=0;i<4;i++) pthread_join(tid[i],NULL);

    return 0;
}
