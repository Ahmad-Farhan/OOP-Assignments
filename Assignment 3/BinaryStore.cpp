#include "BinaryStore.h"
#include <iostream>

//Byte Class Function Definitions

char* Byte::getByte()
{
	return bits;
}

void Byte::setbits(char* a)
{
	for(int i=0 ; i<9 ; i++)
		bits[i] = a[i];
}

Byte::Byte(char* str)
{
	for (int i = 0; i < 9 ; i++)
		bits[i] = str[i];
}

Byte::Byte(const Byte& A)
{
	for (int i = 0; i <= 8; i++)
		bits[i] = A[i];
}

char& Byte::operator[](int i) 
{
	return bits[i];
}

char Byte::operator[](int i) const
{
	return bits[i];
}

void Byte::operator=(const Byte& B)
{
	for (int i = 0; i < 9; i++)
		bits[i] = B[i];
}

char Add_Chars(char num1, char num2, int& carry)
{
	int result = (static_cast<int>(num1) - 48) + (static_cast<int>(num2) - 48) + carry;
	carry = 0;

	while (result > 1)
	{
		result -= 2;
		carry++;
	}

	return static_cast<char>(result + 48);
}

Byte Byte::operator+(Byte& A)
{
	Byte res(*this);
	int carry = 0;

	for(int i = 7; i >= 0; i--)
		res[i] = Add_Chars(A[i], bits[i], carry);

	return res;
}

char Logic(bool num)
{
	if (num == true)
		return '1';

	return '0';
}

bool Subtractable(char* num1, char* num2)
{
	int start1 = 0, start2 = 0;

	while (num1[start1] != '1')
		start1++;
	
	while (num2[start2] != '1')
		start2++;

	if (start1 <= start2)
		return true;

	return false;
}

void check_borrow(char* num1 ,int n,char* num2)
{
	for (int i = 0; i <= n; i++)
	{
		if (*(num1 + n-i) >= *(num2 + n - i))
			break;

		*(num1 + n - i) += 2;
		*(num1 + n - i - 1) -= 1;
	}
}

Byte Byte::operator-(Byte& A)
{
	Byte res;
	if (!Subtractable(bits, A.getByte()))
	{
		res = "11111111";
		return res;
	}
	Byte b1(bits), b2(A.getByte());

	for (int i = 0; i < 8; i++)
	{
		check_borrow(b1.getByte(), 7 - i, b2.getByte());
		res[i] = (b1[i] + 7 - i) - (b2[i] + 7 - i) + 48;
	}
	return res;
}

Byte Byte::operator||(Byte& A)
{
	Byte res;
	for (int i = 0; i < 8; i++)
		res[i] = Logic(int(A[i]-48) || int(bits[i]-48));
	return res;
}

Byte Byte::operator&&(Byte& A)
{
	Byte res;
	for (int i = 0; i < 8; i++)
		res[i] = Logic(int(A[i] - 48) && int(bits[i] - 48));
	return res;
}

bool Byte::operator==(Byte& A)
{
	for (int i = 0; i < 8; i++)
		if (bits[i] != A[i])
			return false;

	return true;
}

Byte::~Byte()
{
}


//Binary Store Class Functions Definitions

void Initialize_Object(char**& address, Byte*& data , int total)
{
	data = new Byte[total];
	address = new char* [total];
	for (int i = 0; i < total; i++)
	{
		address[i] = new char[5];

		for (int j = 0; j < 5; j++)
			address[i][j] = '\0';
	}
}

void Copy_Val(BinaryStore& B1, BinaryStore& B2)
{
	for (int i = 0; i < B2.getTotal(); i++)
		{
			B1.getData(i) = B2.getData(i);

			for (int j = 0; j < 5; j++)
				B1.setAddress(i, j, B2.getAddress(i, j));
		}
	B1 = B2;
}

BinaryStore::BinaryStore(int size)
{
	total = size;
	Initialize_Object(address,data, total);

}

BinaryStore::BinaryStore(const BinaryStore& A)
{
	total = A.getTotal();
	Initialize_Object(address, data, total);

	for (int i = 0; i < total; i++)
	{
		data[i] = A.getData(i);

		for (int j = 0; j < 5; j++)
			address[i][j] = A.getAddress(i, j);
	}
}

void BinaryStore::setSize(int val)
{	
	this->~BinaryStore();

	total = val;
	Initialize_Object(address, data, total);
}

int BinaryStore::getTotal() const
{
	return total;
}

void BinaryStore::setAddress(int i, int j, char a)
{
	address[i][j] = a;
}

char BinaryStore::getAddress(int i , int j) const
{
	return address[i][j];
}

char* BinaryStore::getAddress(int i) const
{
	return address[i];
}

void BinaryStore::setAddress(char* str, int index)
{
	for (int i = 0; i < 5; i++)
		address[index][i] = str[i];
}

bool Equal_Address(char* A , char* B)
{
	for (int i = 0; i < 5; i++)
		if (A[i] != B[i])
			return false;

	return true;
}

Byte BinaryStore::Get(char* add)
{
	for (int i = 0; i < total; i++)
	{
		if (Equal_Address(address[i], add))
			return data[i];
	}
}

Byte BinaryStore::getData(int i) const
{
	return *(data+i);
}

bool Empty_ByteIndex(BinaryStore& A, int& index)
{
	for (index = 0; index < A.getTotal(); index++)
		if (A.getData(index)[0] == '\0')
				return true;

	return false;
}

void BinaryStore::Add(char* add, Byte Entry)
{
	int index = 0;

	if (Empty_ByteIndex(*this, index))
		this->data[index] = Entry;
	else
	{
		BinaryStore res(*this);
		this->total = res.getTotal() + 1;
		Initialize_Object(address, data, total);

		*this = res;
		this->data[total - 1] = Entry;
	}
}

bool Empty_Index(BinaryStore A , int& i)
{
	for (i = 0; i < A.getTotal(); i++)
		if (A.getAddress(i , 0) == '\0')
			return true;

	return false;
}

void BinaryStore::operator=(const BinaryStore& A)
{
	total = A.getTotal();

	for (int i = 0; i < total; i++)
	{
		data[i] = A.getData(i);

		for(int j=0 ; j < 5 ; j++) 
		address[i][j] = A.getAddress(i , j);
	}
}

void BinaryStore::operator+=(char* add)
{
	int index = 0;
	
	if(Empty_Index(*this , index))
		this->address[index] = add;
	else
	{
		BinaryStore res(*this);
		this->~BinaryStore();
		this->setSize(res.getTotal() + 1);

		Copy_Val(* this , res);
		this->setAddress(add, index);
	}
}

BinaryStore::~BinaryStore()
{
	delete[] data;

	for (int i = 0; i < total; i++)
		address[i] = nullptr;

	address = nullptr;
	data = nullptr;
	total = 0;
}

ostream& operator<<(ostream& output, BinaryStore& A)
{
	output << "BinaryStore Output \n";
	for (int i = 0; A.getData(i)[0] != '\0'; i++)
	{
		output << "\nAddress : " << A.getAddress(i) << "    Binary Data: ";

		for (int j = 0; j < 9; j++)
			output << A.getData(i)[j];
	}
	return output;
}