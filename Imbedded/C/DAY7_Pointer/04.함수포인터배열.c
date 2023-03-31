#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}
int gop(int a, int b) {
	return a * b;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int(*p[4])(int,int) = { &sum,&gop,&sum,&gop };
	for (int i = 0; i < 4; i++) {
		printf("%d\n", (*p[i])(a, b));
	}
	return 0;
}