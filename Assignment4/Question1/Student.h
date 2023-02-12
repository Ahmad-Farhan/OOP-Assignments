#include "String.h"
#include "User.h"
#pragma once

class Student : public User {
	String Batch;
	String Designation;
public:
	Student(const String = "", const String = "" , const String = "" , const String = "");
	void setBatch(const String);
	void setDesignation(const String);
	String getBatch() const;
	String getDesignation() const;
	int getType() const;
	bool operator==(const Student&) const;
};