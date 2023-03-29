#include <stdio.h>

struct ABC {
    int a;
    int b;
}tt;
//타입을 만들자마자 변수선언 가능

struct KFC{
    int m1;
    char m2;
    int m3[5];
}a;

//아예 첨부터 이름 이렇게 해놓고 typedef 해주는 방법이 많이 사용됨
struct _BBQ_{
    int m1;
    char m2;
};
typedef struct _BBQ_ BBQ;

typedef struct _BBQ2_{
	int m1;
	char m2;
}bbq;
//bbq가 type임

int main(){
    struct ABC t;
    // C언어는 struct를 꼭 붙여줘야 한다.
    t.a=10;
    t.b=20;
    tt.a=20;
    tt.b=22;

    struct KFC b;
    BBQ c;
    //C++은 가능하지만 C언어는 불가능한 문법. 따로따로 초기화 해줘야함
    //a={1,'h',{1}};

    b.m3[2]=3;
    c.m1=111;

    bbq bbq1={1,'h'};
    return 0;
}

//C
//1. 선택적 초기화 됨. 유용함
//C++
//1. strcut 키워드 생략가능
//2. 선언한 이후에, 초기화 가능

//구조체 변수 = 구조체 생성과 동시에 변수 생성 가능
