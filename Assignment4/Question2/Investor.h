#pragma once
#include "Assets.h"
#include "String.h"

class Investor {
	String Name;
	int total;
	Asset** assets;
public:
	Investor(String = "", int = 0);
	String getName() const;
	int getTotal() const;
	void AddAssetSpace();
	Asset* getAsset(int i) const;
	void BuyAsset(Asset&);
	void SellAsset(Asset&);
	void ComputeProfit();
	void DisplayCurrentValue();
	void operator=(const Investor&);
	void Display();
};