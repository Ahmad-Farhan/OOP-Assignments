#include <iostream>
#include "CustomerAccount.h"
using namespace std;

void GenerateAccountVal(int accountsOpen, char* res)
{
	*res = 'P';
	*(res + 1) = 'K';
	for (int i = 2; i < 6; i++)
		*(res + i) = '0';

	if (accountsOpen > 10)
	{
		*(res + 4) = accountsOpen % 9 + 49;
		*(res + 3) = accountsOpen / 10 + 48;
	}
	else if (accountsOpen < 10)
		*(res + 4) = accountsOpen + 49;
	else if (accountsOpen == 100)
		*(res + 2) = '1';

	*(res + 5) = '\0';
}

void OpenCustomerAccount(CustomerAccount* customers[], int& accountsOpen, char* NameVal, char* addVal, char* cityVal, char* stateVal, int zipcodeVal, long long phoneVal, float balanceVal)
{
	if (accountsOpen >= 100)
		return;

	customers[accountsOpen] = new CustomerAccount;
	customers[accountsOpen]->name = NameVal;
	customers[accountsOpen]->address.address = addVal;
	customers[accountsOpen]->address.city = cityVal;
	customers[accountsOpen]->address.state = stateVal;
	customers[accountsOpen]->address.zip_code = zipcodeVal;
	customers[accountsOpen]->phoneNum = phoneVal;
	customers[accountsOpen]->balance = balanceVal;
	GenerateAccountVal(accountsOpen, customers[accountsOpen]->accountNum);
	accountsOpen++;
}

bool check_equal(char* required, char* given)
{
	for (int i = 0; i < 5; i++)
		if (*(required + i) != *(given + i))
			return false;

	return true;
}

bool ValidSearch(char* search)
{
	if (*(search + 2) > '0' && *(search + 4) > '0')
		return false;
	else if (*(search + 2) == '1' && *(search + 4) > '0')
		return false;

	return true;
}

int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char* accountNum)
{
	if (ValidSearch(accountNum))
	{
		for (int i = 0; i < accountsOpen; i++)
		{
			if (check_equal(customers[i]->accountNum, accountNum))
				return i;
		}
	}
	return (-1);
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, Address addressVal)
{
	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1)
	{
		customers[index]->address = addressVal;
		return true;
	}
	return false;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, long long phoneVal)
{
	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1)
	{
		customers[index]->phoneNum = phoneVal;
		return true;
	}
	return false;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, float balanceVal)
{
	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1)
	{
		customers[index]->balance = balanceVal;
		return true;
	}
	return false;
}

void DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen)
{
	cout << "Customer Accounts Information" << endl
		<< "**--------------------------------------**" << endl;
	for (int i = 0; i < accountsOpen; i++)
	{
		cout << "Name : " << customers[i]->name << endl
			<< "Address : " << customers[i]->address.address << endl
			<< "State : " << customers[i]->address.state << endl
			<< "City : " << customers[i]->address.city << endl
			<< "ZIP Code : " << customers[i]->address.zip_code << endl
			<< "Phone Number : " << customers[i]->phoneNum << endl
			<< "Balance : " << customers[i]->balance << endl
			<< "Account Num : " << customers[i]->accountNum << endl
			<< " --------------------------------- " << endl;
	}
}