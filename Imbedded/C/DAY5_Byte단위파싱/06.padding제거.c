#include <stdio.h>

#pragma pack(1);
struct Node{
    int a;
    char b;
}kfc;

#pragma pack(4);

int main(){
    printf("%d",sizeof(kfc));
    //4+1 =5 가아닌 8byte를 할당한다.. 왜?
    //CPU는 4byte 단위로 읽을 수 있다
    //char를 첫번째바이트에 저장하고 int를 2~5번째에 저장하면
    //int를 읽기 위해서는 1~4 한 번 읽고 5~8까지해서 두 번읽어야한다.   
    //속도저하 이슈..   
    
    //따라서 padding을 넣어서 4바이트 단위로 맞춰준다.
    //그런데 padding을 넣어서 바이트 단위를 맞추면 메모리가 순서대로
    //저장되지 않을 수 있다. (컴파일러의 메모리 할당방식에 따라 다름)
    //따라서 Parsing을 할 때, padding때문에 골치아파진다.
    //Parsing을 위해서 이 padding을 없애야 한다.

    // #pragma pack(1) -> 해당 코드 밑으로 구조체들은 패딩을 사용하지 않음
    // #pragma pack(4) -> 원상복구 방법
    // 따라서 바이트 파싱할 때는 pack(1)으로 세팅한 범위 내에 struct를 만들자!


}