#include "Address.h"

Address::Address(String H, String S, String T, String C)
{
	this->HouseNo = H;
	this->StreetNo = S;
	this->Town = T;
	this->City = C;
}
void Address::setHouseNo(const String H)
{
	HouseNo = H;
}
void Address::setStreetNo(const String S)
{
	StreetNo = S;
}
void Address::setTown(const String T)
{
	Town = T;
}
void Address::setCity(const String C)
{
	City = C;
}
String Address::getHouseNo() const
{
	return HouseNo;
}
String Address::getStreetNo() const
{
	return StreetNo;
}
String Address::getTown() const
{
	return Town;
}
String Address::getCity() const
{
	return City;
}
void Address::Display()
{
	cout << "Address Information" << endl
		<< "House No. " << HouseNo << endl
		<< "StreetNo. " << StreetNo << endl
		<< "Town : " << Town << endl
		<< "City : " << City << endl;
}