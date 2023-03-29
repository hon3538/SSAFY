#include <stdio.h>

struct Node{
    int a;
    struct { //구조체 이름이 필요하지 않기 때문에 생략
        int b1;
        int b2;
    }b;
    int c;
};
int main(){
    struct Node n;
    n.a=20;
    n.b.b1=50;
    n.b.b2=30;
    n.c=10;   

    //선택적 초기화 기능
    //C++에서 지원하지 않는 문법
    //리눅스 Device Driver 개발시 자주 사용되는 문법
    // struct Node v={
    //     .a=10,
    //     .c=30
    // }

    struct Node v={
        .a=10,
		.b={
			.b1=150,
			.b2=250
		},
        .c=30
    };

    KFC k={
    		.da=10,
    		.ga={
    				.ga_a=100,
    				.ga_b=200
    		},
			.dc={
					.dc_1=50,
					.dc_2=60
			}
    };
    return 0;
}