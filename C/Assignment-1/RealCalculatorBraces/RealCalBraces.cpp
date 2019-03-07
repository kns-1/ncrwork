#include<iostream>
#include<stdio.h>
#include<ctype.h>
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
	if ('-' == operator_stack[top_operator])
	{
		if ('-' == operator_stack[top_operator - 1])
			operator_stack[top_operator] = '+';
		cout << "OPERATOR_STACK eval - = " << operator_stack[top_operator] << endl;
	}
	else if ('+' == operator_stack[top_operator])
	{
		if ('-' == operator_stack[top_operator - 1])
			operator_stack[top_operator] = '-';
		cout << "OPERATOR_STACK eval + = " << operator_stack[top_operator] << endl;
	}
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
	{
		if (0 == op2)
		{
			cout << "Divide by Zero exception is caused, Terminating application\n";
			system("pause");
			exit(0);
		}
		result = op1 / op2;
	}
	cout << "RESULT_STACK = " << result << endl;
	push_operand(result);
}


int precedence(char ele)
{
	if ('*' == ele || '/' == ele)
		return 1;

	return 0;
}

int isOperator(char ele)
{
	if ('+' == ele || '-' == ele || '*' == ele || '/' == ele)
		return 1;
	return 0;
}

void main()
{
	char *str = NULL;
	
	int i = 0, temp_ctoi = 1, start_flag = 0, minus_flag = 0;// plus_flag = 0;
		str = (char *)malloc(MAX * sizeof(char));
		cout << "enter string: ";
		cin >> str;
		cout << "entered string is: ";
		cout << str << "\n" << "length = " << strlen(str) << "\n";
		if ('-' == str[0])
		{
			start_flag = 1;
			i++;
		}
		

		while (i < strlen(str))
		{
			if (isdigit(str[i]))
			{
				temp_ctoi = (str[i] - '0');
				i++;
				while (isdigit(str[i]))
				{
					temp_ctoi = temp_ctoi * 10 + (str[i] - '0');
					i++;
				}
				if (1 == start_flag)
				{
					temp_ctoi = -temp_ctoi;
					start_flag = 0;
				}
				push_operand(temp_ctoi);
				cout << "is DIGIT = " << temp_ctoi << endl;
				temp_ctoi = 1;

			}//if(isdigit(str[i]))

			else if (isOperator(str[i]))
			{
				if (isOperator(str[i - 1]))
				{

					if ('-' == str[i] && isdigit(str[i + 1]))
					{
						/*if ('-' == str[i - 1])
							minus_flag = 1;*/
						/*if ('+' == str[i - 1])
							plus_flag = 1;*/
						i++;
						temp_ctoi = (str[i] - '0');
						i++;
						while (isdigit(str[i]))
						{
							temp_ctoi = temp_ctoi * 10 + (str[i] - '0');
							i++;
						}
						//if(0 == minus_flag)
						temp_ctoi = -temp_ctoi;
						push_operand(temp_ctoi);
						/*if (1 == plus_flag)
						{
							operator_stack[top_operator] = '-';
							plus_flag = 0;
						}*/
						temp_ctoi = 1;
						minus_flag = 0;
					}
					else if ('-' == str[i] && isOperator(str[i + 1]))
					{
						if ('*' != operator_stack[top_operator] && '/' != operator_stack[top_operator])
						{
							operator_stack[top_operator] = str[i + 1];
							i += 2;
						}
						cout << "OPERATOR_STACK - op = " << operator_stack[top_operator] << endl;
						i++;
						
					}
					else if ('+' == str[i])
					{
						operator_stack[top_operator] = str[i];
						cout << "OPERATOR_STACK + = " << operator_stack[top_operator] << endl;
						i++;
					}
					else if ('*' == str[i])
					{
						operator_stack[top_operator] = str[i];
						cout << "OPERATOR_STACK * = " << operator_stack[top_operator] << endl;
						i++;
					}
					else if ('/' == str[i])
					{
						operator_stack[top_operator] = str[i];
						cout << "OPERATOR_STACK / = " << operator_stack[top_operator] << endl;
						i++;
					}
					else
					{
						cout << "invalid expression, terminating application\n";
						system("pause");
						exit(0);
					}
				}//if (isOperator(str[i - 1]))
				else
				{
					if (-1 == top_operator)
						push_operator(str[i]);
					else if (precedence(str[i]) > precedence(operator_stack[top_operator]))
						push_operator(str[i]);
					else
					{
						evaluate();
						push_operator(str[i]);
					}
					i++;
				}
			}//else if(isOperator(str[i]))
			else
			{
				cout << "invalid expression, terminating application\n";
				system("pause");
				exit(0);

			}
		} //main while

		if (top_operator > -1)
		{
			while (top_operator > -1)
				evaluate();
		}
		cout << "Result is: " << pop_operand() << endl;
		free(str);
	
	system("pause");
}