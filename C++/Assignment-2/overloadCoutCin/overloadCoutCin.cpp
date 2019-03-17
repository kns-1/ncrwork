#include<iostream>
#include<conio.h>
#include<string>
#define STUDENT_COUNT 2
using namespace std;

class Student
{
	int stud_id, marks1, marks2, total_marks;
	char grade;
	string stud_name;

public:
	friend void generate_results(Student stud_obj[]);
	friend istream& operator >> (istream& cin, Student &stud_obj);
	friend ostream& operator<<(ostream& cout, Student stud_obj);
};


istream& operator >> (istream& cin, Student &stud_obj)
{
	cout << "enter stud_id and stud_name (spaces seperated): ";
	cin >> stud_obj.stud_id;

	getline(cin, stud_obj.stud_name);

	cout << "enter 2 marks: ";
	cin >> stud_obj.marks1 >> stud_obj.marks2;

	stud_obj.total_marks = stud_obj.marks1 + stud_obj.marks2;

	return cin;
}


ostream& operator<<(ostream& cout, Student stud_obj)
{
	cout << "Student Details:" << endl;
	cout << "stud_name: " << stud_obj.stud_name << endl << "Roll number: " << stud_obj.stud_id << endl;
	cout << "Marks: marks1 = " << stud_obj.marks1 << ", marks2 = " << stud_obj.marks2 << endl;
	cout << "total_marks = " << stud_obj.total_marks<<endl;
	cout << "Grade = " << stud_obj.grade << endl << endl;
	return cout;
}


void generate_results(Student stud_obj[])
{
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		if (stud_obj[i].total_marks >= 15)
			stud_obj[i].grade = 'A';

		else if (stud_obj[i].total_marks >= 10 && stud_obj[i].total_marks < 15)
			stud_obj[i].grade = 'B';

		else if (stud_obj[i].total_marks >= 5 && stud_obj[i].total_marks < 10)
			stud_obj[i].grade = 'C';

		else
			stud_obj[i].grade = 'F';
	}
	
}

void main()
{
	Student stud_obj[STUDENT_COUNT];

	for (int i = 0; i < STUDENT_COUNT; i++)
		cin >> stud_obj[i];

	generate_results(stud_obj);

	for (int i = 0; i < STUDENT_COUNT; i++)
		cout << stud_obj[i];

	_getch();
}
