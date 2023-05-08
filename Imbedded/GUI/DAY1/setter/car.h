#ifndef __CAR__
#define __CAR__

#include <iostream>
using namespace std;

class Marine{
private:
	int hp=40;
	int power=6;
	int speed=1.875;
public:
	void attack();
	void move();
	void showStatus();

	void setHP(int n);
	void setPower();
	void setSpeed();
};
#endif	