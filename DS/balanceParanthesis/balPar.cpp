#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

int top = -1;

class Stack
{
	char s[100];
public:
	void push(char ele);
	void pop();
	int isempty();
	int bal(string exp);
};

int Stack::isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}


void Stack::push(char ele)
{
	s[++top] = ele;
}


void Stack::pop()
{
    s[top--];
}

int Stack::bal(string exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			push(exp[i]);
		if (exp[i] == ')')
		{
			if (!isempty())
			{
				if (s[top] == '(')
					pop();
			}
			else 
			return -1;
			
		}
		if (exp[i] == ']')
		{
			if (!isempty())
			{
				if (s[top] == '[')
					pop();
			}
			else
				return -1;
		}
		if (exp[i] == '}')
		{
			if (!isempty())
			{
				if (s[top] == '{')
					pop();
			}
			else
				return -1;
		}

	}
	return 0;
}
void main()
{
	Stack ob;
	string exp;
	cout << "Enter expression: ";
	getline(cin, exp);
	cout << "entered expression is: " << exp << endl;
	int n=ob.bal(exp);
	if (ob.isempty() && n==0)
		cout << "Balanced paranthesis";
	else
		cout << "Not balanced";
	_getch();
}