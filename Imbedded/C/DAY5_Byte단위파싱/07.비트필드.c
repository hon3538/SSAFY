//특정 bit만 사용하는 멤버변수

#include <stdio.h>

int main(){
    struct Node1{
        uint8_t a :2; //uint8_t 중에서 2비트만 사용
        uint8_t b :4; //uint8_t 중에서 4비트만 사용
        uint8_t c :1; //uint8_t 중에서 1비트만 사용
    };
    // 1byte 사용
    struct Node2{
        uint8_t a :2; //uint8_t 중에서 2비트만 사용
        uint8_t b :5; //uint8_t 중에서 4비트만 사용
        uint8_t c :2; //uint8_t 중에서 1비트만 사용
    };
    //2byte 사용
    struct Node2{
        uint16_t a :3; //uint8_t 중에서 2비트만 사용
        uint8_t b :2; //uint8_t 중에서 4비트만 사용
        uint8_t c :5; //uint8_t 중에서 1비트만 사용
    };
    //3byte 사용
    //uint16_t 타입, 2Byte잡아먹고 그중 3bit 사용
    //그 다음 타입이 달라진다면 새롭게 byte사용함
    //따라서 2바이트중 3비트, 1바이트 중 7개 비트 사용하므로
    //3바이트 필요
}