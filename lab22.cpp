#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);

	// + - * /
	ComplexNumber operator+(const ComplexNumber &); // prefix ex: ComplexNumber + ComplexNumber
	// ComplexNumber operator+(double);								// suffix ex: ComplexNumber + dobule

	ComplexNumber operator-(const ComplexNumber &); // ComplexNumber - ComplexNumber
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);

	friend ostream &operator<<(ostream &, const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
};

// bool operator
bool ComplexNumber::operator==(const ComplexNumber &c)
{
	if (real == c.real && imag == c.imag)
	{
		return true;
	}
	return false;
};

double ComplexNumber::abs()
{
	return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle()
{
	return atan2(imag, real) * 180 / M_PI;
}

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

// ComplexNumber ComplexNumber::operator+(double x)
// {
// 	return ComplexNumber(real + x, x );
// }

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{

	double dumb = pow(c.real, 2) + pow(c.imag, 2);
	double first = ((real * c.real) + (imag * c.imag));
	double second = ((imag * c.real) - (real * c.imag));
	return ComplexNumber(first / dumb, second / dumb);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	double first = (real * c.real) - (imag * c.imag);
	double second = (real * c.imag) + (imag * c.real);
	return ComplexNumber(first, second);
}

// non-member function
ComplexNumber operator-(double x, const ComplexNumber &c)
{
	return ComplexNumber(x - c.real, -c.imag);
}

ComplexNumber operator+(double x, const ComplexNumber &c)
{
	return ComplexNumber(x + c.real, c.imag);
}

ComplexNumber operator*(double x, const ComplexNumber &c)
{

	double first = (x * c.real);
	double second = (x * c.imag);
	return ComplexNumber(first, second);
}

ComplexNumber operator/(double a, const ComplexNumber &c)
{
	double dumb = (pow(c.real, 2) + pow(c.imag, 2));
	double first = (a * c.real) / dumb;
	double second = -(a * c.imag) / dumb;
	return ComplexNumber(first, second);
}

bool operator==(double x, const ComplexNumber &c)
{
	if (x == c.imag && x == c.real)
	{
		return true;
	}
	return false;
}

ostream &operator<<(ostream &os, const ComplexNumber &c)
{
	if (c.real != 0)
	{
		if (c.imag == 0)
			os << c.real;
		else if (c.imag < 0)
			os << c.real << c.imag << 'i';
		else
			os << c.real << '+' << c.imag << 'i';
	}
	else
	{
		if (c.imag == 0)
			os << 0;
		else
			os << c.imag << 'i';
	}
	return os;
}
int main()
{
	ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";

	cout << a + 2.5 << "\n";
	cout << 2.5 + a << "\n";
	cout << a - 1.5 << "\n";
	cout << 1.5 - a << "\n";
	cout << b + ComplexNumber(0, 2.5) << "\n";
	cout << c - c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a + b) / c;
	ComplexNumber e = b / (a - c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c * 2 << "\n";
	cout << 0.5 * c << "\n";
	cout << 1 / c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).abs() << "\n";
	cout << ComplexNumber(-1, 1).abs() << "\n";
	cout << ComplexNumber(1.5, 2.4).abs() << "\n";
	cout << ComplexNumber(3, 4).abs() << "\n";
	cout << ComplexNumber(69, -9).abs() << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).angle() << "\n";
	cout << ComplexNumber(-1, 1).angle() << "\n";
	cout << ComplexNumber(-1, -1).angle() << "\n";
	cout << ComplexNumber(1, -1).angle() << "\n";
	cout << ComplexNumber(5, 2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
	cout << (ComplexNumber(1, 1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
