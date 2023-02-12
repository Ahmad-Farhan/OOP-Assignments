#pragma once

class CSR {

	int csrID = 0;
	char* csrName;
	int hours = 0;
	int complaintsResolved = 0;
	float payrate = 0.0;
	float wage = 0.0;
	static int totalComplaintsResolved;

public:

	int getCSRID();
	char* getName();
	int getHours();
	int getComplaintsResolved();
	float getPayrate();
	float getWage();
	void setCSRID(int);
	void setName(char*);
	void setHours(int);
	void setComplaintsResolved(int);
	static void setTotalCpsResolved(int);
	void calcPayrate();
	void calcWage();
	static int getTotalCpsResolved();
};

CSR getCSR_at(CSR[7], int);
void calcTotalComplaints(CSR[7]);
void calcAllEmployeeWages(CSR[7]);
void SortByHours(CSR[7]);
void SortByComplaintsRes(CSR[7]);
void SortByWages(CSR[7]);