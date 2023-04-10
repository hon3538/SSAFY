//Thread 4개 만들어서 각각 ABC, MINMIN, COCO, KFCKFC 출력
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t arr[4];
void* abc(void *p){
    int* a=(int*)p;
    if(*a==1){
        printf("%d : ABC\n",*a);
    }else if(*a==2){
        printf("%d : MINMIN\n",*a);
    }else if(*a==3){
        printf("%d : COCO\n",*a);
    }else if(*a==4){
        printf("%d : KFCKFC\n",*a);
    }
    return 0;
}
int main(){
    int tid[4];
    for(int i=0;i<4;i++){
        tid[i]=i+1;
        pthread_create(&arr[i],NULL,abc,&tid[i]);
    }
    for(int i=0;i<4;i++) pthread_join(arr[i],NULL);
    return 0;
}