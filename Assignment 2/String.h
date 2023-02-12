#pragma once

class String {

	char* data;
	int length;

public:

	String();
	String(int);
	String(char*);
	String(const String&);
	int strLength();
	void clear();
	bool empty();
	char* getdata();
	int charAt(char);
	bool equals(char*);
	bool equalsIgnoreCase(char*);
	char* substring(char*, int);
	char* substring(char*, int, int);
	void print();
	~String();
};

bool CompareCase(char, char);
bool check_equal(char*, char*, int);
char* generatesubstr(char*, int, int);