#include<iostream>
using namespace std;

class Rifle {
public:
    //virtual은 다형성을 위해 사용함
    //없다면 자식에서 재정의한 shot을 사용하는 것이 아니라, 부모의 shot을 사용함
    //왜냐면 원래 컴파일 과정에서 이미 함수가 정해지는데, virtual을 사용함으로써 해당 함수는
    //실행상태(runtime)에서 정해지기 때문에 자식에서 재정의한 함수로 사용가능하게함.
	virtual void shot() {
		cout << "RIFLE\n";
	}
};
class Shotgun : public Rifle {
public:
	void shot() override {
		cout << "SHOTGUN\n";
	}
};
class Sniper : public Rifle {
public:
	void shot() override {
		cout << "SNIPER\n";
	}
};
int main(){
	Rifle* a = new Rifle();
	Rifle* b = new Sniper();
	Rifle* c = new Shotgun();
	a->shot();
	b->shot();
	c->shot();
	return 0;
}