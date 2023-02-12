#include "Rational.h"

void Rational::setP(int A) {
	this->p = A;
}

int Rational::getP() const {
	return p;
}

void Rational::setQ(int B) {
	this->q = B;
}

int Rational::getQ() const {
	return q;
}

int gcd(int num1, int num2)
{
	int n1 = num1 , n2 = num2;
	if (num1 < 0)
		n1 = num1 * (-1);

	if (num2 < 0)
		n2 = num2 * (-1);

	int res = 0;

	if ((num1 == 0 && num2 == 1) )//|| (num1 < 0 && num2 > 0))
		return 1;

	for (int i = 1; i <= n1 && i <= n2; i++)
		if (n1 % i == 0 && n2 % i == 0)
			res = i;

	if (num1 < 0 && num2 < 0)
		res *= (-1);

	return res;
}

void normalize(int& num1, int& num2)
{
	if ((num2 < 0 && num1 > 0) || (num1 < 0 && num2 < 0))
	{
		num1 *= (-1);
		num2 *= (-1);
	}

	if (num1 == 0)
		num2 = 1;
	
	int GCD = gcd(num1, num2);

	num1 /= GCD;
	num2 /= GCD;
}

Rational::Rational(int n, int d)
{
	this->p = n;
	this->q = d;
	normalize(p, q);
}

Rational::Rational(const Rational& copy)
{
	this->p = copy.getP();
	this->q = copy.getQ();
}

Rational Rational::operator = (const Rational& x)
{
	this->p = x.getP();
	this->q = x.getQ();
	return *this;
}

Rational Rational::operator+(const Rational& x) const
{
	Rational res;
	int P = (p * x.getQ()) + (q * x.getP()), Q = this->q * x.getQ();
	normalize(P,Q);

	res.setP(P);
	res.setQ(Q);

	return res;
}

Rational Rational::operator-(const Rational& x) const
{
	Rational res;
	int P = (p * getQ()) - (q * x.getP()), Q = this->q * x.getQ();
	normalize(P, Q);

	res.setP(P);
	res.setQ(Q);

	return res;
}

Rational Rational::operator*(const Rational& x) const
{
	Rational res;
	int P = this->p * x.getP(), Q = this->q * x.getQ();
	normalize(P, Q);

	res.setP(P);
	res.setQ(Q);

	return res;
}

Rational Rational::operator/(const Rational& x) const
{
	Rational res;
	int P = this->p * x.getQ(), Q = this->q * x.getP();
	normalize(P, Q);

	res.setP(P);
	res.setQ(Q);

	return res;
}

Rational Rational::operator += (const Rational& x)
{
	this->p += x.getP();
	this->q += x.getQ();
	normalize(p, q);
	return *this;
}

Rational Rational::operator -= (const Rational& x)
{
	this->p -= x.getP();
	this->q -= x.getQ();
	normalize(p, q);
	return *this;
}

Rational Rational::operator *= (const Rational& x)
{
	this->p *= x.getP();
	this->q *= x.getQ();
	normalize(p, q);
	return *this;
}

Rational Rational::operator /= (const Rational& x)
{
	this->p /= x.getP();
	this->q /= x.getQ();
	normalize(p, q);
	return *this;
}

bool Rational::operator == (const Rational& other) const
{
	if (this->p == other.getP() && this->q == other.getQ())
		return true;
	return false;
}

bool Rational::operator < (const Rational& other) const
{
	float R1 = static_cast<float>(this->p) / static_cast<float>(this->q);
	float R2 = static_cast<float>(other.getP()) / static_cast<float>(other.getQ());

	if (R1 < R2)
		return true;
	return false;
}

bool Rational::operator > (const Rational& other) const
{
	float R1 = static_cast<float>(this->p) / static_cast<float>(this->q);
	float R2 = static_cast<float>(other.getP()) / static_cast<float>(other.getQ());

	if (R1 > R2)
		return true;
	return false;
}

bool Rational::operator <= (const Rational& other) const
{
	float R1 = static_cast<float>(this->p) / static_cast<float>(this->q);
	float R2 = static_cast<float>(other.getP()) / static_cast<float>(other.getQ());

	if (R1 <= R2)
		return true;
	return false;
}

bool Rational::operator >= (const Rational& other) const
{
	float R1 = static_cast<float>(this->p) / static_cast<float>(this->q);
	float R2 = static_cast<float>(other.getP()) / static_cast<float>(other.getQ());

	if (R1 >= R2)
		return true;
	return false;
}

string reverseString(string num , int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		char temp = num[size - i - 1];
		num[size - i - 1] = num[i];
		num[i] = temp;
	}
	return num;
}

string CValue(int num)
{
	string res = "";
	int size;

	if (num == 0)
		return "0";

	if (num < 0)
		num *= (-1);

	for (size = 0; num > 0 ; size++)
	{
		res += static_cast<char>(num % 10 + 48);
		num /= 10;
	}

	if (size > 1)
		res = reverseString(res, size);

	return res;
}

Rational::operator string() const
{
	string result = "";

	if (p < 0 || q < 0)
		result = '-';

	result += CValue(p);

	if (q != 1)
	{
		result += '/';
		result += CValue(q);
	}

	return result;
}

Rational::~Rational()
{
	this->p = 0;
	this->q = 1;
}

ostream& operator<<(ostream& output, const Rational& A) 	// outputs the Rational
{
	output << "Rational Number is : " << (string)A << '\n';
	return output;
}

istream& operator>>(istream& input, Rational& res) 	// inputs the Rational
{
	string in;
	cout << "Enter Rational Number(p/q) : ";
	input >> in;

	int P = 0, Q = 0, index, size , start = 0;

	if (in[0] == '-')
		start = 1;

	for (index = start; in[index] != '/'; index++);
	for (size = start; in[size] != '\0'; size++);

	for (int i = start; i < index; i++)
	{
		P += static_cast<int>(in[i] - 48);
		if (i + 1 < index)
			P *= 10;
	}

	if (start == 1)
		P *= (-1);

	start = index + 1;
	if (in[start] == '-')
		start = index + 2;

	for (int i =  start; i < size; i++)
	{
		Q += static_cast<int>(in[i] - 48);
		if (i + 1 < size)
			Q *= 10;
	}

	if (start == index + 2)
		Q *= (-1);

	normalize(P, Q);

	res.setP(P);
	res.setQ(Q);

	return input;
}