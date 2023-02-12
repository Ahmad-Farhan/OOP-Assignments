#include "CMap.h"
#include "String.h"

int CMap::getRows() const
{
	return rows;
}

void CMap::setRows(const int val)
{
	rows = val;
}

String** CMap::getMap() const
{
	return map;
}

void CMap::setMapVal(int a , int b ,String str)
{
	int size;
	String res(str);
	map[a][b] = res;
}

String& CMap::getMapVal(int i, int j) const
{
	return map[i][j];
}

void GenerateMap(String**& map, int rows)
{
	map = new String*[rows];

	for (int i = 0; i < rows; i++)
	{
		map[i] = new String [7];

		for (int j = 0; j < 7; j++)
			map[i][j] = "";
	}
}

CMap::CMap(const CMap& A)
{
	rows = A.getRows();
	GenerateMap(map, A.getRows());

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = A.getMapVal(i , j);
}

CMap::CMap(const String** omap,const int size)
{
	rows = size;
	GenerateMap(map, size);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 6; j++)
			map[i][j] = omap[i][j];
}

CMap::CMap(const int size)
{
	rows = size;
	GenerateMap(map, size);
}

void CMap::operator=(const CMap& A)
{
	this->~CMap();
	this->rows = A.getRows();

	GenerateMap(map, rows);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 6; j++)
			map[i][j] = A.getMapVal(i , j);
}

int Empty_ValIndex(String* map, const int n)
{
	for (int i = 1; i < 7; i++)
		if (is_Empty(map[i]))
			return i;
}

int Empty_KeyIndex(String** map, const int n, String str = "")
{
	for (int i = 0; i < n; i++)
		if (map[i][0]== str || is_Empty(map[i][0]))
			return i;
}

int Val_Index(String* map, String str)
{
	for (int i = 0; i < 6; i++)
		if ((map[i]) == str)
			return i;
	return 6;
}

bool is_Empty(const String& entry)
{
	if (entry == "")
		return true;

	return false;
}

bool Keys_Full(String** map, const int n)
{
	for (int i = 0; i < n; i++)
		if (is_Empty(map[i][0]))
			return false;

	return true;
}

void CMap::UpdateMap()
{
	CMap res(*this);
	this->~CMap();

	rows = res.getRows() + 1;
	GenerateMap(map, rows);

	for (int i = 0; i < rows - 1; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = res.getMapVal(i, j);
}

bool Key_Present(String** map, const int n, const String& temp)
{
	for (int i = 0; i < n; i++)
		if (map[i][0] == temp)
			return true;

	return false;
}

String& CMap::operator[](char* str)
{
	const String temp(str);
	if (Keys_Full(map, rows) && !Key_Present(map , rows , temp))
		UpdateMap();

	int rowIndex = Empty_KeyIndex(map, rows, str);
	//int colIndex = Empty_ValIndex(map, rowIndex);
	map[rowIndex][0] = temp;
	return map[rowIndex][1];
}

String CMap::operator[](char* str) const
{
	String temp(str);
	for (int i = 0; i < rows; i++)
	{
		if (temp == map[i][0])
			return map[i][0];
	}
}

void CMap::operator=(const char* str)
{
	int index = rows;
	if (index == 0)
		UpdateMap();

	if (Keys_Full(map, index))
		UpdateMap();

	while (!is_Empty(map[index][0]) && index < rows)
		index++;
	
	String temp = str;
	map[index][1] = temp;
}

string Strtostr(const String& str)
{
	char* temp = new char[str.getLength()+1];

	for (int i = 0; i <= str.getLength(); i++)
		temp[i] = str[i];

	string result = temp;
	return result;
}

string CMap::toString()
{
	string result = "["; 

	for (int i = 0; i < rows; i++)
	{
		if (!is_Empty(map[i][0]))
		{
			result += " " ;
			result += Strtostr(map[i][0]);
			result += " : { ";

			for (int j = 1; j < 7; j++)
			{
				if (!is_Empty(map[i][j]))
				{
					result += Strtostr(map[i][j]);
					if (!is_Empty(map[i][j + 1]))
						result += ", ";
					else
					{
						result += " }";
						break;
					}
				}
			}
		}

		if(i+1 < rows)
			if (!is_Empty(map[i+1][0]))
				result += ",";
	}
	result += " ]";

	return result;
}

void operator+=(String& str, const char* arr)
{
	String temp(arr);
	int a = Empty_ValIndex(&str, 7);
	*(&str+a) = temp;
}
void Shift_left(String& str, int a)
{
	for (int i = a; i < 5; i++)
		*(&str + i) = *(&str + i + 1);
}

void operator-=(String& str, const char* arr)
{
	String temp(arr);
	int a = Val_Index(&str, temp);
	Shift_left(str, a);
	//*(&str + a) = "";
}

int UniqueDepartments(const CMap& map1, const CMap& map2 , int& size, int & index)
{
	int unique = 0;
	for (int i = 0; i < map1.getRows() && i < map1.getRows(); i++)
		if (map1.getMapVal(i, 0) != map2.getMapVal(i, 0))
			unique++;

	size = map1.getRows();
	index = map2.getRows();

	if (map2.getRows() > size)
	{
		size = map2.getRows();
		index = map1.getRows();
	}

	unique += size - index;
	return unique;
}

bool Nonrepeating(const String**& map, String str , const int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 7; j++)
			if (map[i][j] == str)
				return false;

	return true;
}

CMap& CMap::operator+(const CMap& omap)
{
	CMap res(*this);
	int i;
	rows = res.getRows() + omap.getRows();//UniqueDepartments(*this, omap , size , index));
	GenerateMap(map, rows);
	
	for(i = 0 ; i < res.getRows(); i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = res.getMapVal(i,j);

	for (int j = 0; j < omap.getRows(); j++)
		for (int k = 0; k < 7; k++)
			map[j + i][k] = res.getMapVal(j, k);

	return *this;
}

CMap::~CMap()
{
	for (int i = 0; i < this->rows; i++)
		delete[] map[i];

	delete[] map;
	map = nullptr;
	rows = 0;
}