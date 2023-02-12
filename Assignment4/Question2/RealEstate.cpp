#pragma once
#include "RealEstate.h"

RealEstate::RealEstate(int area, int currentval, int year, int cost, String location)
{
	Location = location;
	Area = area;
	Currentvalue = currentval;
	YearOfPurchase = year;
	Cost = cost;
	setID(2);
}
String RealEstate::getAddress() const
{
	return Location;
}
int RealEstate::getArea() const
{
	return Area;
}
int RealEstate::getCost() const
{
	return Cost;
}
int RealEstate::getCurrentValue() const
{
	return Currentvalue;
}
int RealEstate::getYearOfPurchase() const
{
	return YearOfPurchase;
}
void RealEstate::setLocation(String A)
{
	Location = A;
}
void RealEstate::setArea(int n)
{
	Area = n;
}
void RealEstate::setCost(int n)
{
	Cost = n;
}
void RealEstate::setYearOfPurchase(int year)
{
	YearOfPurchase = year;
}
void RealEstate::setCurrentValue(int current)
{
	Currentvalue = current;
}
istream& operator>>(istream& input, RealEstate& A)
{
	string in;
	int inp;
	cout << "Real Estate" << endl
		<< "-------------------------------" << endl
		<< "Enter Location of Estate : ";
	input >> in;
	A.setLocation(in);
	cout << "Enter Total Area of Estate(sq. meters) : ";
	input >> inp;
	A.setArea(inp);
	cout << "Enter Original Cost of Estate : ";
	input >> inp;
	A.setCost(inp);
	cout << "Enter The Year of Purchase : ";
	input >> inp;
	A.setYearOfPurchase(inp);
	cout << "Enter Current Market Value : ";
	input >> inp;
	A.setMarketValue(inp);
	cout << "-------------------------------" << endl;

	A.CalulateProfit(A.getCost());

	return input;
}