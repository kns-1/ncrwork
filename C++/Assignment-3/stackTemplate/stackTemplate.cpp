#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 5
int top = -1;
template <class T>
class Stack
{
	T s[MAX];
public:
	void push(T ele);
	T pop();
};

template <class T>
void Stack<T>::push(T ele)
{
	if (top == MAX)
			throw "stack full";
	
	s[++top] = ele;
}

template <class T>
T Stack<T>::pop()
{
	if (top == -1)
	{
		throw "stack empty";
		return 0;
	}
	return s[top--];
}

void main()
{
	int n,ch;
	
		while (1)
		{
			cout << "enter choice: 1.int, 2.float, 3.char, 4.exit\n";
			cin >> n;
			switch (n)
			{
			case 1: Stack<int> s1;
				try {
					s1.push(10);
					cout << s1.pop();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			case 2: Stack<float> s2;
				try {
					//s2.push(23.343534);
					cout << s2.pop();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			case 3: Stack<char *> s3;
				try {
					s3.push("navya");
					//cout << s3.pop();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			}
			cout << "enter -1 to stop: ";
			cin >> ch;
			if (ch == -1)
				break;
		}
	_getch();
}