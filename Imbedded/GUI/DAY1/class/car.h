//interface

#pragma once
#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

class Car {
private:
	//멤버/필드/attribute
	int speed;
	int gear;
public:
	//메서드
	void go();
	void gearUP();
	void gearDown();
};
#endif