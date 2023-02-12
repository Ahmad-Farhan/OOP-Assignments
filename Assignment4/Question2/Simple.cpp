#include "Simple.h"

Simple::Simple(String symbol , int shares , int cost , int price)
{
	setSymbol(symbol);
	setShares(shares);
	setCosts(cost);
	setCurrentPrice(price);
	setID(4);
}
istream& operator>>(istream& input, Simple& A)
{
	int inp;
	string in;
	cout << "Simple Stock" << endl
		<< "-------------------------------" <<endl
		<< "Enter Simple Stock Symbol : ";
	input >> in;
	A.setSymbol(in);
	cout << "Enter Original Cost of Simple Stock : ";
	input >> inp;
	A.setCosts(inp);
	cout << "Enter Total No. of Shares : ";
	input >> inp;
	A.setShares(inp);
	cout << "Enter Current Price of Stock : ";
	input >> inp;
	A.setCurrentPrice(inp);
	cout << "-------------------------------" << endl;

	A.setMarketValue(A.getShares() * A.getCurrentPrice());
	A.CalulateProfit(A.getCost() * A.getShares());

	return input;
}