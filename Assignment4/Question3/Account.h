#pragma once
#include "String.h"
#include"Transactions.h"

class Account {
	const int type;
	int Balance;
	Transactions transactions;
public:
	Account();
	int getType() const;
	void WithDraw(const int);
	void Deposit(const int);

};