#include "Array.h"

int Array::getLength() const
{
	return length;
}

void Array::setLength(int num)
{
	length = num;
	data = new int[length];
}

Array::Array()
{
	length = 0;
	data = nullptr;
}

Array::Array(int size)
{
	this->length = size;
	data = new int[length];
}

Array::Array(int* arr, int size)
{
	this->length = size;
	data = new int[size];

	for (int i = 0; i < size; i++)
		*(data + i) = *(arr + i);
}

Array::Array(const Array& A)
{
	this->length = A.getLength();
	data = new int[length];

	for (int i = 0; i < length; i++)
		*(data + i) = A.data[i];
}

int& Array::operator[](int i)
{
	if (i < length)
		return *(data + i);
}

int& Array::operator[](int i)const
{
	if (i < length)
		return *(data + i);
}

const Array& Array::operator=(const Array& A) //copy the array
{
	this->~Array();
	length = A.getLength();
	data = new int[length];

	for (int i = 0; i < length; i++)
		*(data + i) = A.data[i];

	return *this;
}

Array Array::operator+(const Array& A) //adds two Array
{
	Array Res(length);

	for (int i = 0; i < length; i++)
		Res[i] = this->data[i] + A.data[i];

	return Res;
}

Array Array::operator-(const Array& A) //subtracts two Array
{
	Array Res(length);

	for (int i = 0; i < length; i++)
		Res[i] = this->data[i] - A.data[i];

	return Res; 
}

Array Array::operator++()// adds one to each element of Array
{
	Array Res(length);

	for (int i = 0; i < length; i++)
		Res.data[i] = *(data + i) + 1;

	return Res;
}

Array Array::operator++(int)// adds one to each element of Array
{	
	Array Res(length);

	for (int i = 0; i < length; i++)
		Res[i] = this->data[i];

	for (int i = 0; i < length; i++)
		this->data[i]++;

	return Res;
}

Array& Array::operator--(int)// subtracts one from each element of Array
{
	Array Res(length);

	for (int i = 0; i < length; i++)
		Res[i] = this->data[i];

	for (int i = 0; i < length; i++)
		this->data[i]--;

	return Res;
}

bool Array::operator==(const Array& A)const // returns true if two arrays are same
{ 
	if (length != A.getLength())
		return false;

	for (int i = 0; i < length; i++)
		if (data[i] != A.data[i])
			return false;

	return true;
}

bool Array::operator!() // returns true if the Array is empty
{
	if (data == nullptr)
		return true;

	return false;
}

void Array::operator+=(const Array& A) // adds two Array
{
	for (int i = 0; i < A.getLength() ; i++)
		*(data + i) += A.data[i];
}

void Array::operator-=(const Array& A) // subtracts two Array
{
	for (int i = 0; i < A.getLength(); i++)
		*(data + i) -= A.data[i];
}

void Shift_Left(int* Arr, int index , int &size)
{
	for (int i = index; i < size; i++)
		*(Arr + i) = *(Arr + i + 1);

	size--;
}

int Array::operator()(int idx, int val) // erases the value val at idx. Returns 1 for a successful deletion and -1 if idx does not exist or is invalid. Shift the elements after idx to the left.
{
	if (idx < 0 || idx > length)
		return (-1);

	Shift_Left(data, idx , length);
	return 1;
}

Array::~Array() // destructor...
{
	length = 0;
	delete[] data;
	data = nullptr;
}

ostream& operator<<(ostream& output, const Array& arr) //Inputs the Array
{
	for (int i = 0; i < arr.getLength(); i++)
		output << arr[i] << " ";

	output << '\n';
	return output;
}

istream& operator>>(istream& input, Array& arr) //Outputs the Array
{
	int len = 0;

	cout << "Enter Array Length : ";
	input >> len;
	arr.setLength(len);

	for (int i = 0; i < len; i++)
	{
		cout << "Value [" << i + 1 << "] : ";
		input >> arr[i];
	}

	return input;
}