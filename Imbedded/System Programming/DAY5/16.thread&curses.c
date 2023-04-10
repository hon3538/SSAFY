//gcc ./main.c -o ./main -lncursesw -lpthread && ./main
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t t;
pthread_mutex_t mlock;
void *abc(){
    int num=0;
    while(1){
        //mutex를 안 쓰면 문제가 main thread랑 커서를 서로 가져가려고
        //하기 때문에 이상한 곳에 출력되기도 함... 따라서 커서는 한번씩만
        //할당될 수 있도록 mutex써준다.
        pthread_mutex_lock(&mlock);
        mvprintw(10,30,"      ");
        mvprintw(10,30,"%d",num);
        pthread_mutex_unlock(&mlock);
        refresh();
        num++;
        usleep(100*1000);
    }
}

int main(){
    initscr();
    clear();
    pthread_mutex_init(&mlock,NULL);
    pthread_create(&t,NULL,abc,NULL);
    int num=0;
    while(1){
        pthread_mutex_lock(&mlock);
        mvprintw(10,10,"      ");
        mvprintw(10,10,"%d",num);
        refresh();
        pthread_mutex_unlock(&mlock);
        num++;
        usleep(10*1000);
    }
    getch();
    pthread_join(t,NULL);
    endwin();
    return 0;
}
