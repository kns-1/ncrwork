#include<iostream>
#include<conio.h>
using namespace std;

class Swapping
{ 
	
public:
	void swap_val(int a, int b)
	{
		a = a + b; b = a - b; a = a - b;
	}
	void swap_ref(int &a, int &b)
	{
		a = a + b; b = a - b; a = a - b;
	}
};

void main()
{
	int n,a,b;
	Swapping s;
	cout << "enter a and b: ";
	cin >> a >> b;
	cout << "Enter choice: 1.call-by-value, 2.call-by-reference, 3.exit" << endl;
	cin >> n;
	switch (n)
	{
	case 1: s.swap_val(a, b); 
		cout<<"a= "<<a<<", b= "<<b<<endl;
		break;
	case 2: s.swap_ref(a, b);
		cout << "a= " << a << ", b= " << b << endl;
		break;
	default: cout << "invalid choice";
	}
	_getch();
}