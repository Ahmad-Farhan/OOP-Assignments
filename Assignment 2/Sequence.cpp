#include "Sequence.h"

Sequence::Sequence()
{
	length = 10;
	pseq = new int[length];

	for (int i = 0; i < 10; i++)
		*(pseq + i) = 0;
}

Sequence::Sequence(int lengthVal, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10)
{
	length = lengthVal;
	pseq = new int[length];
	int temp[] = { n1,n2,n3,n4,n5,n6,n7,n8,n9,n10 };
	for (int i = 0; i < length; i++)
		*(pseq + i) = temp[i];
}

Sequence::Sequence(Sequence& Seq)
{
	length = Seq.length;
	pseq = new int[length];

	for (int i = 0; i < length; i++)
		*(pseq + i) = Seq.pseq[i];
}

int Sequence::getLength()
{
	return length;
}

int* Sequence::getSeq()
{
	return pseq;
}

int count(int* pseq, int i, int n)
{
	int index = 0;
	for (int j = 0; j < n; j++)
	{
		if (*(pseq + i) > *(pseq + j))
			index++;
	}
	return index;
}

void Sequence::Sort(int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = *(pseq + count(pseq, i, n));
		*(pseq + count(pseq, i, n)) = *(pseq + i);
		*(pseq + i) = temp;
	}
}

bool repetitive(int* pseq, int num, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (*(pseq + i) == num)
			return true;
	}
	return false;
}

void shiftleft(int* pseq, int index, int& length)
{
	for (int i = index; i < length; i++)
		*(pseq + i) = *(pseq + i + 1);

	length--;
}

int Sequence::RemoveDuplicates()
{
	int result = length;
	for (int i = 0; i < length; i++)
	{
		if (repetitive(pseq, *(pseq + i), i))
			shiftleft(pseq, i, result);
	}
	Sort(result);
	return result;
}

void Sequence::Rotate(int steps)
{
	int temp[50];
	for (int i = 0; i < steps; i++)
		temp[i] = *(pseq + length - steps + i);

	for (int i = 0; i < length - steps; i++)
		temp[steps + i] = *(pseq + i);

	for (int i = 0; i < length; i++)
		*(pseq + i) = *(temp + i);
}

Sequence::~Sequence()
{
	length = 0;
	delete[] pseq;
	pseq = nullptr;
}