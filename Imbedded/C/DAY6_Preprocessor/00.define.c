#include <stdio.h>
//#define PAI 3.141592
int main() {
    //내부적으로 define 정의됨 __FILE__
	printf("File : %s\n", __FILE__);
	printf("Date : %s\n", __DATE__);
	printf("Time : %s\n", __TIME__);
	printf("Line : %d\n", __LINE__);
	return 0;
}