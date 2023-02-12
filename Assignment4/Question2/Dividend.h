#pragma once
#include "Stocks.h"
#include <iostream>
using namespace std;

class Dividend : public Stock {
	int dividend;
public:
	Dividend(String = "", int = 0, int = 0, int = 0);
	void CalculateDividend();
};
istream& operator>>(istream&, Dividend&);