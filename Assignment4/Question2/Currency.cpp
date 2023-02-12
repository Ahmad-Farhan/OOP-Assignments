#include "Currency.h"

Currency::Currency(const int a)
{
	amount = a;
	setID(1);
}
int Currency::getAmount() const
{
	return amount;
}
void Currency::setAmount(const int a)
{
	setMarketValue(0);
	setProfit(0);
	amount = a;
}

istream& operator>>(istream& input, Currency& A)
{
	int inp;
	cout << "Currency Asset" << endl
		<< "-------------------------------" << endl
		<< "Enter Original Cost : ";
	input >> inp;
	A.setAmount(inp);
	cout << "Enter Current Value : ";
	input >> inp;
	A.setMarketValue(inp);
	cout << "-------------------------------" << endl;
	A.CalulateProfit(A.getAmount());
	return input;
}