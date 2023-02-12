#pragma once

class Matrix {

	int** matrix;
	int row;
	int col;

public:

	Matrix(int, int, int, int, int = 2, int = 2);
	Matrix(int, int, int, int, int, int, int, int, int, int = 3, int = 3);
	Matrix(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int = 4, int = 4);
	Matrix(const Matrix&);
	~Matrix();
	int getRow() const;
	int getCol() const;
	int getValue(int, int);
	void setValue(int, int, int);
	int Total();
	double Average();
	int RowTotal(int);
	int ColumnTotal(int);
	int HighestInRow(int);
	int LowestInRow(int);
	Matrix Transpose();
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	Matrix Add(Matrix);
	Matrix Subtract(Matrix);
	Matrix Multiply(Matrix);
	int FindkSmallest(int);
	int FindkLargest(int);
	Matrix merge(Matrix);
};

void GenerateMatrix(int**& , int , int);
int countL(int** , int , int);
int countS(int** , int , int );
int UniqueValues(int** , int , int);
bool check_repeat(int**, int, int, int, int);