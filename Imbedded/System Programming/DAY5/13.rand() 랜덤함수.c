#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    initscr();

    while(1){
        clear();
        //App을 껐다 킬 때 마다 랜덤 값이 똑같다.
        //프로그램을 켜면 5->9->1->4->6->4....
        //프로그램 다시 껐다 키면 5->9->1->4... 똑같음
        printw("%d\n",rand());
        printw("%d\n",rand()%5);//0~4까지 랜덤
        //printw("%d\n",rand()%5+3);//3~7까지 랜덤
        refresh();
        usleep(100*1000);
    }
    //getch();
    endwin();
    return 0;
}
