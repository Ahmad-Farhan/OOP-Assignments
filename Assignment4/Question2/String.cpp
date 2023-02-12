#include "String.h"

int String::getLength() const
{
	return length;
}

void String::setLength(int A)
{
	length = A;
}

char* String::getDataPtr() const
{
	return data;
}
String::String()
{
	data = nullptr;
	length = 0;
}

String::String(const char* str)
{
	int size;
	for (size = 0; *(str + size) != '\0'; size++);

	length = size;
	data = new char[length + 1];

	for (int i = 0; i < size; i++)
		*(data + i) = *(str + i);

	*(data + size) = '\0';
}

String::String(const String& str)
{
	length = str.getLength();
	data = new char[length + 1];

	for (int i = 0; i < length; i++)
		*(data + i) = str.data[i];

	*(data + length) = '\0';
}

String::String(const string& str)
{
	for (length = 0; str[length] != '\0'; length++);
	data = new char[length + 1];

	for (int i = 0; i < length; i++)
		*(data + i) = str[i];

	*(data + length) = '\0';
}

String::String(int x)
{
	data = new char[x+1];
	length = x ;
}

char& String::operator[](int i)
{
	return *(data + i);
}


const char String::operator[](int i) const
{
	return *(data + i);
}

String String::operator+(const String& str) const
{
	int size;
	for (size = 0; str[size] != '\0'; size++);

	String res(length + size);

	for (int i = 0; i < length; i++)
		res.data[i] = data[i];

	for (int i = 0; i < size; i++)
		res.data[length + i] = str[i];

	res.data[length + size] = '\0';
	return res;
}

String String::operator+(const char& str) const
{
	int size;
	for (size = 0; *(data + size) != '\0'; size++);

	String res(size + 2);

	for (int i = 0; i < size; i++)
		res.data[i] = data[i];

	res.data[size] = str;
	res.data[size + 1] = '\0';
	return res;
}

String String::operator+(char*& str) const
{
	int size;
	for (size = 0; *(str + size) != '\0'; size++);

	String res(length + size);

	for (int i = 0; i < length; i++)
		res.data[i] = data[i];

	for (int i = 0; i < size; i++)
		res.data[length + i] = str[i];

	res.data[length + size] = '\0';
	return res;
}

bool check_equal(char* s1, char* s2, int size)
{
	for (int i = 0; i < size; i++)
		if (*(s1 + i) != *(s2 + i))
			return false;

	return true;
}

bool check_equal(char* s1, string s2, int size)
{
	for (int i = 0; i < size; i++)
		if (s1[i] != s2[i])
			return false;

	return true;
}

int IndexSubstr(char* str1, char* str2, int length, int& size)
{
	for (size = 0; str2[size] != '\0'; size++);

	for (int index = 0; index < length; index++)
	{
		char temp[20] = "";
		temp[size] = '\0';

		for (int j = 0; j < size; j++)
			temp[j] = str1[index+j];

		if (check_equal(temp, str2, size))
			return index;
	}
}

int IndexSubstr(char* str1, string str2, int length, int& size)
{
	for (size = 0; str2[size] != '\0'; size++);

	for (int index = 0; index < length; index++)
	{
		char temp[20] = "";
		temp[size] = '\0';

		for (int j = 0; j < size; j++)
			temp[j] = str1[index + j];

		if (check_equal(temp, str2, size))
			return index;
	}
}

String String::operator-(const String& str) const
{
	String res(*this);

	int size,index = IndexSubstr(data, str.data, length , size);


	for (int i = index; i < length; i++)
		res[i] = *(data + i + size);

	res.length -= size;
	return res;
}

String String::operator-(const string& str) const
{
	String res(*this);

	int size, index = IndexSubstr(data, str, length, size);

	for (int i = index; i < length; i++)
		res[i] = *(data + i + size);

	res.length -= size;
	return res;
}


String String::operator=(const String& A)
{
	this->~String();
	this->length = A.getLength();
	this->data = new char[length + 1];

	for (int i = 0; i <= length; i++)
		this->data[i] = A.data[i];

	return *this;
}

String String::operator=(char* str)
{
	this->~String();
	for (this->length = 0; *(str + length) != '\0'; length++);
	this->data = new char[length + 1];

	for (int i = 0; i <= length; i++)
		this->data[i] = str[i];

	return *this;
}

String String::operator=(const string& str)
{
	this->~String();
	for (this->length = 0; str[length] != '\0'; length++);
	this->data = new char[length + 1];

	for (int i = 0; i <= length; i++)
		this->data[i] = str[i];

	return *this;
}

bool String::operator==(const String& A) const
{
	if (this->length != A.getLength())
		return false;

	for(int i=0 ; i < length ; i++)
		if(this->data[i] != A[i])
			return false;

	return true;
}

bool String::operator==(const string& str) const
{
	int size;
	for (size = 0; str[size] != '\0'; size++);

	if (this->length != size)
		return false;

	for (int i = 0; i < length; i++)
		if (this->data[i] != str[i])
			return false;

	return true;
}

bool String::operator==(char* str) const
{
	int size;
	for (size = 0; str[size] != '\0'; size++);

	if (this->length != size)
		return false;

	for (int i = 0; i < length; i++)
		if (this->data[i] != str[i])
			return false;

	return true;
}

bool String::operator!()
{
	if (*data)
		return false;

	return true;
}

int String::operator()(char a) const
{
	for (int i = 0; i < length; i++)
		if (*(data + i) == a)
			return i;
}

int String::operator()(const String& str) const
{
	int size = 0;
	return IndexSubstr(data, str.data, length , size);
}

int String::operator()(const string& str) const
{
	int size;
	return IndexSubstr(data, str, length, size);
}

int String::operator()(char* str) const
{
	int size = 0;
	return IndexSubstr(data, str, length, size);
}

String::operator int() const
{
	return length;
}

String::~String()
{
	delete[] data;
	data = nullptr;
}

ostream& operator<<(ostream& output, const String& str)
{
	output << str.getDataPtr();

	return output;
}

istream& operator>>(istream& input, String& str)
{
	str.~String();

	char* in = new char[100];

	input.getline(in, 100);
	str = in;
	
	for(str.setLength(0) ; in[str.getLength()] != '\0' ; str.setLength(str.getLength()+1));

	return input;
}