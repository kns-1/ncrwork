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
	void read();
	T topele();
	int size();
	T pop();
	void display();
};

template<class T>
void Stack<T>::display()
{
	if (top == -1)
	{
		cout << "stack empty" << endl;
		return;
	}
	cout << "The elements are: ";
	for (int i = 0; i <= top; i++)
		cout << s[i] << " ";
	cout << endl;
}

template<class T>
T Stack<T>::topele()
{
	if (top == -1)
	{
		cout << "stack empty" << endl;
		return NULL;;
	}
	return s[top];
}
template<class T>
int Stack<T>::size()
{
	if (top == -1)
	{
		cout << "stack empty" << endl;
		return NULL;
}
	return (top + 1);
}

template <class T>
void Stack<T>::push(T ele)
{
	if (top == MAX)
	{
		cout << "stack full"<<endl;
		return;
	}

	s[++top] = ele;
}

template <class T>
T Stack<T>::pop()
{
	if (top == -1)
	{
		cout<<"stack empty"<<endl;
		return NULL;
	}
	return s[top--];
}

template<class T>
void Stack<T>::read()
{
	int n,ch;	
	while (1)
	{
		cout << "choose option: 1.push, 2.pop, 3.size, 4.topele, 5.display 6.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:	T ele; 
			cout << "enter element: ";
			cin >> ele;
			push(ele);
			break;
		case 2: cout<<"Removed element: "<<pop()<<endl;
			break;
		case 3: cout<<"Number of elements: "<<size()<<endl;
			break;
		case 4: cout<<"Top element: "<<topele()<<endl;
			break;
		case 5: display();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
		if (ch == -1)
			break;
	}
	
}

void main()
{
	int n, ch;

	while (1)
	{
		cout << "enter choice: 1.int, 2.float, 3.char, 4.exit\n";
		cin >> n;
		switch (n)
		{
		case 1: Stack<int> s1;
			s1.read();
			break;
		case 2: Stack<float> s2;
			s2.read();
			break;
		case 3: Stack<char> s3;
			s3.read();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
		if (ch == -1)
			break;
	}
	_getch();
}