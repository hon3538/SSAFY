#include <stdio.h>
#include <unistd.h>
//3초에 # 하나씩 출력하는 프로그램 작성
int main(){
    setbuf(stdout,NULL);
    // sleepm usellp 사용할 때 화면에 안 찍힐 경우가 있는데,
    //이 때 버퍼를 비우고 시작해야함 (stdout은 터미널을 의미)


    while(1){
        pritnf("#");
        sleep(3);
    }
    return 0;
}