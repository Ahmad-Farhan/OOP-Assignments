#include "String.h"
#include "User.h"
#pragma once

class Staff : public User {
	String Designation;
	String Department;
public:
	Staff(const String = "", const String = "", const String = "", const String = "");
	void setDesignation(const String);
	void setDepartment(const String);
	String getDesignation() const;
	String getDepartment() const;
	bool operator==(const Staff& A) const;
};
