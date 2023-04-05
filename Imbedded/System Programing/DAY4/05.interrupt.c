#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void gogo(int num){ //num에 시그널 번호가 자동으로 들어감
    printf("GOGO\n");
}
int main(){
    //SIGUSR1 : User signal, 정해진 역할 없음.. kill 명령어 또는 killall 명령어로 시그널 전송 가능
    siganl(SIGUSR1,gogo); // kill -SIGUSR1 [PID]
    //SIGUSR1 siganl을 받으면 gogo 콜백함수를 실행시킴
    
    //다른 process에서 ex) kill -SIGUSR1 10991 
    whlie(1) sleep(1);
    return 0;
}