#include<iostream>
using namespace std;

// 가상함수 테이블, 함수 포인터

class Phone {
public :
	virtual void call() { // virtual 은 나중에 다형성을 위함

	}
};
class SmartPhone : public Phone {
public:
	void internet() {
		cout << "connecting...\n";
	}
	void call() override { //cal1 이런식으로 잘못 쳐질 수 있기 때문에 무조건 override 돼야한다는 의미에서 override를 붙여줌 -> 무조건 안전하게 방어적으로 코딩하는게 좋음
		cout << "smart calling..." << endl;
	}
};
int main(){
	SmartPhone* s = new SmartPhone();
	Phone* b = new SmartPhone(); //-> 가능, SmartPhone에는 internet()과 call()이 다 구현되어 있고, Phone에서는 call()만 사용하기 때문에 가능
	SmartPhone* c= new Phone(); //-> 불가능 , internet()이 Phone에서 구현되지 않았는데 SmartPhone에서는 선언이 되어 있으므로 불가능..
	
	s->call();
	return 0;
}