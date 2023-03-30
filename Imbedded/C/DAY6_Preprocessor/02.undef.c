#define bbq 10
int main(){
    int a=bbq;
#undef bbq
//정의된 매크로를 해제

//매크로 재정의하여 매크로 충돌 방지
#define bbq 20
    int b=bbq;

    return 0;
}