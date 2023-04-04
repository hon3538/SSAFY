#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a=100;
int b;
void* abc(){
    int c=10;
    printf("============\n");
    printf(".data : 0x%X\n",&a); // 전역변수 -> .data (초기화)
    printf(".bss : 0x%X\n",&b); // 전역변수 -> .bss (초기화x)
    //전역변수들은 메모리를 공유함

    int *p=(int*)malloc(4);
    printf(".heap : 0x%X\n",p); // 동적할당 -> heap 
    //참고로 &p 는 포인터변수의 주소로 stack에 있다.
    free(p);
    // heap도 공유 된다. 다만, 이 예제로는 malloc으로 함수가 실행될 때마다 새로운 주소를 할당하므로
    // 공유 가능 여부를 판단할 수가 없다.

    static int cnt=15; // static은 전역변수와 동일
    cnt++;
    printf("static : %d\n",cnt);
    //static도 공유된다.

    printf("stack : 0x%X\n",&c); // 지역변수 -> .stack
    //stack만 공유 안 된다.

}
int main(){
    pthread_t t1, t2;
    pthread_create(&t1,NULL,abc,NULL);
    sleep(1); //이렇게 하면, 첫 thread가 malloc 하고 free까지 하기 때문에
    // 그공간은 비어있다. 따라서 두번째 thread에서 같은 주소로 malloc을 할당한다.
    //만약, 첫번째 thread에서 free 하기 전에 두번째 malloc이 실행된다면 다른 주소로 할당하겠지
    pthread_create(&t2,NULL,abc,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
