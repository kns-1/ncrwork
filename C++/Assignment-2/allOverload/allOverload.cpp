#include<iostream>
#include<conio.h>
using namespace std;
class Complex
{
	double real, imag;
public:
	Complex()
	{
		real = imag = 0;
		cout << "default constructor" << endl;
	}
	Complex(double r)
	{
		real = imag = r;
		cout << "one arg constructor" << endl;
	}
	Complex(double r, double i)
	{
		real = r; imag = i;
		cout << "two arg constructor" << endl;
	}
	Complex(Complex &c)
	{
		real = c.real;
		imag = c.imag;
		cout << "copy constructor" << endl;
	}

	friend istream& operator >> (istream& cin, Complex &c);
	friend ostream& operator<<(ostream& cout, Complex c);
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);
	Complex operator-();
	Complex operator++();
	Complex operator++(int x);


	~Complex()
	{
		cout << "Destructor" << endl;
	}
};


istream& operator >> (istream& cin, Complex &c)
{
	cout << "enter real and imag values: ";
	cin >> c.real >> c.imag;
	return cin;
}

ostream& operator<<(ostream& cout, Complex c)
{
	cout << "RESULT: " << c.real << " +(i) " << c.imag << endl;
	return cout;
}

Complex Complex::operator+(Complex &c)
{
	Complex temp;
	cout << "Binary + operation" << endl;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}

Complex Complex::operator-(Complex &c)
{
	Complex temp;
	cout << "Binary - operation" << endl;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}

Complex Complex::operator-()
{
	Complex temp;
	cout << "Unary - operation" << endl;
	temp.real = -real;
	temp.imag = -imag;
	return temp;
}

Complex Complex::operator++()
{
	Complex temp;
	cout << "Pre-increment operation" << endl;
	temp.real = ++real;
	temp.imag = ++imag;
	return temp;
}

Complex Complex::operator++(int x)
{
	Complex temp;
	cout << "Post-increment operation" << endl;
	temp.real = real++;
	temp.imag = imag++;
	return temp;
}

void main()
{
	Complex c1(10,10);
	Complex c2(c1);
	Complex c3;
	cin >> c1;
	c3 = c1 + c2;
	cout << c3;
	c3 = c1 - c2;
	cout << c3;
	c3=-c3;
	cout << c3;
	c3=++c3;
	cout << c3;
	c3=c3++;
	cout << c3;
	_getch();
}