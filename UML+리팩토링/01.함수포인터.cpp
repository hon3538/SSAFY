#include<iostream>
using namespace std;

void abc() {

}
void bbq() {

}
int main(){
	void(*fptr)();
	int n;
	cin >> n;

	if (n == 1) fptr = abc;
	else fptr = bbq;

    //fptr만 한번만 업데이트 해주면 아래에 모든 함수의 동작을 한번에 바꿀 수 있다.
    
	return 0;
}