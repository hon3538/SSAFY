//A~Z , Z~A 무한 출력 프로그램
//SIGUSR1 핸들러
//SIGUSR2 핸들러
//SOGTERM 핸들러
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int flag;
void aaa(int num){
    printf("[Button Clicked]\n");
}
void bbb(int num){
    system("clear");
    printf("RESET\n");
    sleep(1);
}
void ccc(int num){
    flag=1;
    printf("BYE\n");
    sleep(1);
}
int main(){
    signal(SIGUSR1,aaa);
    signal(SIGUSR2,bbb);
    signal(SIGTERM,ccc);
    char c='A';
    int i=0;
    while(1){
        printf("%c\n",c);
        if(i){
            c--;
        }else c++;
        if(c=='A'||c=='Z'){
            i=i^0x01;
        }
        if(flag) break;
        usleep(1000*100);
    }
}
