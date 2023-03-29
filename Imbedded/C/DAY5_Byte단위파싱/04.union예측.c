#include <stdio.h>
#include <stdint.h>
//한 유니온내에서 메모리를 똑같이 공유한다 ( 최대 메모리 기준)
union UNI1{
    struct {
        uint8_t a;
        uint8_t b;
    }d1;
    struct {
        uint8_t c;
        uint8_t d;
    }d2;
};
union UNI2{
    struct {
        uint8_t a;
        uint8_t b;
    }d1;
    uint16_t c;
};
union UNI3{
    union{
        struct {
            uint8_t a;
            uint8_t b;
        }d1;
        uint16_t c;
    };
    uint16_t d;
};
int main(){

    union UNI1 t1={0xAB,0xCD}; // 메모리에 AB CD로 저장
    //a=0xAB b=0xCD, c=0xAB, d=0xCD
    //총 2바이크 크기만 만들어진다.

    union UNI2 t2={9,10}; // 메모리에 09 0a 저장
    //a=0x09 b=0x0a c=0x0a09
    //c는 ab의 메모리를 공유하는데 리틀라디안이라서 읽을 때 반대로 꺼내온다

    union UNI t3={.d=0xABCD}; //메모리에 CD AB 로 저장
    //d=0xABCD, a=0xCD, b=0xAB, c=0xABCD
}