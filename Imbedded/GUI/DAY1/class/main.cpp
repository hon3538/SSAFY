//application
#include "car.h"

int main() {
	Car* car = new Car();
	car->go();
	car->gearDown();
	car->gearUP();
	return 0;
}