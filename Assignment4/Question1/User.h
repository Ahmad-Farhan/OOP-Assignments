#include "String.h"
#include "Account.h"
#pragma once

class User {
	String Name;
	String ID;
	Account Acc;
public:
	User(const String = "" , const String = "",int = 0, int = 0, int = 0);
	void setName(const String);
	void setID(const String);
	void setAccount(int, int, int);
	String getName() const;
	String getID() const;
	//Account getAccount() const;
	Account& getAccount();
	bool Verify(const String,const String);
	bool Check_account(const Account&);
	void get_book_info();
};