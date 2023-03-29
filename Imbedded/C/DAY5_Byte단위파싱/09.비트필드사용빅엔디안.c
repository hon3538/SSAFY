//빅엔디안으로 들어온 데이터 파싱
#include <stdio.h>
#include <stdint.h>
int main(){
    uint16_t DA=0xF3B5;

    union par{
        uint16_t i;
        struct{
            uint16_t a:3;
            uint16_t b:3;
            uint16_t c:4;
            uint16_t d:6;
        }e;
    }p;
    p.i=DA;
    printf("%d %d %d %d",p.e.a,p.e.b,p.e.c,p.e.d);

    return 0;
}
