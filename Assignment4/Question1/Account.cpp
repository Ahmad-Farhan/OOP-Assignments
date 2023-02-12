#include "Account.h"

Account::Account(int a, int b, int c)
{
	no_borrowed_books = a;
	no_lost_books = b;
	no_reserved_books = c;
}

void Account::setBorrow(const int val)
{
	no_borrowed_books = val;
}

void Account::setLost(const int val)
{
	no_lost_books = val;
}

void Account::setReserved(const int val)
{
	no_reserved_books = val;
}

int Account::getBorrowed() const
{
	return no_borrowed_books;
}

int Account::getLost() const
{
	return no_lost_books;
}

int Account::getReserved() const
{
	return no_reserved_books;
}

int Account::getFine() const 
{
	return fine_amount;
}
void Account::Calculate_fine(int n)
{
	if (n < 0)
		this->fine_amount = 0;
	else
		this->fine_amount = 50 * no_lost_books + 50*n;
}