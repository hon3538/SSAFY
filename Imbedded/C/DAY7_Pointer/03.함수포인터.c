#include <stdio.h>
#include <string.h>

void bbq() {
	printf("BBQ\n");
}
int moms(int x) {
	return x + 10;
}

int main() {
	//함수포인터는 소괄호로 묶어준다.
	void (*b)();
    b=&bbq;
	int (*m)(int x) = &moms;

	(*b)();
	printf("%d\n",(*m)(5));
	return 0;
}