#include "Book.h"

Book::Book(String title, String author, String isbn , int num , int type)
{
	Title = title;
	Author = author;
	ISBN = isbn;
	Reserved = type;
	Pages = new Page[num];
	ResDate = { 0 , 0 , 0 };
	DueDate = { 0 , 0 , 0 };
}

void Book::setTitle(const String title)
{
	this->Title = title;
}

void Book::setAuthor(const String author)
{
	this->Author = author;
}

void Book::setISBN(const String isbn)
{
	this->ISBN = isbn;
}

String Book::getTitle() const
{
	return Title;
}

String Book::getAuthor() const
{
	return Author;
}

String Book::getISBN() const
{
	return ISBN;
}

Date Book::getDueDate() const
{
	return DueDate;
}

Date Book::getResDate() const
{
	return ResDate;
}

void Book::Show_due_date()
{
	//int D = 0;

	//if (Reserved == 1)
	//	D = 14;
	//if (Reserved == 2)
	//	D = 112;

	//Date DueDate(ResDate);
	//DueDate.AddDays(D);

	//cout << "Reserve Date : " << ResDate
	cout << "Due Date : " << DueDate;
}

void Book::Reservation_status()
{
	if (Reserved == 0)
		cout << "Book not Reserved" << endl;
	else
		cout << "Book Reserved" << endl;
}

int Book::getReserved() const
{
	return Reserved;
}

void Book::Book_request(int type)
{
	if (Reserved != 0)
	{
		cout << "Book Already Reserved" << endl;
		return;
	}

	cout << "Reserve Date : " << endl;
	cin >> ResDate;
	Reserved = type;

	int D = 0;
	if (Reserved == 1)
		D = 14;
	if (Reserved == 2)
		D = 112;

	DueDate = ResDate;
	DueDate.AddDays(D);
}

void Book::Renew_info()
{
	Reserved = 0;
	ResDate = { 0 , 0 , 0 };
	DueDate = { 0 , 0 , 0 };
}

void Book::ShowInfo()
{
	cout << "\nAuthor : " << Author << "Title : " << Title 
		<< "ISBN : " << ISBN << "Reserve Date : " << ResDate 
		<< "Due Date : " << DueDate << endl;
}

bool Book::operator==(const Book A)
{
	if (this->Author == A.getAuthor() &&
		this->ISBN == A.getISBN() &&
		this->Title == A.getTitle())
		return true;
	return false;
}