// C 기준 static 사용 이유
//1) 함수 내 지역 변수 앞에 사용 -> 전역변수처럼 사용하기 위함
//2) 전역변수 앞 -> 다른 소스코드에서 사용 불가
//3) 함수 앞 -> 다른 소스코드에서 사용 불가 (함수는 default가 extern)



void abc(){
    static int cnt;
    for(int i=0;i<5;i++) cnt++;
}
int main(){
    abc();
    abc();
    abc();
    //cnt 는 15가 됨.
}