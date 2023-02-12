#include "Date.h"

Date::Date(int D, int M, int Y)
{
	Day = D;
	Month = M;
	Year = Y;
}
Date::Date(const Date& A)
{
	Day = A.Day;
	Month = A.Month;
	Year = A.Year;
}
void Date::setDay(const int D)
{
		Day = D;
}
void Date::setMonth(const int M)
{
	Month = M;
}
void Date::setYear(const int Y)
{
	Year = Y;
}
int Date::getDay() const
{
	return Day;
}
int Date::getMonth() const
{
	return Month;
}
int Date::getYear() const
{
	return Year;
}
void Date::AddDays(int Add)
{
	Day += Add;
	while (Day > 30)
	{
		Day -= 30;
		Month++;
	}
	while (Month > 12)
	{
		Month -= 12;
		Year++;
	}
}
int Date::operator-(const Date& A)
{
	int D1 = Day + Month*30 + Year*365;
	int D2 = A.getDay() + A.getMonth() * 30 + A.getYear() * 365;
	return D1 - D2;
}

istream& operator>>(istream& input, Date& A)
{
	string in;
	cout << "Enter Date (DD/MM/YYYY) : ";
	input >> in;

	A.Day = int(in[1]-48) + 10 * int(in[0]-48);
	A.Month = int(in[4] - 48) + 10 * int(in[3] - 48);
	A.Year = int(in[9] - 48) + 10 * int(in[8] - 48) + 100 * int(in[7] - 48) + 1000 * int(in[6] - 48);

	return input;
}
ostream& operator<<(ostream& output , const Date& A)
{
	output << A.Day << "/" << A.Month << "/" << A.Year << endl; 
	return output;
}
void Date::Display()
{
	cout << "Day : " << Day << "\nMonth : " << Month << "\nYear : " << Year << endl;
}