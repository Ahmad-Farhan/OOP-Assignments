#include "Sandwich.h"

Sandwich::Sandwich()
{
	name = nullptr;
	filling = nullptr;
	size = nullptr;
	price = 0.0;
	is_ready = false;
}

Sandwich::Sandwich(char* fillingVal, double priceVal)
{
	name = nullptr;
	size = nullptr;
	filling = fillingVal;
	price = priceVal;
	is_ready = false;
}

bool check_small(char* val)
{
	if (*val == 's' && *(val + 1) == 'm' && *(val + 2) == 'a' &&
		*(val + 3) == 'l' && *(val + 4) == 'l')
		return true;

	return false;
}

bool check_medium(char* val)
{
	if (*(val) == 'm' && *(val + 1) == 'e' && *(val + 2) == 'd' &&
		*(val + 3) == 'i' && *(val + 4) == 'u' && *(val + 5) == 'm')
		return true;

	return false;
}

bool check_large(char* val)
{
	if (*(val) == 'l' && *(val + 1) == 'a' && *(val + 2) == 'r' &&
		*(val + 3) == 'g' && *(val + 4) == 'e')
		return true;

	return false;
}

bool valid_Size(char* sizeval)
{
	if (check_small(sizeval) || check_medium(sizeval) || check_large(sizeval))
		return true;
	else
		return false;
}

Sandwich::Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status)
{
	name = nameVal;
	is_ready = ready_status;
	filling = fillingVal;
	price = priceVal;

	if (valid_Size(sizeVal))
		size = sizeVal;
}

Sandwich::Sandwich(const Sandwich& sandwich)
{
	name = sandwich.name;
	size = sandwich.size;
	is_ready = sandwich.is_ready;
	filling = sandwich.filling;
	price = sandwich.price;
}

void Sandwich::setFilling(char* fillingVal)
{
	filling = fillingVal;
}

void Sandwich::setPrice(double priceVal)
{
	price = priceVal;
}

void Sandwich::setName(char* nameVal)
{
	name = nameVal;
}

void Sandwich::setSize(char* sizeVal)
{
	if (valid_Size(sizeVal))
		size = sizeVal;
}

char* Sandwich::getFilling()
{
	return filling;
}

double Sandwich::getPrice()
{
	return price;
}

char* Sandwich::getName()
{
	return name;
}

char* Sandwich::getSize()
{
	return size;
}

void Sandwich::makeSandwich()
{
	if (filling)
		is_ready = true;
}

bool Sandwich::check_status()
{
	if (is_ready)
		return true;

	return false;
}