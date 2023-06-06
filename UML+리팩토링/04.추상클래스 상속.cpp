#include<iostream>
using namespace std;

class Base {
public:
	virtual void func0() = 0;
	virtual void func1() = 0;
	virtual void func2() = 0;
	virtual void func3() = 0;
};
class Derived :public Base {

};
int main(){
	//가상함수가 있는 클래스(추상클래스)를 상속받으면 무조건 자식클래스에서 재정의를 해주도록
	//강제할 수 있다. 재정의를 하지 않으면 에러가 발생
	//즉 Base를 상속받는 클래스들은 무조건 해당 가상함수들의 구현부를 만들어줘야하기 때문에
	// Base는 interface역할을 한다.
	Derived a{};
	return 0;
}