#include <stdio.h>
#include <stdlib.h>  

int main(){
    char *s1 = "0xaf10";    // "0xaf10"은 문자열
    int num1;

    num1 = strtol(s1, NULL, 16);    // 16진법으로 표기된 문자열을 정수로 변환

    printf("%x %d\n", num1, num1);  // af10 44816

    return 0;
}