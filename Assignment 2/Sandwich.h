#pragma once

class Sandwich {

	char* name;
	char* size;
	char* filling;
	bool is_ready;
	double price;

public:

	Sandwich();
	Sandwich(char*, double);
	Sandwich(char*, double, char*, char*, bool);
	Sandwich(const Sandwich&);
	void setFilling(char*);
	void setPrice(double);
	void setName(char*);
	void setSize(char*);
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	void makeSandwich();
	bool check_status();
};

bool check_small(char*);
bool check_medium(char*);
bool check_large(char*);
bool valid_Size(char*);