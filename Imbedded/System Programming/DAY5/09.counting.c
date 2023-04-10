include <ncurses.h>
#include <unistd.h>

int main(){
    initscr();
    for(int i=3;i>=0;i--){
        printw("[%d]",i);
        refresh();
        sleep(1);
        //clear() : 화면 전체를 지운다
        clear();
    }
    getch();
    endwin();
    return 0;
}
