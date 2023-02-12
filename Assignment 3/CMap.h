#pragma once
#include<iostream>
#include "String.h"
using namespace std;

class CMap
{
	String** map;
	int rows;
	
public:
	int getRows() const;
	void setRows(const int);
	String** getMap() const;
	void setMapVal(int , int , String);
	String& getMapVal(int , int ) const;

	//constructors
	CMap(const CMap&);
	CMap(const int = 1);
	CMap(const String**, const int);

	String& operator[](char*);
	void operator=(const char*);
	void operator=(const CMap&);
	CMap& operator+(const CMap&);
	String operator[](char*) const;

	string toString();
	~CMap();

	void UpdateMap();
};

string Strtostr(const String& );
void operator+=(String&, const char*);
void operator-=(String&, const char*);
bool is_Empty(const String&);