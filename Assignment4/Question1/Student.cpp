#include "Student.h"

Student::Student(const String name, const String id ,const String batch, const String desig )
{
	Batch = batch;
	Designation = desig;
	this->setName(name);
	this->setID(id);
}

void Student::setBatch(const String batch)
{
	this->Batch = batch;
}

void Student::setDesignation(const String desig)
{
	this->Designation = desig;
}

String Student::getBatch() const
{
	return Batch;
}

String Student::getDesignation() const
{
	return Designation;
}

int Student::getType() const
{
	return 1;
}

bool Student::operator==(const Student& A) const
{
	if (this->getID() == A.getID() &&
		this->getName() == A.getName() &&
		this->Designation == A.getDesignation() &&
		this->Batch == A.Batch)
		return true;

	return false;
}
