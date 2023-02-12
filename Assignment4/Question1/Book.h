#pragma once
#include "String.h"
#include "Date.h"
#include "Page.h"

class Book {
	String Title;
	String Author;
	String ISBN;
	int Reserved;
	Date ResDate;
	Date DueDate;
	Page* Pages ;
public:
	Book(String = "" , String = "" , String = "" , int = 0 , int = 0);
	void setTitle(const String);
	void setAuthor(const String);
	void setISBN(const String);
	String getTitle() const ;
	String getAuthor() const;
	String getISBN() const;
	Date getDueDate() const;
	Date getResDate() const;
	int getReserved() const;
	void Show_due_date();
	void Reservation_status();
	void Book_request(int);
	void Renew_info();
	void ShowInfo();
	bool operator==(const Book);
};