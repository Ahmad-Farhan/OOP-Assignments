#include "Investor.h"

Investor::Investor(String name, int size) : Name(name)
{
	total = size;
	assets = new Asset * [total];

	for (int i = 0; i < total; i++)
		assets[i] = nullptr;

	assets[0] = nullptr;
}
String Investor::getName() const
{
	return Name;
}
int Investor::getTotal() const
{
	return total;
}
void Investor::AddAssetSpace()
{
	Asset** Res = new Asset * [total+1];
	for (int i = 0; i < total; i++)
		Res[i] = assets[i];

	total++;
	Res[total-1] = nullptr;
	assets = Res;
}
void Investor::BuyAsset(Asset& asset)
{
	AddAssetSpace();
	for (int i = 0; i < total; i++)
	{
		if (assets[i] == nullptr)
		{
			assets[i] = &asset;
			cout << "Asset Bought Successfully" << endl;
			return;
		}
	}
	cout << "Failed to Buy Asset" << endl;
}
void Investor::SellAsset(Asset& asset)
{
	int profit = 0;
	for (int i = 0; i < total; i++)
	{
		if (assets[i] == &asset)
		{
			profit = assets[i]->getProfit();
			assets[i] = nullptr;
			return;
		}
	}
	cout << "Profit Made Upon Selling Stock" << profit << endl;
}
void Investor::ComputeProfit()
{
	int profit = 0;
	for (int i = 0; i < total; i++)
	{
		profit += assets[i]->getProfit();
	}
	cout << "Total Profit on All Assets = " << profit << endl;
}

void Investor::DisplayCurrentValue()
{
	cout << "\nMarket Values of all Assets " << endl
		<< "---------------------------------" << endl;

	for (int i = 0; i < total; i++)
	{
		string AssetType;
		if (assets[i]->getID() == 1)
			AssetType = { "Currency" };
		if (assets[i]->getID() == 2)
			AssetType = { "Real Estate" };
		if (assets[i]->getID() == 3)
			AssetType = { "Dividend Stock" };
		if (assets[i]->getID() == 4)
			AssetType = { "Simple Stock" };

		cout <<	"Market Value of " << AssetType << " = " << assets[i]->getMarketValue() << endl;
	}
}
Asset* Investor::getAsset(int i) const
{
	return assets[i];
}

void Investor::operator=(const Investor& A)
{
	Name = A.getName();
	total = A.getTotal();
}