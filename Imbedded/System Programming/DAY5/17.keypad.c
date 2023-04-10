#include <stdio.h>
#include <ncurses.h>
#include <locale.h> //setlocale()
int main(){
    setlocale(LC_CTYPE,"ko_KR.utf8");//ncurses 에서 한글입력 가능하게 함
    initscr();
    keypad(stdscr,TRUE);
    while(1){
        int ch =getch();
        if(ch==KEY_LEFT){
            printw("←");
            refresh();
        }
        if(ch==KEY_RIGHT){
            printw("→");
            refresh();
        }
        if(ch==KEY_UP){
            printw("↑"); //window key + .(점)
            refresh();
        }
        if(ch==KEY_DOWN){
            printw("↓");
            refresh();
        }
    }
    getch();
    endwin();
    return 0;
}
