#include <stdio.h>
#include <stdint.h>
int main(){

#pragma pack(1)
    struct Data{ //0번비트부터 순차적으로 넣는다 (ccbbbaaa)
    //메모리에는 바이트 단위로는 그대로 들어간다.
        uint8_t a :3;
        uint8_t b :3;
        uint8_t c :2;
    }d;
    d.a=3; // 011
    d.b=6; // 110
    d.c=1; // 01
    //(01111001)  -> 메모리(01 110 011) 0x73
    printf("%d",sizeof(d)); //1byte

    //특정 비트를 지칭할 대는 [큰 bit번호 : 작은 bit번호] 로함
    //[5:2] -> 2번째 비트부터 5번째 비트까지

    uint8_t data=0x73; // 0111 0011
    union Node{
    	uint8_t ori;
    	struct{
    		uint8_t a : 1; //0비트
    		uint8_t b : 5; //1~5비트
    		uint8_t c : 1; //6비트
    		uint8_t d : 1; //7비트
    	}e;
    }a;
    a.ori=data;
    return 0;
}
