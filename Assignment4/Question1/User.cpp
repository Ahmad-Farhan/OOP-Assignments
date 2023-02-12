#include "User.h"

User::User(const String name, const String id, int a, int b, int c)
{
	Name = name;
	ID = id;
	Acc = { a , b , c };
}

void User::setName(const String name)
{
	Name = name;
}

void User::setID(const String id)
{
	ID = id;
}

void User::setAccount(int a, int b, int c)
{
	Acc.setBorrow(a);
	Acc.setLost(b);
	Acc.setReserved(c);
}

String User::getName() const
{
	return Name;
}

String User::getID() const
{
	return ID;
}

Account& User::getAccount()
{
	return Acc;
}

bool User::Verify(const String name, const String id)
{
	return (Name == name && ID == id);
}

bool User::Check_account(const Account& other)
{
	return (&Acc == &other);
}

void User::get_book_info()
{
	cout << "Account Information" << endl
		<< "No. of Borrowed Books : " << Acc.getBorrowed() << endl
		<< "No. of Lost Books : " << Acc.getLost() << endl
		<< "No. of Reserved Books" << Acc.getReserved() << endl
		<< "Calculate Fine : " << Acc.getFine() << endl;
} 