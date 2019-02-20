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
	void convert(string exp);
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

void Stack::convert(string exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (isalpha(exp[i]))
			cout << exp[i];
		else if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			for (int i = top; s[i] != '('; i--)
				cout << pop();
			top--;
		}
		else if (top == -1)
			push(exp[i]);
		else
		{
			if (prec(exp[i]) > prec(s[top]))
				push(exp[i]);
			else
			{
				while(top!=-1 && (prec(exp[i])<=prec(s[top])))
				cout << pop();
				push(exp[i]);
			}

		}
		

}
	
}
void main()
{
	Stack ob;
	string exp;
	cout << "Enter expression: ";
	getline(cin, exp);
	cout << "entered expression is: " << exp << endl;
	cout << "POSTFIX: ";
	ob.convert(exp);
	while(top!=-1)
	cout << ob.pop();
	_getch();
}