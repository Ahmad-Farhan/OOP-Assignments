#include "Librarian.h"

Librarian::Librarian(Library_database &DB, String name, String password, int id) : Database(DB)
{
	Name = name;
	ID = id;
	Password = password;
}

void Librarian::setName(const String name)
{
	this->Name = name;
}

void Librarian::setID(const int id)
{
	this->ID = id;
}

void Librarian::setPassword(const String password)
{
	this->Password = password;
}

String Librarian::getName() const
{
	return Name;
}

int Librarian::getID() const
{
	return ID;
}

String Librarian::getPassword() const
{
	return Password;
}

bool Librarian::Verify_Librarian(String name , String id , String pass)
{
	return (ID == id && Name == name && Password == pass);
}

bool Librarian::Search_book(String search)
{
	for (int i = 0; i < Database.getSize(); i++)
	{
		if (Database.getBook(i)->getAuthor() == search ||
			Database.getBook(i)->getTitle() == search ||
			Database.getBook(i)->getISBN() == search)
			return true;
	}
	return false;
}

void Librarian::AddBooks(const int num)
{
	Database.setSize(num);
}

void Librarian::operator=(const Librarian A)
{
	*this = A;
}

Library_database Librarian::openDatabase()
{
	return Database;
}