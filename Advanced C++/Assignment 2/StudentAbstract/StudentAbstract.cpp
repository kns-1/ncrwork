#include<iostream>
#include "File1.cpp"
#include "File2.cpp"
using namespace std;
//using namespace MyNamespace1;
//using namespace MyNamespace2;

void main()
{
	int num1 = 0, num2 = 0;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	MyNamespace1::MyClass obj1;
	MyNamespace2::MyClass obj2;
	cout << "MyNamespace 1:\n Addition= " << obj1.addition(num1, num2) << "\n Subtraction= " << obj1.subtraction(num1, num2) << "\n";
	cout << "MyNamespace 2:\n Addition= " << obj2.addition(num1, num2) << "\n Subtraction= " << obj2.subtraction(num1, num2) << "\n";
	system("pause");
}