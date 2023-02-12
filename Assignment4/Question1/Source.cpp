#include <iostream>
#include "LibraryManagementSystem.h"
using namespace std;

int main()
{
	LibraryManagementSystem Admin(1 , "Ahad", "Ahm1234");
	Admin.Register("Mira", 211366, "Fa1234");
	Admin.Login("Mira", 211366, "Fa1234");
	//Admin.AddBookSpace(10);
	
	cout << "Adding Books to LMS" << endl;
  //Admin.AddBook(Title, Author, ISBN, Index, Pages);
	Admin.AddBook("Harry Potter 1", "JKR", "123456", 2);
	Admin.AddBook("Harry Potter 2", "JKR", "234561", 2);
	Admin.AddBook("Harry Potter 3", "JKR", "345612", 2);
	Admin.AddBook("Harry Potter 4", "JKR", "456123", 2);
	Admin.AddBook("Harry Potter 5", "JKR", "561234", 2);
	Admin.AddBook("Harry Potter 6", "JKR", "612345", 2);
	Admin.AddBook("Harry Potter 7", "JKR", "654231", 2);
	Admin.AddBook("Percy Jackson 1", "RR", "561234", 2);
	Admin.AddBook("Percy Jackson 2", "RR", "612345", 2);
	Admin.AddBook("Percy Jackson 3", "RR", "654231", 2);

	cout << "\nAdding User Accounts to LMS" << endl;
  //Admin.AddUser(Name , ID , Batch , Department/Designation);
	Admin.AddStudent("Ahmad", "986", "21", "CS");
	Admin.AddStudent("Kiara", "8765", "21", "EE");
	Admin.AddStaff("Luna", "4567", "Computing", "Professor");

	cout << "\nIssuing Books to Users" << endl;
  //Admin.IssueBook(Name , AccType , Book1 , Book2' , Book3');
	Admin.IssueBook("Ahmad" , 1 , "Harry Potter 1" , "Harry Potter 2");
	Admin.IssueBook("Kiara", 1 , "Percy Jackson 1" , "Percy Jackson 2" , "Percy Jackson 3");
	Admin.IssueBook("Luna", 2 ,"Harry Potter 7", "Harry Potter 6");

	cout << "\nDisplaying Books Reserved by Student 1" << endl;
	Admin.ShowInfo("Ahmad" , "Harry Potter 1" , "Harry Potter 2");

	cout << "Returning Books of Student 2" << endl;
	Admin.ReturnBook("Kiara", "Percy Jackson 1", "Percy Jackson 2" , "Percy Jackson 3");
	
	cout << "\nLogging out Admin" << endl;
	Admin.Logout();
	return 0;
}
