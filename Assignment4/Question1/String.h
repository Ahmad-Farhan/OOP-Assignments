#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <string>
using namespace std;

class String {
	char* data;
	int length;
	// think about the private data members...
public:

	int getLength() const;
	void setLength(int);
	char* getDataPtr() const;
	// provide definitions of following functions
	String();
	// default constructor
	String(const char* str);
	// initializes the string with constant c-string
	String(const String&);
	// copy constructor to initialize the string from the existing string
	String(int x); // initializes a string of predefined size
	char& operator[](int i);
	// returns the character at index [x]
	const char operator[](int i) const;
	// returns the character at index [x]
	// Arithmetic Operators
	String operator+(const String& str) const;
	// appends a String at the end of the String
	String operator+(const char& str) const;
	// appends a char at the end of the String
	String operator+(char*& str) const;
	// appends a String at the end of the String
	String operator-(const String& substr) const;
	//removes the substr from the String
	String operator-(const string& substr) const;
	//removes the substr from the String
	// Assignment Operators
	String operator=(const String&);
	// copies one String to another
	String operator=(char*);
	// copies one c-string to another
	String operator=(const string&);
	// copies one string to another
	// Logical Operators
	bool operator==(const String&) const;
	// returns true if two Strings are equal
	bool operator==(const string&) const;
	// returns true if the string is equal to the String
	bool operator==(char*) const;
	// returns true if the c-string is equal to the String

	// Unary Operators
	// Boolean Not Operator
	bool operator!();
	// returns true if the String is empty
	// Function-Call Operators
	int operator()(char) const; // returns the index of the character being searched
	int operator()(const String&) const; // returns the index of the String being searched
	int operator()(const string&) const; // returns the index of the string being searched
	int operator()(char*) const; // returns the index of the c-string being searched
	// Conversion Operator
	operator int() const; // returns the length of string
	~String(); // destructor
};

// Operator Overloading as Non-Member Functions
// Stream Insertion and Extraction Operators
ostream& operator<<(ostream& output, const String&); // outputs the string
istream& operator>>(istream& input, String&); // inputs the string
bool check_equal(char* s1, char* s2, int size);
bool check_equal(char* s1, string s2, int size);
int IndexSubstr(char* str1, char* str2, int length, int& size);
int IndexSubstr(char* str1, string str2, int length, int& size);

#endif /* STRING_H_ */