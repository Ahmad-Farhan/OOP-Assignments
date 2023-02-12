#pragma once
#include "Book.h"
#include "User.h"

class Library_database {
	Book** List_of_books = nullptr;
	Account** Accounts = nullptr;
	int size;
	int acc;
public:
	Library_database(int = 0);
	Library_database(Book**& list,Account**& Acc, int a, int b);
	void setDatabase(Book**);
	Book* getBook(int = 0) const;
	void setSize(int = 1);
	int getSize() const;
	Account* getAccount(int = 0) const;
	void setAcc(int = 1);
	int getAcc() const;
	Book** getDatabase() const;
	Account** getAccounts() const;

	void AddBookspace(const int);
	void AddBook(Book&);
	void DeleteBook(const String);
	void UpdateBook(const Book&, int);
	int SearchBook(const String);

	void AddAccountspace();
	void AddAccount(Account&);
	void DeleteAccount(const int);
	void UpdateAccount(const Account&, int);

	void Display();
};