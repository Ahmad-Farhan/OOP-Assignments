#include "Matrix.h"

void GenerateMatrix(int**& matrix, int r, int c)
{
	matrix = new int* [r];
	for (int i = 0; i < r; i++)
		matrix[i] = new int[c];
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int r, int c)
{
	row = r;
	col = c;
	GenerateMatrix(matrix, row, col);

	matrix[0][0] = n1;	matrix[0][1] = n2;
	matrix[1][1] = n4;  matrix[1][0] = n3;
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int r, int c)
{
	row = r;
	col = c;
	GenerateMatrix(matrix, row, col);

	matrix[0][0] = n1;	matrix[0][1] = n2;	matrix[0][2] = n3;
	matrix[1][0] = n4;	matrix[1][1] = n5;	matrix[1][2] = n6;
	matrix[2][0] = n7;	matrix[2][1] = n8;	matrix[2][2] = n9;
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16, int r, int c)
{
	row = r;
	col = c;
	GenerateMatrix(matrix, row, col);

	matrix[0][0] = n1;	matrix[0][1] = n2;	matrix[0][2] = n3;	matrix[0][3] = n4;
	matrix[1][0] = n5;	matrix[1][1] = n6;	matrix[1][2] = n7;	matrix[1][3] = n8;
	matrix[2][0] = n9;	matrix[2][1] = n10;	matrix[2][2] = n11;	matrix[2][3] = n12;
	matrix[3][0] = n13;	matrix[3][1] = n14;	matrix[3][2] = n15;	matrix[3][3] = n16;
}

Matrix::~Matrix()
{
	row = 0;
	col = 0;

	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
}

int Matrix::getRow() const
{
	return row;
}

int Matrix::getCol() const
{
	return col;
}

Matrix::Matrix(const Matrix& m)
{
	row = m.row;
	col = m.col;
	GenerateMatrix(matrix, row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			matrix[i][j] = m.matrix[i][j];
	}
}

int Matrix::getValue(int row, int col)
{
	return matrix[row][col];
}

void Matrix::setValue(int r, int c, int value)
{
	matrix[r][c] = value;
}

int Matrix::Total()
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			sum += matrix[i][j];
	}
	return sum;
}

double Matrix::Average()
{
	double result = static_cast<double>(Total()) / static_cast<double>(row * col);
	return result;
}

int Matrix::RowTotal(int row)
{
	int sum = 0;
	for (int i = 0; i < col; i++)
		sum += matrix[row][i];

	return sum;
}

int Matrix::ColumnTotal(int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum += matrix[i][col];

	return sum;
}

int Matrix::HighestInRow(int row)
{
	int max = matrix[row][0];

	for (int i = 0; i < col; i++)
		if (matrix[row][i] > max)
			max = matrix[row][i];

	return max;
}

int Matrix::LowestInRow(int row)
{
	int min = matrix[row][0];

	for (int i = 0; i < col; i++)
		if (matrix[row][i] < min)
			min = matrix[row][i];

	return min;
}

bool check_repeat(int** matrix, int num, int row, int col, int pos)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (matrix[i][j] == num)
				return true;
	}

	for (int i = 0; i < pos; i++)
		if (matrix[row][i] == num)
			return true;

	return false;
}

int UniqueValues(int** matrix, int r, int c)
{
	int count = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			if (!check_repeat(matrix, matrix[i][j], i, c, j))
				count++;
	}
	return count;
}
int countS(int** matrix, int num, int size)
{
	int index = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (!check_repeat(matrix, matrix[i][j], i, size, j) && matrix[i][j] < num)
				index++;
	}
	return index;
}

int Matrix::FindkSmallest(int k)
{
	if (k < 1)
		return 0;

	else if (k >= UniqueValues(matrix, row, col))
		return FindkLargest(1);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (countS(matrix, matrix[i][j], row) == k)
				return matrix[i][j];
	}
}

int countL(int** matrix, int num, int size)
{
	int index = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (!check_repeat(matrix, matrix[i][j], i, size, j) && matrix[i][j] > num)
				index++;
	}
	return index;
}

int Matrix::FindkLargest(int k)
{
	if (k < 1)
		return 0;

	else if (k > row * col || k > UniqueValues(matrix, row, col))
		return FindkSmallest(1);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (countL(matrix, matrix[i][j], row) == k)
				return matrix[i][j];
	}
}

Matrix Matrix::Transpose()
{
	Matrix M(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			M.matrix[i][j] = matrix[j][i];
	}
	return M;
}

int Matrix::LeftDiagonalTotal()
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum += matrix[i][i];

	return sum;
}

int Matrix::RightDiagonalTotal()
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum += matrix[i][row - i - 1];

	return sum;
}

Matrix Matrix::Add(Matrix M)
{
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	if (row == M.row)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				M1.matrix[i][j] = matrix[i][j] + M.matrix[i][j];
			}
		}
	}
	else
		M1.~Matrix();

	return M1;
}

Matrix Matrix::Subtract(Matrix M)
{
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	if (row == M.row)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				M1.matrix[i][j] = matrix[i][j] - M.matrix[i][j];
			}
		}
	}
	else
		M1.~Matrix();

	return M1;
}

Matrix Matrix::Multiply(Matrix M)
{
	Matrix M1(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (col == M.getRow())
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < M.getCol(); j++)
			{
				for (int k = 0; k < col; k++)
					M1.matrix[i][j] += matrix[i][k] * M.matrix[k][j];
			}
		}
	}

	else
		M1.~Matrix();

	return M1;
}

Matrix Matrix::merge(Matrix M)
{
	Matrix M1(3, 4, 5, 6);
	M1.~Matrix();

	if (row != M.getRow())
		return M1;

	M1.row = row;
	M1.col = col + M.col;
	GenerateMatrix(M1.matrix, M1.row, M1.col);

	for (int i = 0; i < M1.row; i++)
	{
		for (int j = 0; j < col; j++)
			M1.matrix[i][j] = matrix[i][j];
	}

	for (int i = 0; i < M1.row; i++)
	{
		for (int j = 0; j < M.getCol(); j++)
			M1.matrix[i][col + j] = M.matrix[i][j];
	}
	return M1;
}