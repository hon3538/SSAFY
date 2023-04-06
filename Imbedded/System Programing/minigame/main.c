#include <ncurses.h>
#include <locale.h> //setlocale()
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#define N 7
//M 몬스터, Y 성배
pthread_t m; // 몬스터 스레드
pthread_mutex_t mlock;
char map[N][N+1]={
    "#######",
    "#     #",
    "#^##  #",
    "#   a #",
    "# ^ ###",
    "#    Y#",
    "#######"
};
//캐릭터 위치
int ny=1;
int nx=1;
int hp=100;
//몬스터 정보
struct Monster{
    int before_y;
    int before_x;
    int y;
    int x;

}mon1;
//화면 지우고 출력하는 소스코드 작성
void print(){
    clear();
    for(int y=0;y<N;y++){
        for(int x=0;x<N+1;x++){
            if(y==ny&&x==nx){
                printw("@");
            }else{
                printw("%c",map[y][x]);
            }
        }
        printw("\n");
    }
    printw("HP : %d\n",hp);
    refresh();
}
void gameOver(){
    usleep(500*1000);
    clear();

    mvprintw(10,30,"Game Over");
    refresh();
    sleep(1);
}
int checkStatus(){
    if(map[ny][nx]=='M'){
        gameOver();
        return 0;
    }
    if(map[ny][nx]=='Y'){
        usleep(500*1000);
        clear();

        mvprintw(10,30,"WIN");
        refresh();
        sleep(1);
        return 1;
    }
    if(map[ny][nx]=='^'){
        hp-=10;
        if(hp<=0){
            gameOver();
            return 0; //over
        }

    }
    if(map[ny][nx]=='a'){
        hp+=50;
        map[ny][nx]=' ';
    }
    return 2;//survive;
}
int dir[4][2]={-1,0,0,1,1,0,0,-1};
void* monster(){
    srand(time(NULL));
    int dy;
    int dx;
    while(1){
        int d=rand()%4;
        dy=mon1.y+dir[d][0];
        dx=mon1.x+dir[d][1];
        if(map[dy][dx]=='#') continue;
        pthread_mutex_lock(&mlock);

        map[mon1.before_y][mon1.before_x]=' ';
        mon1.before_y=mon1.y;
        mon1.before_x=mon1.x;
        mon1.y=dy;
        mon1.x=dx;
        map[dy][dx]='M';

        pthread_mutex_unlock(&mlock);
        usleep(2000*1000);
    }
}
int main(){
    setlocale(LC_CTYPE,"ko_KR.utf8");//ncurses 에서 한글입력 가능하게 함
    initscr();
    //원래는 getch() 가 들어올 떄까지 대기하고 있는다..
    //나중에 몬스터가 움직여야할 상황이나
    //입력 받지 않아도 게임이 뭔가 진행되어야 할 상황이라면문제가 생긴다.
    // nodelay를 쓰면 반복문을 계속 돌리면서
    //getch를 받는다.getch에 들어오는게 없으면 ERR 리턴
    pthread_mutex_init(&mlock,NULL);
    mon1.y=1;
    mon1.x=3;
    mon1.before_y=1;
    mon1.before_x=3;
    pthread_create(&m,NULL,monster,NULL);

    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    while(1){
        print(); //맵 표시
        int ch =getch();
        usleep(10*1000);
        if(ch==ERR) ch=0;
        if(ch==KEY_LEFT){
            if(map[ny][nx-1]!='#') nx--;
        }
        if(ch==KEY_RIGHT){
            if(map[ny][nx+1]!='#') nx++;
        }
        if(ch==KEY_UP){
            if(map[ny-1][nx]!='#') ny--;
        }
        if(ch==KEY_DOWN){
            if(map[ny+1][nx]!='#') ny++;
        }

        int ret=2;
        if(ch!=0)
            ret=checkStatus();
        if(ret==0||ret==1) break;

    }
    pthread_join(m,NULL);
    getch();
    endwin();
    return 0;
}
