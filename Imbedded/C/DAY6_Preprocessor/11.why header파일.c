#include "12.source.c"

void abc(){
    printf("#");
}

int main(){

    return 0;
}

/* 아래는 12.source.c
#include <stdio.h>
#include <stdlib.h>

void abc();
*/

//이처럼 c파일로 include 해도 에러없이 빌드함
//근데 왜 header 파일 사용할 까?

#include "12.source.c"

int main(){

    return 0;
}
/* 12.source.c
int y=35;
int x=44;
*/

//위의 경우를 가정해보자, 전처리와 컴파일까지 문제없이 된다.
//근데 Link 과정에서 error가 발생한다.
//Link는 c파일을 하나의 프로그램으로 합치기 때문에
//main에 include 되어 y,x 가 정의 되어있는데, 또 12.source.c 파일을
//합치기 때문에 중복 정의가 되어 에러가 발생한다.

// .c파일과 header 파일의 차이점
// 전처리기는 둘을 구분하지 않는다.
// header는 컴파일이 안 된다. (확장자로 컴파일 여부를 구분)
// 따라서 가져와서 전처리만 하고 컴파일에서는 내용이 쏙 빠져서
// 메인문에민 그대로 들어가고 중복은 되지 않는다.
