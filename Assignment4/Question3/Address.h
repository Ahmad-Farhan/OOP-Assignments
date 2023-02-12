#include "String.h"
#pragma once

class Address {
	String HouseNo;
	String StreetNo;
	String Town;
	String City;

public:
	Address(String = "", String = "", String = "", String = "");
	void setHouseNo(const String);
	void setStreetNo(const String);
	void setTown(const String);
	void setCity(const String);
	String getHouseNo() const;
	String getStreetNo() const;
	String getTown() const;
	String getCity() const;
	void Display();
};