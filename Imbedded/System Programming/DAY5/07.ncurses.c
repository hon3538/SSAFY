#include <unistd.h>
#include <ncurses.h>

int main(){
    //ncurses 시작을 위한 내부 세팅
    initscr();
    
    printw("Hello world");
    //printw를 수행했지만, 화면에 글씨가 안나올수 있으니 
    //printw 수행 뒤에는 항상 화면 refresh를 해주자
    refresh();

    //키를 눌러야 프로그램이 종료되도록 함
    //안 쓰면 자동 종료됨
    getch(); //키가 눌릴때까지 대기

    //ncurses 종료를 위한 내부 정리
    endwin(); //initscr()과 세트, initscreen
    return 0;
}
