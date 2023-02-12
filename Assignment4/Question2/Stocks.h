#pragma once
#include "String.h"
#include "Assets.h"

class Stock : public Asset{
	String Symbol;
	int Shares;
	int Cost;
	int CurrentPrice;
public:
	Stock(String = "", int = 0, int = 0, int = 0);
	void setSymbol(const String);
	void setShares(const int);
	void setCosts(const int);
	void setCurrentPrice(const int);
	String getSymbol() const;
	int getCurrentPrice() const;
	int getShares() const;
	int getCost() const;
};