#include<iostream>
#include<conio.h>
#include<string>
#define EMPLOYEE_COUNT 5
using namespace std;
class Employee
{
	int emp_id, emp_salary;
	string emp_name;
public:
	Employee()
	{
		cout << "Default constructor"<<endl;
	}
	Employee(Employee emp_obj[], int n)
	{
		cout << "Parameterized constructor" << endl;
		for (int i = 0; i < n; i++)
			cin >> emp_obj[i];
	}
	friend istream& operator >> (istream& cin, Employee &emp_obj);
	void display()
	{
		cout << "Employee Details:" << endl;
		cout << "emp_name: " << emp_name << endl << "emp_id: " << emp_id << endl;
		cout << "emp_salary = " << emp_salary << endl << endl;
	}
	~Employee()
	{
		cout << "Destructor" << endl;
	}
};
istream& operator >> (istream& cin, Employee &emp_obj)
{
	cout << "enter emp_id and emp_name (seperated by spaces): ";
	cin >> emp_obj.emp_id;
	getline(cin, emp_obj.emp_name);
	cout << "enter emp_salary: ";
	cin >> emp_obj.emp_salary;
	return cin;
}
void main()
{
	Employee emp_obj1[EMPLOYEE_COUNT];
	Employee emp_obj2(emp_obj1, EMPLOYEE_COUNT);
	for (int i = 0; i < EMPLOYEE_COUNT; i++)
		emp_obj1[i].display();

	_getch();
}