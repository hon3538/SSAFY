#include <ncurses.h>
#include <unistd.h>

int main(){
    initscr();
    for(int i=3;i>=0;i--){
        printw("[%d]",i);
        refresh();
        sleep(1);
        clear();
    }

    double d=0;
    while(d<=10){
        printw("%.2lf\n",d);
        refresh();
        usleep(1000*10);
        d+=0.01;
        clear();
    }
    /*
    for(double i=0;i<=10;i+=0.01) 로도 가능
    */

    sleep(2);
    getch();
    endwin();
    return 0;
}
