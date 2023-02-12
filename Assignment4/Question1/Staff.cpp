#include "Staff.h"

Staff::Staff(const String name, const String id, const String desig, const String dept)
{
	Designation = desig;
	Department = dept;
	this->setName(name);
	this->setID(id);
}

void Staff::setDesignation(const String desig)
{
	Designation = desig;
}

void Staff::setDepartment(const String dept)
{
	Department = dept;
}

String Staff::getDesignation() const
{
	return Designation;
}

String Staff::getDepartment() const
{
	return Department;
}

bool Staff::operator==(const Staff& A) const
{
	if (this->getID() == A.getID() &&
		this->getName() == A.getName() &&
		this->Designation == A.getDesignation() &&
		this->Department == A.getDepartment())
		return true;

	return false;
}