#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *abc(){
    while(1){
        printf("ABC\n");
        sleep(1);
        //1+shift+K -> shell script 에 쓰이고
        //3+shift+K -> C 라이브러리 함수
        //2+shift+K -> syscall ( sleep은 syscall 아니라 안 뜸)
    }
    return 0; //void* 을 return 시키는 것임, 생략가능
}

void *bts(){
    while(1){
        printf("BTS\n");
        sleep(1);
    }
    return 0;
}
int main(){
    pthread_t t1, t2;
    //pthread_create(thread id, 쓰레드 속성, 함수, 파라미터)
    //Arg1 : thread id 저장될 변수 주소
    //Arg2 : 쓰레드 설정(attribute), NULL은 Default 설정
    //Arg3 : 실행할 함수 이름
    //Arg4 : 함수에 인자 값을 전달해주고 싶을 때 사용

    pthread_create(&t1,NULL,abc,NULL);
    pthread_create(&t2,NULL,bts,NULL);

    //main도 하나의 thread이기 때문에, 총 스레드가 3개있음
    //main thread는 여기서 멈춰있음
    //abc, bts 함수가 무한 반복중이다,
    //pthread_craete를 하면 커널 내부적으로 쓰레드 제작작업을 한다.
    //pthread_join을 만나면 쓰레드가 종료됨을 기다린 후, 커널 내부 정리 작업을 한다.
    //근데, abc, bts가 무한루프라 main쓰레드는 기다리느라 동작 못하는중

    //pthread_join(thread id,thread 리턴값)
    //pthread를 사용하면 반드시 join을 써주자 -> 메모리 해제 작업
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    
    //gcc ./thread.c -o ./thread -lpthread
    //lpthread : pthread Library를 사용

    //결과가 abc 와 bts 가 순서와 상관없이 나오는데
    //이는 OS의 스케쥴러에 의존하여 출력되기 때문이다.
    return 0;
}
