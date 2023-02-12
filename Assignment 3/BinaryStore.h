#include <iostream>
using namespace std;

#pragma once

class Byte
{
	char bits[9];

public:
	//Constructors
	Byte(char* = "");
	Byte(const Byte&);

	//Setter and Getter
	char* getByte();
	void setbits(char*);

	//Overloaded operators

	Byte operator+(Byte&);
	Byte operator-(Byte&);
	Byte operator||(Byte&);
	Byte operator&&(Byte&);
	bool operator==(Byte&);
	char& operator[](int);
	char operator[](int) const;
	void operator=(const Byte&);

	//Destructors
	~Byte();
};

class BinaryStore
{
	int total;
	Byte* data;
	char** address;

public:
	//Constructors
	BinaryStore(int = 0);
	BinaryStore(const BinaryStore& );

	//Setters and Getters
	void setAddress(int, int, char);
	char getAddress(int, int) const;
	void setAddress(char*, int = 0);
	char* getAddress(int) const;
	void setSize(int);
	int getTotal() const;
	Byte Get(char*);
	Byte getData(int) const;

	//Functions & Overloaded Operators
	void Add(char*, Byte);
	void operator+=(char*);
	void operator=(const BinaryStore&);

	//Destructor
	~BinaryStore();
};
void check_borrow(char* num1, int n, char* num2);
bool Subtractable(char* num1, char* num2);
char Logic(bool num);
char Add_Chars(char num1, char num2, int& carry);

bool Empty_Index(BinaryStore A, int& i);
bool Empty_ByteIndex(BinaryStore& A, int& index);
bool Equal_Address(char* A, char* B);
void Copy_Val(BinaryStore& B1, BinaryStore& B2);
void Initialize_Object(char**& address, Byte*& data, int total);

ostream& operator<<(ostream&, BinaryStore&);