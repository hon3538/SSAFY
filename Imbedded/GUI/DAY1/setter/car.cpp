#include "car.h"

void Marine::attack()
{
	cout << "attack" << endl;
}

void Marine::move()
{
	cout << "move" << endl;
}

void Marine::showStatus()
{
	cout << "hp:" << hp << " speed:" << speed << endl;
}

void Marine::setHP(int n)
{
	hp = n;
}
