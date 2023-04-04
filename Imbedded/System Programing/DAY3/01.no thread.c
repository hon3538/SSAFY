#include <stdio.h>
#include <unistd.h>

void abc(){
    while(1){
        printf("ABC\n");
        sleep(1);
        //1+shift+K -> shell script 에 쓰이고
        //3+shift+K -> C 라이브러리 함수
        //2+shift+K -> syscall ( sleep은 syscall 아니라 안 뜸)
    }
}

void bts(){
    while(1){
        printf("BTS\n");
        sleep(1);
    }
}
int main(){
    abc();
    bts();
    //ABC 만 계속 나옴
    return 0;
}
