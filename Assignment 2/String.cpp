#include<iostream>
#include "String.h"
using namespace std;

String::String()
{
	data = nullptr;
	length = 0;
}

String::String(int size)
{
	length = size;
	data = new char[size];
	*data = '\0';
}

String::String(char* str)
{
	for (length = 0; *(str + length) != '\0'; length++);

	data = new char[length + 1];

	for (int i = 0; i < length; i++)
		data[i] = str[i];

	data[length] = '\0';
}

String::String(const String& str)
{
	length = str.length;
	data = new char[length + 1];

	for (int i = 0; i <= length; i++)
		data[i] = str.data[i];
}

String::~String()
{
	length = 0;
	delete[] data;
	data = nullptr;
}

int String::strLength()
{
	return length;
}

void String::clear()
{
	length = 0;
	delete[] data;
	data = nullptr;
}

bool String::empty()
{
	if (length == 0)
		return true;

	return false;
}

char* String::getdata()
{
	return data;
}

int String::charAt(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (*(data + i) == c)
			return i;
	}
}

bool String::equals(char* str)
{
	for (int i = 0; i < length; i++)
		if (*(data + i) != *(str + i))
			return false;

	return true;
}

bool CompareCase(char c1, char c2)
{
	if (c1 == c2 || c1 == c2 + 32 || c1 == c2 - 32)
		return true;

	return false;
}

bool String::equalsIgnoreCase(char* str)
{
	for (int i = 0; i < length; i++)
		if (!CompareCase(*(data + i), *(str + i)))
			return false;

	return true;
}

bool check_equal(char* s1, char* s2, int size)
{
	for (int i = 0; i < size; i++)
		if (*(s1 + i) != *(s2 + i))
			return false;

	return true;
}

char* String::substring(char* substr, int startIndex)
{
	int size;
	char sub[50];

	for (size = 0; *(substr + size) != '\0'; size++);

	for (int i = startIndex; i < length; i++)
	{
		*(sub + length - i) = '\0';

		for (int j = 0; j < length - i; j++)
			*(sub + j) = *(data + j + i);

		if (check_equal(substr, sub, size))
			return sub;
	}
	return nullptr;
}

char* generatesubstr(char* data, int start, int end)
{
	char str[50] = "";
	*(str + end - start + 1) = '\0';
	for (int i = 0; i <= end - start; i++)
		*(str + i) = *(data + start + i);

	return str;
}

char* String::substring(char* substr, int startIndex, int endIndex)
{
	int size = 0;
	for (size = 0; *(substr + size) != '\0'; size++);

	char* res = nullptr;
	for (int i = startIndex; i < endIndex; i++)
	{
		char sub[20];
		*(sub + size) = '\0';
		for (int j = 0; j < size; j++)
			*(sub + j) = *(data + i + j);

		if (check_equal(sub, substr, size))
		{
			res = generatesubstr(data, i, endIndex);
			break;
		}
	}
	return res;
}

void String::print()
{
	if (*(data) == '\0')
		cout << "NULL";
	else
		cout << data << endl;
}