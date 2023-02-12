#pragma once
#include "Stocks.h"

class Simple : public Stock {
public:
	Simple(String = "", int = 0, int = 0, int = 0);
};

istream& operator>>(istream&, Simple&);