#pragma once
#include "Investor.h"
#include "Currency.h"
#include "Dividend.h"
#include "Simple.h"
#include "RealEstate.h"

class AssetManagementSystem {
	Investor* Admin;
public:
	void UseAssetmanagementSystem();
	void DisplayProfitsInfo();
	void DisplayComparison();
};