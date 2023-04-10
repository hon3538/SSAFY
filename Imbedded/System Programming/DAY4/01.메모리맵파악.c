#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int t;
int g=32;

int main(){
    int q=31;
    int *p=(int*)malloc(4);
    while(1){
        printf("DATA(%d) =%llX\n",g,&g);
        printf("BSS = %llX\n",&t);
        printf("HEAP = %llX\n",p);
        pritnf("STACK = %llX\n",&q);
        printf("================\n");
        sleep(1);
        g++;
    }
    return 0;
}