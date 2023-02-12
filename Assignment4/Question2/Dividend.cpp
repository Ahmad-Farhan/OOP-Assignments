#pragma once
#include "Dividend.h"

Dividend::Dividend(String syms, int shares, int costs, int price)
{
	setSymbol(syms);
	setCosts(costs);
	setShares(shares);
	setCurrentPrice(price);
	setID(3);
}

void Dividend::CalculateDividend()
{
	dividend = getShares() * 100;
}

istream& operator>>(istream& input, Dividend& A)
{
	int inp;
	string in;
	cout << "Dividend Stock" <<endl
		<< "-------------------------------" << endl
		<< "Enter Dividend Stock Symbol : ";
	input >> in;
	A.setSymbol(in);
	cout << "Enter Cost of Dividend Stock : ";
	input >> inp;
	A.setCosts(inp);
	cout << "Enter No. of Shares : ";
	input >> inp;
	A.setShares(inp);
	cout << "Enter Current Price of Stock : ";
	input >> inp;
	A.setCurrentPrice(inp);
	cout << "-------------------------------" << endl;

	A.setMarketValue(A.getShares() * A.getCurrentPrice());
	A.CalculateDividend();
	A.CalulateProfit(A.getCost() * A.getShares());

	return input;
}