#include<iostream>
using namespace std;

class Complex
{
	double real, imag;

public:

	Complex()
	{
		real = imag = 0;
		cout << "Default Constructor\n";
		//displayComplex();
	}

	Complex(double num)
	{
		real = imag = num;
		cout << "One argument Constructor\n";
		//displayComplex();
	}

	Complex(double real_arg, double imag_arg)
	{
		real = real_arg; imag = imag_arg;
		cout << "Two argument Constructor\n";
	//	displayComplex();
	}

	friend void addComplex(Complex &complex_obj1, Complex &complex_obj2);
	friend void multiplyComplex(Complex &complex_obj1, Complex &complex_obj2);

	void displayComplex()
	{
		cout << "Result is: " << real << "+(i)" << imag <<"\n";
	}

	~Complex()
	{
		cout << "Destructor\n";
	}
};


void addComplex(Complex &complex_obj1, Complex &complex_obj2)
{
	Complex temp;
	temp.real = complex_obj1.real + complex_obj2.real;
	temp.imag = complex_obj1.imag + complex_obj2.imag;
	cout << "Addition ";
	temp.displayComplex();
}


void multiplyComplex(Complex &complex_obj1, Complex &complex_obj2)
{
	Complex temp;
	temp.real = complex_obj1.real * complex_obj2.real - complex_obj1.imag * complex_obj2.imag;
	temp.imag = complex_obj1.real * complex_obj2.imag + complex_obj2.real + complex_obj1.imag;
	cout << "Multiplication ";
	temp.displayComplex();
}


void main()
{
	double num1 = 0, num2 = 0, num3 = 0;
	cout << "Enter three numbers: ";
	cin >> num1 >> num2 >> num3;
	Complex complex_obj1(num1, num2);
	Complex complex_obj2(num3);
	Complex complex_obj3;

	addComplex(complex_obj1, complex_obj2);
	multiplyComplex(complex_obj1, complex_obj2);

	system("pause");
}
