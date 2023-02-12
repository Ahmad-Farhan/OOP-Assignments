#include "Database.h"

Library_database::Library_database(int Size)
{
	this->size = Size;
	this->acc = 0;
	
	List_of_books = new Book * [size];
	Accounts = new Account * [acc];

	for (int i = 0; i < size; i++)
		List_of_books[i] = nullptr;

	for (int i = 0; i < acc; i++)
		Accounts[i] = nullptr;

	List_of_books[0] = nullptr;
	Accounts[0] = nullptr;
}

Library_database::Library_database(Book**& list, Account**& Acc, int a, int b)
{
	size = a;
	acc = b;
	List_of_books = new Book * [size];
	Accounts = new Account * [acc];

	for (int i = 0; i < size; i++)
		List_of_books[i] = list[i];

	for (int i = 0; i < acc; i++)
		Accounts[i] = Acc[i];
}

void Library_database::setSize(int val)
{
	val = size;
	Book** Res = new Book * [val];
	for (int i = 0; i < size; i++)
		Res[i] = List_of_books[i];

	delete List_of_books;
	List_of_books = Res;
}

int Library_database::getSize() const
{
	return size;
}

Book** Library_database::getDatabase() const
{
	return List_of_books;
}

void Library_database::setDatabase(Book** list)
{
	List_of_books = list;
}

Book* Library_database::getBook(int i) const
{
	return List_of_books[i];
}

Account* Library_database::getAccount(int i) const
{
	return Accounts[i];
}

void Library_database::setAcc(int i)
{
	acc = i;
}

int Library_database::getAcc() const
{
	return acc;
}

Account** Library_database::getAccounts() const
{
	return Accounts;
}

void Library_database::AddBookspace(const int Size)
{
	size += Size;

	Book** temp = new Book*[size];

	for (int i = 0; i < size; i++)
		temp[i] = nullptr;

	for (int i = 0; i < size - Size; i++)
		temp[i] = List_of_books[i];

	List_of_books = temp;
}

void Library_database::AddBook(Book &obj)
{
	Book* temp = &obj;
	for (int i = 0; i < size; i++)
	{
		if (List_of_books[i] == nullptr)
		{
			List_of_books[i] = temp;
			cout << "Book Added Successfully" << endl;
			return;
		}
	}
	cout << "Book Adding Failed" << endl;
}

int Library_database::SearchBook(const String search)
{
	for (int i = 0; i < size; i++)
	{
		if (List_of_books[i]->getAuthor() == search ||
			List_of_books[i]->getISBN() == search ||
			List_of_books[i]->getTitle() == search)
			return i;
	}
	return (-1);
}

void Library_database::DeleteBook(const String del)
{
	int index = SearchBook(del);
	if (index == -1)
	{
		cout << "Unable to Delete" << endl;
		return;
	}

	for (int i = index; i < size; i++)
	{
		List_of_books[i] = List_of_books[i + 1];
	}

	List_of_books[size - 1] = nullptr;
	size--;
	cout << "Successfully Deleted" << endl;
}

void Library_database::UpdateBook(const Book &obj , int index)
{
	if(index < size)
		List_of_books[index][0] = obj;
}

void Library_database::AddAccountspace()
{
	Account** temp = new Account * [++acc];

	for (int i = 0; i < acc; i++)
		temp[i] = nullptr;

	for (int i = 0; i < acc - 1; i++)
		temp[i] = Accounts[i];

	Accounts = temp;
}

void Library_database::AddAccount(Account &obj)
{
	for (int i = 0; i < size; i++)
	{
		if (Accounts[i] == nullptr)
		{
			Accounts[i] = &obj;
			cout << "Account Added Successfully" << endl;
			return;
		}
	}
	cout << "Account Adding Failed" << endl;
}

void Library_database::DeleteAccount(const int del)
{
	if (del > acc || del < 0) 
	{
		cout << "Unable to Delete" << endl;
		return;
	}

	for (int i = del; i < acc; i++)
	{
		Accounts[i] = Accounts[i + 1];
	}
	Accounts[acc - 1] = nullptr;
	acc--;
	cout << "Successfully Deleted" << endl;
}

void Library_database::UpdateAccount(const Account &obj, int index)
{
	if (index < acc)
		Accounts[index][0] = obj;
}

void Library_database::Display()
{
	cout << "Database Book Information" << endl;
	for (int i = 0; i < size; i++)
	{
		Book obj(List_of_books[i][0]);
		cout << "Title : " << obj.getTitle()
			<< "Author : " << obj.getAuthor()
			<< "ISBN : " << obj.getISBN() <<endl;
	}
}