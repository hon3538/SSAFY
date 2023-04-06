//워낙 move_prinw 를 같이 쓰니까 합쳐서 나옴
//mvprintw(1,3,"AAA");
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void abc(int y,int x){
    clear();
    for(int i=0;i<5;i++){
        mvprintw(y+i,x,"*");
        refresh();
        usleep(100*1000);
    }
    usleep(100*1000);
    for(int i=0;i<5;i++){
        mvprintw(y+i,x," ");
        refresh();
        usleep(100*1000);
    }
}
int main(){
    initscr();
    curs_set(0);
    while(1){
        int y=rand()%20;
        int x=rand()%20;
        abc(y,x);
    }
    getch();
    endwin();
    return 0;
}
