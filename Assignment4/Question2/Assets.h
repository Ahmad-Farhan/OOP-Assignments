#pragma once

class Asset {
	int MarketValue = 0;
	int Profit = 0;
	int id;
public:
	Asset(int = 0, int = 0);
	int getProfit() const;
	int getMarketValue() const;
	int getID() const;
	void setID(const int);
	void setProfit(const int = 0);
	void setMarketValue(const int = 0);
	void CalulateProfit(const int);
	Asset getAsset() const;
};