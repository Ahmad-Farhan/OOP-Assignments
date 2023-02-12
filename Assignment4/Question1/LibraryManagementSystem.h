#pragma once
#include "String.h"
#include "Student.h"
#include "Staff.h"
#include "Book.h"
#include "Librarian.h"
#include "Database.h"

class LibraryManagementSystem {
	int UserType;
	String UserName;
	String Password;
	bool login;

	int BookNo = 0;
	int UserNo = 0;
	Book *Books = nullptr;
	User **Users = nullptr;
	Librarian *librarian = nullptr;
	Library_database *Database = nullptr;
public:
	LibraryManagementSystem(const int = 0, const String = "" , const String = "");
	void setUserType(const int );
	void setUserName(const String);
	void serPassword(const String);
	int getUserType() const;
	String getUserName() const;
	String getPassword() const;
	Librarian getLibrarian(String) const;
	User getUser(String) const;
	void AddStudent(const String ,const String, const String , const String);
	void AddStaff(const String, const String, const String , const String);
	void AddBookSpace(const int = 0);
	void AddBook(const String = "", const String = "", const String = "", int = 0, int = 0);
	void IssueBook(const String, const int, const String , const String = "", const String = "", const String = "");
	void ReturnBook(const String, const String, const String = "", const String = "", const String = "");
	void ShowInfo(const String, const String, const String = "", const String = "", const String = "");
	bool Login(String id, const int, String pass);
	bool Register(const String, const int , const String);
	bool Logout();
};