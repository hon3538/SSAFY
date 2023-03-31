//argc : main()에 전달되는 정보의 개수
//argv[]: main()에 전달되는 정보, 첫 번째 문자열은 실행 경로로 고정

//해당 프로그램을 cmd 실행할때, 또는 리눅스에서
//Project1.exe hello euiseon hong
//으로 인자를 넘겨줄 수 있다
//argc =4, argv[0~3] 까지 Project1.exe hello euiseon hong 이 각각 들어간다.
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("argc=%d\n", argc);
	printf("argv=%s\n", argv[0]);
}