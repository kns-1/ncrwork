#include<conio.h>
#include<iostream>
using namespace std;
class Arithmetic
{
	int a, b;
public:
	Arithmetic(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void add();
	void sub();
	void mul();
	void div();
};
inline void Arithmetic::add()
{
	cout<<"Addition: "<<a+b<<endl;
}
inline void Arithmetic::sub()
{
	cout << "Subtraction: " << a - b << endl;
}
inline void Arithmetic::mul()
{
	cout << "Multiplication: " << a * b << endl;
}
inline void Arithmetic::div()
{
	cout << "Division: " << a / b << endl;
}

void main()
{
	Arithmetic a(20,10);
	a.add();
    a.sub();
	a.mul();
	a.div();
	_getch();
}