#include "String.h"
#include "Database.h"
#pragma once

class Librarian {
	String Name;
	int ID;
	String Password;
	Book *book;
	Library_database &Database;
public:
	Librarian(Library_database &DB, String = "", String = "", int = 0);
	void setName(const String);
	void setID(const int);
	void setPassword(const String);
	String getName() const;
	String getPassword() const;
	int getID() const;
	void AddBooks(const int);
	bool Verify_Librarian(String id, String name, String pass);
	bool Search_book(String);
	Library_database openDatabase();
	void operator=(const Librarian);
	bool operator==(const Librarian);
};