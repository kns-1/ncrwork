#include<iostream>
#include<conio.h>
#include<string>
#include<ctype.h>
using namespace std;

int top = -1;

class Stack
{
	char s[100];
public:
	void push(char ele);
	char pop();
	void eval(string exp);
	int prec(char ch);
};
int Stack::prec(char ch)
{
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '(')
		return 0;
	else
		return NULL;
}
void Stack::push(char ele)
{
	s[++top] = ele;
}


char Stack::pop()
{
	return s[top--];
}

void Stack::eval(string exp)
{
	int a, b;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (isalpha(exp[i]))
		{
			int v;
			cout << "enter value: ";
			cin >> v;
			push(v);
		}
		else
		{
			b = pop();
			a = pop();
			switch (exp[i])
			{
			case '+': push(a+b); break;
			case '-': push(a-b); break;
			case '*': push(a*b); break;
			case '/': push(a/b); break;
			}
		}
	}
}
void main()
{
	Stack ob;
	string exp;
	cout << "Enter postfix expression: ";
	getline(cin, exp);
	cout << "entered expression is: " << exp << endl;
	ob.eval(exp);
	cout << "Result is: " << (int)ob.pop();
	_getch();
}