#include "Stocks.h"

Stock::Stock(String symbol, int shares, int cost, int price) : Symbol(symbol)
{
	Shares = shares;
	Cost = cost;
	CurrentPrice = price;
}
void Stock::setSymbol(const String syms)
{
	Symbol = syms;
}
void Stock::setShares(const int shares)
{
	Shares = shares;
}
void Stock::setCosts(const int cost)
{
	Cost = cost;
}
void Stock::setCurrentPrice(const int price)
{
	CurrentPrice = price;
}
String Stock::getSymbol() const
{
	return Symbol;
}
int Stock::getCurrentPrice() const
{
	return CurrentPrice;
}
int Stock::getShares() const
{
	return Shares;
}
int Stock::getCost() const
{
	return Cost;
}