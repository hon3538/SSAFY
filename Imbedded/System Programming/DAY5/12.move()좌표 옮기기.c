#include <ncurses.h>
#include <unistd.h>

int main(){
    initscr();
    curs_set(0); //커서 안 보이게 하는거
    move(10,30);
    printw("GAME OVER\n");
    refresh();

    sleep(2);
    //getch();
    endwin();
    return 0;
}
