#include "LibraryManagementSystem.h"

LibraryManagementSystem::LibraryManagementSystem(const int type, const String urnm, const String pass)
{
	login = false;
	UserType = type;
	UserName = urnm;
	Password = pass;
	Database = new Library_database;
	Users = new User * [10];
	for (int i = 0; i < 10; i++)
		Users[i] = nullptr;
	//Librarian temp(Database , "", 0 , "");
	//for (int i = 0; i < 10; i++)
	//	librarian[i] = temp;

	//
	//Student tempS("" , "");
	////for (int i = 0; i < 10; i++)
	////	students[i] = tempS;

	//Staff tempSt("", "");
	////for (int i = 0; i < 10; i++)
	////	staff[i] = tempSt;

	//Register(urnm, type, pass);
}

void LibraryManagementSystem::setUserType(const int type)
{
	UserType = type;
}
void LibraryManagementSystem::setUserName(const String urnm)
{
	UserName = urnm;
}
void LibraryManagementSystem::serPassword(const String pass)
{
	Password = pass;
}
int LibraryManagementSystem::getUserType() const
{
	return UserType;
}
String LibraryManagementSystem::getUserName() const
{
	return UserName;
}
String LibraryManagementSystem::getPassword() const
{
	return Password;
}
Librarian LibraryManagementSystem::getLibrarian(String a) const
{
	for (int i = 0; i < 10; i++)
		if (librarian[i].getName() == a)
			return librarian[i];
}

User LibraryManagementSystem::getUser(String a) const
{
	for (int i = 0; i < 10; i++)
		if (Users[i]->getName() == a)
			return *(Users[i]);
}

bool LibraryManagementSystem::Login(const String ur, const int id, const String pass)
{
	for (int i = 0; i < 10; i++)
		if (librarian[i].Verify_Librarian(ur, id, pass))
			login = true;

	if (!login)
		cout << "Login Failed - UserName or Password not Correct" << endl;

	return login;
}

bool LibraryManagementSystem::Register(const String ur,const int type, const String pass)
{
	librarian = new Librarian(*Database, ur, pass, type);
	return true;
}

bool LibraryManagementSystem::Logout()
{
	if (login)
	{
		login = false;
		cout << "Logout Successful" << endl;
		return true;
	}
	return false;
}

void LibraryManagementSystem::IssueBook(const String name, const int type, const String book1, const String book2, const String book3, const String book4)
{
	if(!login)
	{
		cout << "Unable to Issue Book(Login required)" << endl;
		return;
	}
	int index = 0;

	for (index = 0; index < UserNo; index++)
		if (Users[index]->getName() == name)
			break;

	int res = Users[index]->getAccount().getReserved();

	for (int i = 0; i < BookNo; i++)
	{
		if (Books[i].getTitle() == book1 || Books[i].getTitle() == book2 ||
			Books[i].getTitle() == book3 || Books[i].getTitle() == book4)
		{
			Books[i].ShowInfo();
			Books[i].Book_request(type);
			res++;
		}
	}
	Users[index]->getAccount().setReserved(res);
}

void LibraryManagementSystem::ReturnBook(const String name, const String book1, const String book2, const String book3, const String book4)
{
	if (!login)
	{
		cout << "Unable to Issue Book(Login required)" << endl;
		return;
	}
	int index = 0;

	for (index = 0; index < UserNo; index++)
		if (Users[index]->getName() == name)
			break;

	int res = Users[index]->getAccount().getReserved();

	for (int i = 0; i < BookNo; i++)
	{
		if ((Books[i].getTitle() == book1 || Books[i].getTitle() == book2 ||
			Books[i].getTitle() == book3 || Books[i].getTitle() == book4) &&
			Books[i].getReserved() != 0)
		{
			Date ReturnDate(0 , 0 , 0);
			cout << "\nReturning Book" << endl
				<< "---------------------------------" << endl;
			Books[i].ShowInfo();
			cout << "Return Date : " << endl;
			cin >> ReturnDate;
			int difference = ReturnDate - Books[i].getDueDate();
			Database->getAccount(index)->Calculate_fine(difference);
			cout << "Fine Amount : " << Database->getAccount(index)->getFine() << endl
				<< "---------------------------------" << endl;
			Books[i].Renew_info();
			res--;
		}
	}
	Users[index]->getAccount().setReserved(res);
}

void LibraryManagementSystem::ShowInfo(const String name, const String book1, const String book2, const String book3, const String book4)
{
	if (!login)
	{
		cout << "Unable to Issue Book(Login required)" << endl;
		return;
	}
	int index = 0;

	for (index = 0; index < UserNo; index++)
		if (Users[index]->getName() == name)
			break;

	int res = Users[index]->getAccount().getReserved();

	for (int i = 0; i < BookNo; i++)
	{
		if (Books[i].getTitle() == book1 || Books[i].getTitle() == book2 ||
			Books[i].getTitle() == book3 || Books[i].getTitle() == book4)
		{
			cout << "-------------------------------" << endl;
			Books[i].ShowInfo();
			cout << "-------------------------------" << endl;
		}
	}
}
void LibraryManagementSystem::AddBookSpace(const int a)
{
	if(!login)
	{
		cout << "Login to Add Book Space" << endl;
		return;
	}
	Database->AddBookspace(a);
	Book* temp = new Book[BookNo+a];
	for (int i = 0; i < a; i++)
		temp[i] = {"", "", ""};
	for (int i = 0; i < BookNo; i++)
		temp[i] = Books[i];

	Books = temp;
}

void LibraryManagementSystem::AddBook(const String title, const String author, const String isbn ,int pg , int res)
{
	if(!login)
	{
		cout << "Login to Add Books" << endl;
		return;
	}
	AddBookSpace(1);
	int index;
	Book Empty = { "","","" };
	for (index = 0; index < 10; index++)
		if (Books[index] == Empty)
			break;

	Books[index] = { title , author , isbn , pg , res };
	Database->AddBook(Books[index]);
	BookNo++;
}

void LibraryManagementSystem::AddStudent(const String name, const String id, const String batch, const String desig)
{
	if (!login)
	{
		cout << "Login to Add Student" << endl;
		return;
	}

	int index;
	for (index = 0; index < 10; index++)
		if (Users[index] == nullptr)
			break;
	Users[index] = new Student{ name , id , batch , desig };
	Database->AddAccountspace();

	Database->AddAccount(Users[index]->getAccount());
	UserNo++;
}

void LibraryManagementSystem::AddStaff(const String name, const String id, const String dept, const String desig)
{
	if (!login)
	{
		cout << "Login to Add Staff" << endl;
		return;
	}
	int index;
	for (index = 0; index < 10; index++)
		if (Users[index] == nullptr)
			break;
	Users[index] = new Staff{ name , id , dept , desig };
	Database->AddAccountspace();
	Database->AddAccount(Users[index]->getAccount());
	UserNo++;
}