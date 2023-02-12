#pragma once
#include"String.h"

class Transactions {
	String* History;
	int total;
public:
	Transactions(const int = 1);
	void setTotal(const int);
	void setHistory(String*);
	int getTotal() const;
	String* getHistory() const;
	void AddTransaction(const String&);
	void DisplayTransactions(const int = 0);
};