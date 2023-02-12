#pragma once
#include "String.h"

class Date {
	int Day;
	int Month;
	int Year;
public:
	Date(const Date&);
	Date(int = 0, int = 0, int = 0);
	void setDay(const int);
	void setMonth(const int);
	void setYear(const int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void AddDays(int = 0);
	void Display();
	int operator-(const Date&);
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
};