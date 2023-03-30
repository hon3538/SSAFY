//extern
//타 파일에 있는 자원 사용하기

int main(){
    t=10; //변수는 extern을 선언하지 않으면 타파일의 자원을 사용하지 않아 에러발생
    //extern int t;
    //t=10;
    abc(); //함수는 default가 extern이라 다른 자원을 가져옴
    return 0;
}
/* 소스.c
int t;
void abc(){

}
*/

//만약 타 파일에서 가져가는 것을 막고싶다면
//static을 이용한다.
/* 소스.c
static int t;
ststic void abc(){

}
*/