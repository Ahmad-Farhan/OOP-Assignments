#pragma once
#include "String.h"
#include "Address.h"
#include "Date.h"


class Holder {
	int Type;
	float Interest;
	String Firstname, Middlename, Lastname;
	String CNIC;
	Address address;
	String PhoneNumber;
	Date DateOfBirth;
	int AccountNumber;
public:
	Holder(int, const String, const String, const String, const Address&, const String , const String, const String, const String, int);
};
