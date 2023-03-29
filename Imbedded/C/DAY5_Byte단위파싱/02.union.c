// union 사용하는 이유?
// 파싱할 때 편하게 할 수 있다.
#include <stdio.h>
#include <stdint.h>
typedef union _ABC_{
    int a;
    int b;
    int c;
}ABC;

typedef union _BYTE_{
    uint32_t a;
    uint8_t b[4];
}BYTE;

typedef union _HONG_{
    uint64_t a;
    uint8_t b[8];
}HONG;


int main(){
    ABC x;
    x.a=10;
    x.b=20;
    //union으로 받으면 x.a와 x.b 둘 다 20이 들어있다. why?
    //union은 멤버끼리 값을 공유한다
    //a에 값을 넣어도, b에 값을 넣어도... 아무곳에 넣어도 다 공유 된다.
    //멤버 변수끼리 같은 메모리를 쓴다.

    //그럼 왜 사용하는 지?
    //Byte 단위의 파싱을 편리하게 할 수 있다.
    BYTE b;
    b.a=0x1234ABCD; // 리틀엔디안 방식으로 저장되어 있음

    //유니온 안 쓰고 파싱해보기
    uint64_t g=0xABCD12345678CD01;
    uint8_t buf[8];
    for(int i=0;i<8;i++){
        buf[i]=(g>>i*8)&0xff;
    }
    for(int i=0;i<8;i++){
            printf("%02x\n",buf[i]);
    }

    //유니온으로 파싱해보기
    HONG h;
    h.a=0xABCD12345678CD01;
    for(int i=0;i<8;i++){
            printf("%02x\n",h.b[i]);
    }
    return 0;
}
