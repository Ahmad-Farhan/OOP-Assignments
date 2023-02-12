#include"AssetManagementSystem.h"

void AssetManagementSystem::UseAssetmanagementSystem()
{
	Admin = new Investor{"Ahmad"};

	cout << "Welcome to Asset management System\n" << endl;

	Simple SStock;
	cin >> SStock;
	cout << endl;

	Dividend DStock;
	cin >> DStock;
	cout << endl;

	RealEstate REstate;
	cin >> REstate;
	cout << endl;

	Currency PKR;
	cin >> PKR;
	cout << endl;

	Admin->BuyAsset(SStock);
	Admin->BuyAsset(DStock);
	Admin->BuyAsset(REstate);
	Admin->BuyAsset(PKR);

	Admin->SellAsset(SStock);
	//Admin->ComputeProfit();
	DisplayProfitsInfo();
}

void AssetManagementSystem::DisplayProfitsInfo()
{
	for (int i = 0; i < Admin->getTotal(); i++)
	{
		string AssetType;
		if (Admin->getAsset(i)[0].getID() == 1)
			AssetType = { "Currency" };
		if (Admin->getAsset(i)[0].getID() == 2)
			AssetType = { "Real Estate" };
		if (Admin->getAsset(i)[0].getID() == 3)
			AssetType = { "Dividend Stock" };
		if (Admin->getAsset(i)[0].getID() == 4)
			AssetType = { "Simple Stock" };

		cout << "\nProfit From " << AssetType << " = " << Admin->getAsset(i)->getProfit();
	}
	
	Admin->DisplayCurrentValue();

	DisplayComparison();
}

void AssetManagementSystem::DisplayComparison()
{
	int index=0,max = 0;
	for (int i = 0; i < Admin->getTotal(); i++)
	{
		if (Admin->getAsset(i)->getProfit() > max)
		{
			max = Admin->getAsset(i)->getProfit();
			index = i;
		}
	}
	string AssetType;
	if (Admin->getAsset(index)[0].getID() == 1)
		AssetType = { "Currency" };
	if (Admin->getAsset(index)[0].getID() == 2)
		AssetType = { "Real Estate" };
	if (Admin->getAsset(index)[0].getID() == 3)
		AssetType = { "Dividend Stock" };
	if (Admin->getAsset(index)[0].getID() == 4)
		AssetType = { "Simple Stock" };

	cout << "\nMost Profit From " << AssetType << " = " << max << endl;
}