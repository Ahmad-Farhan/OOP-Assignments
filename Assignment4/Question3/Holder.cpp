#include "Holder.h"
#include "Account.h"

Holder::Holder(int type, const String FN, const String MN, const String LN, const Address& Add, const String DD, const String MM, const String YY, const String Ph ,int Accno) : address (Add)
{
	if (type == 1)
		Interest = 0;
	if (type == 2)
		Interest = 0.5;

	Firstname = FN;
	Middlename = MN;
	Lastname = LN;
	DateOfBirth = { DD , MM , YY };
	PhoneNumber = Ph;
	AccountNumber = Accno;
	Account** accounts;
}