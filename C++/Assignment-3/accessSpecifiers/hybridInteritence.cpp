#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class Person //base class
{
	string name;
	int age;
public:
	virtual void read()
	{
		cout << "enter name, age: ";
		getline(cin, name);
		cin >> age;
	}
	virtual void show()
	{
		cout << "Name = " << name << "\nAge = " << age << endl;
	}
};
class Physique :public virtual Person
{
	int ht, wt;
public:
	void read()
	{
		cout << "enter height, weigt: ";
		cin >> ht >> wt;
	}
	void show()
	{
		cout << "Height = " << ht << "\nWeight = " << wt << endl;
	}
};
class Family :public virtual Person
{
	int numChildren;
	string religion;
public:
	void read()
	{
		cout << "enter number of children, religion: ";
		cin >> numChildren;
		getline(cin, religion);
	}
	void show()
	{
		cout << "Number of children = " << numChildren << "\nReligion = " << religion << endl;
	}
};
class Employee :public Physique, public Family
{
	int empno, sal;
public:
	void read()
	{
		cout << "enter empno, salary: ";
		cin >> empno >> sal;
	}
	void show()
	{
		cout << "Empno = " << empno << "\nSalary = " << sal << endl;
	}
};

void main()
{
	Person *p;
	p = new Person();
	p->read();
	p->show();
	p = new Physique();
	p->read();
	p->show();
	p = new Family();
	p->read();
	p->show();
	Employee *e = new Employee();
	e->read();
	e->show();
	_getch();
}