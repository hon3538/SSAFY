#include<iostream>
using namespace std;

class Something {
	//가상함수 = 구현부가 없는 함수
	virtual void func() = 0;
};
int main(){
	Something* a=new Something(); //가상함수밖에 없기 때문에 인스턴스 못만듦
	a.func();
	return 0;
}