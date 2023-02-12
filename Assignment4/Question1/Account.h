#include "String.h"
#pragma once

class Account {
	int no_borrowed_books;
	int no_lost_books;
	int no_reserved_books;
	float fine_amount;
public:
	Account(int = 0, int = 0, int = 0);
	void setBorrow(const int);
	void setLost(const int);
	void setReserved(const int);
	int getBorrowed() const;
	int getLost() const;
	int getReserved() const;
	int getFine() const;
	void Calculate_fine(int);
};