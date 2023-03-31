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
// 메인문에만 그대로 들어가고 중복은 되지 않는다.

//따라서 header 에는 정의를 하지 않고 선언만 한다 -> 중복 코드가 있어도 상관없는 코드들을 삽입

//main문제서는 함수 사용만 하면, include 된 header 파일에 함수가 선언이 되었는지 확인하고
//정의된 곳을 찾아준다.. (main.c 가 아닌 다른 .c 파일들의 함수는 default가 extern이라 header가 찾을 수 있다)