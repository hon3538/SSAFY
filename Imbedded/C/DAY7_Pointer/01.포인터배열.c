//int *p[3]={NULL,NULL,NULL};
//포인터가 여러개이다!

//int (*p)[5]; // 배열을 가리키는 포인터
#include <stdio.h>

int main(){
    
    char kfc='K';
    char moms='M';
    char bbq='B';

    char *p[4]={&kfc,&moms,&bbq,&moms};
    for(int i=0;i<4;i++){
        printf("%c\n",*p[i]);
    }
    return 0;
}
