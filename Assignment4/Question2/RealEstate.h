#pragma once
#include "String.h"
#include "Assets.h"
#include <iostream>
using namespace std;

class RealEstate : public Asset {
	String Location;
	int Area;
	int YearOfPurchase;
	int Cost;
	int Currentvalue;
public:
	RealEstate(int = 0, int = 0, int = 0, int = 0 , String = "");
	String getAddress() const;
	int getArea() const;
	int getCost() const;
	int getCurrentValue() const;
	int getYearOfPurchase() const;
	void setCost(int);
	void setArea(int);
	void setLocation(String);
	void setYearOfPurchase(int);
	void setCurrentValue(int);
};

istream& operator>>(istream&, RealEstate&);
