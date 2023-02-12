#pragma once

class Sequence {

	int length;
	int* pseq;

public:
	Sequence();
	Sequence(int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	Sequence(Sequence&);
	int getLength();
	int* getSeq();
	void Sort(int);
	int RemoveDuplicates();
	void Rotate(int);
	~Sequence();
};

int count(int* , int , int);
bool repetitive(int* , int , int);
void shiftleft(int* , int , int&);