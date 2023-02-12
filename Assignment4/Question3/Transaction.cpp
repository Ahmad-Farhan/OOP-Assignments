#include"Transactions.h"

Transactions::Transactions(const int a)
{
	total = a;
	History = new String[a];
	for (int i = 0; i < total; i++)
		History[i] == nullptr;
}

void Transactions::setTotal(const int tot)
{
	total = tot;
}

void Transactions::setHistory(String* other)
{
	History = other;
}

int Transactions::getTotal() const
{
	return total;
}

String* Transactions::getHistory() const
{
	return History;
}

void Transactions::AddTransaction(const String& Add)
{
	String Empty("");
	for (int i = 0 ; i<total; i++)
	{
		if (History[i] == Empty)
			History[i] = Add;
		return;
	}

}
void Transactions::DisplayTransactions(const int size)
{
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
		cout << History[i] << endl;
	cout << "-------------------------------------------" << endl;
}