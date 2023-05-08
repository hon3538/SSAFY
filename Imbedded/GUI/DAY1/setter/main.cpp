#include "car.h"
int main() {
	Marine* m = new Marine();
	m->attack();
	m->move();
	m->showStatus();
	m->setHP(100);
	m->showStatus();
	return 0;
}