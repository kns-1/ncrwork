#include<conio.h>
#include<iostream>
using namespace std;

class Complex
{
	double real, imag;
public:
	Complex()
	{
		real = imag = 0;
	}
	Complex(double v)
	{
		real = imag = v;
	}
	Complex(double r, double i)
	{
		real = r; imag = i;
	}
	friend void addComplex(Complex &c1, Complex &c2);
	friend void multiplyComplex(Complex &c1, Complex &c2);
	void displayComplex()
	{
		cout << "result is: " << real << "+(i)" << imag<<endl;
	}
};
void addComplex(Complex &c1, Complex &c2)
{
	Complex c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	cout << "Addition ";
	c.displayComplex();
}

void multiplyComplex(Complex &c1, Complex &c2)
{
	Complex c;
	c.real = c1.real * c2.real - c1.imag * c2.imag;
	c.imag = c1.real * c2.imag + c2.real + c1.imag;
	cout << "Multiplication ";
	c.displayComplex();
}
void main()
{
	Complex c1(20.234, 12.212);
	Complex c2(86.124);
	Complex c3;
	addComplex(c1, c2);
	multiplyComplex(c1, c2);
	_getch();
}
