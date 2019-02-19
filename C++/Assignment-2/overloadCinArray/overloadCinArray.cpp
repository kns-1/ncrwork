#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Employee
{
	int id, sal;
	string name;
public:
	Employee()
	{
		cout << "Default constructor"<<endl;
	}
	Employee(Employee e[], int n)
	{
		cout << "Parameterized constructor" << endl;
		for (int i = 0; i < n; i++)
			cin >> e[i];
	}
	friend istream& operator >> (istream& cin, Employee &e);
	void display()
	{
		cout << "Employee Details:" << endl;
		cout << "Name: " << name << endl << "ID: " << id << endl;
		cout << "Salary = " << sal << endl << endl;
	}
	~Employee()
	{
		cout << "Destructor" << endl;
	}
};
istream& operator >> (istream& cin, Employee &e)
{
	cout << "enter id and name (seperated by spaces): ";
	cin >> e.id;
	getline(cin, e.name);
	cout << "enter salary: ";
	cin >> e.sal;
	return cin;
}
void main()
{
	const int n = 5;
	Employee e[n];
	Employee e1(e, n);
	for (int i = 0; i < n; i++)
		e[i].display();

	_getch();
}