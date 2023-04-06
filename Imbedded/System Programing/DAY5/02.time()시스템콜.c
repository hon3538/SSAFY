#include <stdio.h>
#include <time.h>

int main(){
    time_t current_time = time(NULL);
    //time(&current_time); 으로도 위와 똑같이 동작한다.

    printf("%ld\n",current_time);

    struct tm *tmm=localtime(&current_time);
    //tm struct에 localtime 함수를 써서 시간을 넣어주면
    //tm_sec, tm_min, tm_hour, tm_mday, tm_mon.. 등으로
    //알아서 struct 구조로 데이터가 분할 돼서 들어감

    //현재 시간 출력
    char day[10][10]={"MON","TUE","WED","THU","FRI","SAT","SUM"};
    printf("%d/%d/%d %s %d : %d : %d\n",tmm->tm_year,tmm->tm_mon,tmm->tm_mday,day[tmm->tm_wday],tmm->tm_hour,tmm->tm_min,tmm->tm_sec);

    return 0;
}
