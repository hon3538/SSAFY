#include <stdio.h>

// void abc(int *p){
//     printf("%d",*p);
// }
void abc(void *v){
    //int p=*(int*)v;
    int *p=(int*)v;
    printf("%d",*p);
}
int main(){
    int x=0;
    char t='A';

    int* p1=&x;
    char* p2=&t;

    //어떤 타입의 주소도 모두 다 저장할 수 있는 만능 포인터
    void* p3=&x;
    void* p4=&t;
    //만능 포인터의 기능 : 주소 저장만 가능, 하지만 사용할 순 없다. 그냥 저장만 가능
    //printf("%d",*p3); -> 안됨.
    //형변환 해서 사용해야함
    //1: int *p=(int*)p3;  printf("%d",*p);
    //2: printf("%d",*(int*)p3);
    printf("%d",*(int*)p3);

    int x=10;
    abc(&x);

    return 0;
}