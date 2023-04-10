#include <stdio.h>
#include <uinstd.h>
#include <pthread.h>

void *abc(void *p){
    int *a=(int*)p;
    while(1){
        pritnf("#%d\n",*a);
        sleep(1);
    }
}
int main(){
    pthread_t t;
    int gv=1;
    //create 시에 변수의 주소를 넘기는 방식으로 인자값을 넘길 수 있다.
    //구조체 변수를 사용하면, 더 많은 값을 넘길 수 있다.
    pthread_create(&t,NULL,abc,&gv); 
    pthread_join(t,NULL);

    return 0;
}
