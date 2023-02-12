#include "CSR.h"

int CSR::totalComplaintsResolved = 0;

int CSR::getCSRID()
{
	return csrID;
}

char* CSR::getName()
{
	return csrName;
}

int CSR::getHours()
{
	return hours;
}

int CSR::getComplaintsResolved()
{
	return complaintsResolved;
}

float CSR::getPayrate()
{
	return payrate;
}
float CSR::getWage()
{
	return wage;
}

void CSR::setCSRID(int ID)
{
	if (ID > 0)
		csrID = ID;
}
void CSR::setName(char* n)
{
	int size;
	for (size = 0; *(n + size) != '\0'; size++);

	csrName = new char[size];
	*(csrName + size) = '\0';

	for (int j = 0; j < size; j++)
		*(csrName + j) = *(n + j);
}

void CSR::setHours(int hrs)
{
	if (hrs > 0)
		hours = hrs;
}

void CSR::setComplaintsResolved(int cpsResolved)
{
	if (cpsResolved > 0)
		complaintsResolved = cpsResolved;
}

void CSR::setTotalCpsResolved(int totalcpsResolved)
{
	totalComplaintsResolved = totalcpsResolved;
}

void CSR::calcPayrate()
{
	payrate = 25 + (25 * (static_cast<float>(getComplaintsResolved()) / static_cast<float>(getTotalCpsResolved())));
}

void CSR::calcWage()
{
	calcPayrate();
	wage = static_cast<float>(hours) * payrate;
}

int CSR::getTotalCpsResolved()
{
	return totalComplaintsResolved;
}

CSR getCSR_at(CSR employees[7], int index)
{
	return employees[index];
}

void calcTotalComplaints(CSR employees[7])
{
	int sum = 0;
	for (int i = 0; i < 7; i++)
		sum += employees[i].getComplaintsResolved();

	employees[0].setTotalCpsResolved(sum);
}

void calcAllEmployeeWages(CSR employees[7])
{
	for (int i = 0; i < 7; i++)
		employees[i].calcWage();
}

void SortByHours(CSR employees[7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			if (employees[i].getHours() < employees[j].getHours())
			{
				CSR temp = employees[i];
				employees[i] = employees[j];
				employees[j] = temp;
			}
		}
	}
}

void SortByComplaintsRes(CSR employees[7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			if (employees[i].getComplaintsResolved() < employees[j].getComplaintsResolved())
			{
				CSR temp = employees[i];
				employees[i] = employees[j];
				employees[j] = temp;
			}
		}
	}
}

void SortByWages(CSR employees[7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			if (employees[i].getWage() < employees[j].getWage())
			{
				CSR temp = employees[i];
				employees[i] = employees[j];
				employees[j] = temp;
			}
		}
	}
}