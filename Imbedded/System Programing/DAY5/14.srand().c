//srand(시간값) 이렇게 하면 1초당 다른 랜덤값으로 매번 섞인다
//App 실행할 때마다 다른 랜덤값이 출력된다.
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//화면에 랜덤으로 별을 찍는 프로그램
int main(){
    initscr();
    //시간값을 넣어줘서 랜덤값 생성
    srand(time(NULL));
    while(1){
        move(rand()%10,rand()%10);
        printw("*");
        refresh();
        usleep(100*1000);
    }
    endwin();

    return 0;
}
