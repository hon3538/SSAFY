#include <stdio.h>

int main() {
	int vect[5] = { 1,2,3,4,5 };

	int *p = vect;
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(p + i));
	}

	//위 처럼 포인터 변수 하나로 배열을 받을 수도 있는데 굳이..배열포인터..?
	//위는 vect[0]의 주소를 가리킴, p++ 시에 4byte씩 넘어감
	printf("%p\n", p);
	p++;
	printf("%p\n", p);


	int(*s)[5]; //int size의 5개, 즉 단위 크기가 20byte가 됨
	//즉 (*s)는 배열 그자체이다.
	s = &vect;
	printf("%p\n", s);
	s++;
	printf("%p\n", s);

	return 0;
}