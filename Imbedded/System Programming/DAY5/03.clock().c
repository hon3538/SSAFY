#include <stdio.h>
#include <time.h>
int main(){
    //현재 프로세스가 시작되고, 얼마나 시간이 흘렀는지 CPU 클럭 수치 값
    clock_t a=clock();
    printf("%ld\n",a);

    //CLOCKS_PER_SEC 매크로
    //1초당 시스템 clock 이 올라가는 정도를 나타낸다.
    //1초당 100만 clocks 가 나오므로, 1clock은 1us 를 의미한다.
    printf("%ld\n",CLOCKS_PER_SEC);

    clock_t end=clock();
    printf("%ld\n",end);

    int time=end-a; //코드가 수행된 시간
    clock_t start;
    int i;

    start=clock();
    i=0;
    while(i<100000000){
        int a=1+2;
        i++;
    }
    end=clock();
    printf("+ : %ld\n",end-start);

    start=clock();
    i=0;
    while(i<100000000){ int a=1-2; i++;}
    end=clock();
    printf("- : %ld\n",end-start);

    start=clock();
    i=0;
    while(i<100000000){int a=1*2; i++;}
    end=clock();
    printf("* : %ld\n",end-start);

    start=clock();
    i=0;
    while(i<100000000){int a=1/2; i++;}
    end=clock();
    printf("/ : %ld\n",end-start);

    start=clock();
    i=0;
    while(i<100000000){int a=1%2; i++;}
    end=clock();
    printf("% : %ld\n",end-start);

    return 0;
