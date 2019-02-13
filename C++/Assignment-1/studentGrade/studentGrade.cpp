#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	string name;
	char grade;
	int marks[3];
};
class CollegeCourse
{
	int avg;
	char section;
	Student s;
public:
	void set_Data(string name1, char grade1, int m1, int m2, int m3)
	{
		s.name = name1;
		s.marks[0] = m1; s.marks[1] = m2; s.marks[2] = m3;
		section = grade1;
	}
	void calculateAverage()
	{
		avg = (s.marks[0] + s.marks[1] + s.marks[2]) / 3;
	}
	void computeGrade()
	{
		if (avg >= 60)
			s.grade = 'A';
		else if (avg >= 50 && avg < 60)
			s.grade = 'B';
		else if (avg >= 40 && avg < 50)
			s.grade = 'C';
		else
			s.grade = 'F';
	}
	void displayDetails()
	{
		cout << "Student Name: " << s.name << endl <<"Section: "<<section<<endl<<"Average: " << avg << endl << "Grade: " << s.grade<<endl;
	}
};
void main()
{
	CollegeCourse c;
	string name;
	int m1,m2,m3;
	char section;
	cout<<"enter student name: ";
	getline(cin, name);
	cout<<"enter section(char): ";
	cin >> section;
	cout<<"enter 3 subject marks(out of 100): ";
	cin >> m1 >> m2 >> m3;
	c.set_Data(name,section, m1, m2, m3);
	c.calculateAverage();
	c.computeGrade();
	c.displayDetails();
	_getch();
}