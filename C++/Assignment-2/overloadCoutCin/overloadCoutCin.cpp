#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Student
{
	int rno, m1,m2, total;
	char grade;
	string name;
public:
	friend void generate_results(Student s[], int n);
	friend istream& operator >> (istream& cin, Student &s);
	friend ostream& operator<<(ostream& cout, Student s);
};
istream& operator >> (istream& cin, Student &s)
{
	cout << "enter rno and name (spaces seperated): ";
	cin >> s.rno;
	getline(cin,s.name);
	cout << "enter 2 marks: ";
	cin >> s.m1 >> s.m2;
	s.total = s.m1 + s.m2;
	return cin;
}
ostream& operator<<(ostream& cout, Student s)
{
	cout << "Student Details:" << endl;
	cout << "Name: " << s.name << endl << "Roll number: " << s.rno << endl;
	cout << "Marks: m1 = " << s.m1 << ", m2 = " << s.m2 << endl;
	cout << "Total = " << s.total<<endl;
	cout << "Grade = " << s.grade << endl << endl;
	return cout;
}
void generate_results(Student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i].total >= 15)
			s[i].grade = 'A';
		else if (s[i].total >= 10 && s[i].total < 15)
			s[i].grade = 'B';
		else if (s[i].total >= 5 && s[i].total < 10)
			s[i].grade = 'C';
		else
			s[i].grade = 'F';
	}
	
}

void main()
{
	const int n=2;
	Student s1[n];
	for (int i = 0; i < n; i++)
		cin >> s1[i];
	generate_results(s1, n);
	for (int i = 0; i<n; i++)
		cout << s1[i];
	_getch();
}
