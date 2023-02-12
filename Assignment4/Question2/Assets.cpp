#include "Assets.h"

Asset::Asset(int Mval, int Pro)
{
	MarketValue = Mval;
	Profit = Pro;
}
int Asset::getProfit() const
{
	return Profit;
}
int Asset::getMarketValue() const
{
	return MarketValue;
}
int Asset::getID() const
{
	return id;
}
void Asset::setID(const int ID)
{
	id = ID;
}
Asset Asset::getAsset() const
{
	return *this;
}
void Asset::setProfit(const int n)
{
	Profit = n;
}
void Asset::setMarketValue(const int n)
{
	MarketValue = n;
}
void Asset::CalulateProfit(const int n)
{
	Profit = MarketValue - n;
}