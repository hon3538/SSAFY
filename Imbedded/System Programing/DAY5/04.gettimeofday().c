#include <stdio.h>
#include <sys/time.h>

int main(){
    //time() 보다 훨씬 정밀하다 (us 단위로 시간 측정)
    //gettimeofday(struct timeval, timezone);
    // timezone은 구시대 방식이라 안 쓴다.
    struct timeval time;
    gettimeofday(&time,NULL);
    
    printf("%ld\n",time.tv_sec);
    printf("%ld\n",time.tv_usec);
    return 0;
}
