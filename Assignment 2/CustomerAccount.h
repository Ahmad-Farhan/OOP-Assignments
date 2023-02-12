#pragma once

struct Address {
	char* address = nullptr;
	char* city = nullptr;
	char* state = nullptr;
	int zip_code = 0;
};

struct CustomerAccount {
	char* name = nullptr;
	Address address;
	long long phoneNum = 0;
	float balance = 0.0;
	char* accountNum = new char[6];
};

void OpenCustomerAccount(CustomerAccount* [], int&, char*, char*, char*, char*, int, long long, float);
int SearchCustomer(CustomerAccount* [], int, char*);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, Address);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, long long);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, float);
void DisplayAllCustomers(CustomerAccount* [], int);
void GenerateAccountVal(int , char*);
bool check_equal(char* , char*);
bool ValidSearch(char* );