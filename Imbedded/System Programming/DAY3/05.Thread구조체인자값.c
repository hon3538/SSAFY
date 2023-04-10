#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
struct Node{
    int y,x;
};
void *abc(void *p){
    struct Node *a=(struct Node*)p;
    while(1){
        printf("#%d %d\n",a->y,a->x);
        sleep(1);
    }
}
int main(){
    pthread_t t;
    struct Node n={1,2};

    pthread_create(&t,NULL,abc,&n);
    pthread_join(t,NULL);

    return 0;
}
