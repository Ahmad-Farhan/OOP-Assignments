#include <iostream>
using namespace std;

int main()
{
	char decision;
	cout << "Welcome to Fast Banking System" << endl
		<< "A. Create a New Account" << endl
		<< "B. Operations over existing customers." << endl
		<< "\t1. Generate Mini Statement of a Bank Customer." << endl
		<< "\t2. Withdraw money from a customer account." << endl
		<< "\t3. Deposit money." << endl
		<< "\t4. Balance Inquiry" << endl
		<< "\t5. Transaction history" << endl
		<< "\t6. Any other operations you can think of." << endl
		<< "C.Generate the list of all customers with account types and their balance." << endl
		<< "Enter Decision : ";
	cin >> decision;

	return 0;
}