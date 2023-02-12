#pragma once
#include "Assets.h"
#include <iostream>
using namespace std;

class Currency : public Asset{
	int amount;
public:
	Currency(const int = 0);
	int getAmount() const;
	void setAmount(const int);
};

istream& operator>>(istream&, Currency&);