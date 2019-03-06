#include<iostream>
using namespace std;
#define MAX 100

int top_operand = -1, top_operator = -1, result = 0;
int operand_stack[MAX]; //operand stack
char operator_stack[MAX]; //operator stack

void push_operand(int ele)
{
	operand_stack[++top_operand] = ele;
}
void push_operator(char ele)
{
	operator_stack[++top_operator] = ele;
}
int pop_operand()
{
	return operand_stack[top_operand--];
}
char pop_operator()
{
	return operator_stack[top_operator--];
}
void evaluate()
{
	int op2 = 0, op1 = 0;
	op2 = pop_operand();
	op1 = pop_operand();
	char ele = pop_operator();
	if ('+' == ele)
		result = op1 + op2;
	if ('-' == ele)
		result = op1 - op2;
	if ('*' == ele)
		result = op1 * op2;
	if ('/' == ele)
		result = op1 / op2;
	push_operand(result);
}


int precedence(char ele)
{
	if ('*' == ele || '/' == ele)
		return 1;
	if ('+' == ele || '-' == ele)
		return 0;
	return -1;
}

void main()
{
	int num = 0, checker = 0;
	char ch=NULL, choice=NULL;
	do
	{
	cout << "enter string, enter '#' to terminate:\n";
	
		while (1)
		{
			if (checker % 2 == 0)
			{
				cin >> num;
				push_operand(num);
			}
			else
			{
				cin >> ch;

				if ('#' == ch)
					break;

				else if ('+' == ch || '-' == ch || '*' == ch || '/' == ch)
				{
					if (-1 == top_operator)
						push_operator(ch);
					else if (precedence(ch) > precedence(operator_stack[top_operator]))
						push_operator(ch);
					else
					{
						evaluate();
						push_operator(ch);
					}
				}
				else
				{
					cout << "invalid entry, application terminated\n";
					system("pause");
					exit(0);
				}
			}
			checker++;

			if ('#' == ch)
				break;
		}//while
		
	if (top_operator > -1)
	{
		while (top_operator > -1)
			evaluate();
	}
	cout << "Result is: " << pop_operand() << endl;
	push_operand(result);
	cout << "continue? y/n: ";
	cin >> choice;
	checker = 1;
	} while (choice != 'n');

	system("pause");
}