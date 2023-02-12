#include "Car.h"
//using namespace std;

Car::Car()
{
	petrolLevel = 0;
}

Car::Car(int petrolLevelVal)
{
	petrolLevel = petrolLevelVal;
}

void Car::setPetrolLevel(int petrolLevelVal)
{
	if (petrolLevelVal <= 45 && petrolLevelVal >= 0)
		petrolLevel = petrolLevelVal;
}

int Car::getPetrolLevel()
{
	return petrolLevel;
}

bool Car::MoveCar(int distanceKM)
{
	if (petrolLevel >= distanceKM)
	{
		petrolLevel -= distanceKM;
		return true;
	}

	return false;
}

void Car::Refill()
{
	petrolLevel = 45;
}

bool Car::isEmpty()
{
	if (petrolLevel <= 0)
		return true;

	return false;
}