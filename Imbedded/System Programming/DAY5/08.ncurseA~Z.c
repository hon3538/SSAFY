#include <ncurses.h>
#include <unistd.h>

int main(){
    initscr();
    int i=0;
    while(i<26){
        usleep(100*1000);
        printw("%c",'A'+i);
        refresh();
        i++;
    }
    getch();
    endwin();
    return 0;
}
