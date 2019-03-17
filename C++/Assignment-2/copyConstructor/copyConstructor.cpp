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
	Complex(double real_obj)
	{
		real = imag = real_obj;
		cout << "one arg constructor" << endl;
	}
	Complex(double real_obj, double imag_obj)
	{
		real = real_obj; imag = imag_obj;
		cout << "two arg constructor" << endl;
	}
	Complex(Complex &complex_obj)
	{
		real = complex_obj.real;
		imag = complex_obj.imag;
		cout << "copy constructor" << endl;
	}

	friend istream& operator >> (istream& cin, Complex &complex_obj);
	friend ostream& operator<<(ostream& cout, Complex complex_obj);
	Complex operator+(Complex &complex_obj);


	~Complex()
	{
		cout << "Destructor" << endl;
	}
};


istream& operator >> (istream& cin, Complex &complex_obj)
{
	cout << "enter real and imag values to perform addition: ";
	cin >> complex_obj.real >> complex_obj.imag;
	return cin;
}

ostream& operator<<(ostream& cout, Complex complex_obj)
{
	cout << "RESULT: " << complex_obj.real << " +(i) " << complex_obj.imag << endl;
	return cout;
}

Complex Complex::operator+(Complex &complex_obj)
{
	Complex temp;
	cout << "Binary + operation" << endl;
	temp.real = real + complex_obj.real;
	temp.imag = imag + complex_obj.imag;
	return temp;
}

void main()
{
	int num1 = 0, num2 = 0;
	cout << "enter real and imaginary values: ";
		cin >> num1 >> num2;
	Complex complex_num1(num1, num2);
	Complex complex_num2(complex_num1);
	Complex complex_num3;
	cin >> complex_num1;
	complex_num3 = complex_num1 + complex_num2;
	cout << complex_num3;
	_getch();
}