#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
#define MAX 5
int top = -1;

template <class T>
class Stack
{
	T my_stack[MAX];
public:
	void push(T ele);
	T pop();
	void read();
	void display();
	T topele();
	int size();
};

template <class T>
void Stack<T>::push(T element)
{
	if (MAX == top)
			throw "stack full";
	
	my_stack[++top] = element;
}

template <class T>
T Stack<T>::pop()
{
	if (-1 == top)
		throw "stack empty";
	
	return my_stack[top--];
}

template<class T>
void Stack<T>::display()
{
	if (-1 == top)
		throw "stack empty";

	cout << "The elements are: ";
	for (int i = 0; i <= top; i++)
		cout << my_stack[i] << " ";
	cout << endl;
}

template<class T>
T Stack<T>::topele()
{
	if (-1 == top)
		throw "stack empty";

	return my_stack[top];
}

template<class T>
int Stack<T>::size()
{
	if (-1 == top)
		throw "stack empty";

	return (top + 1);
}


template<class T>
void Stack<T>::read()
{
	int option=0, choice=0;
	while (1)
	{
		cout << "choose option: 1.push, 2.pop, 3.size, 4.topele, 5.display, 6.exit\n";
		cin >> option;
		switch (option)
		{
		case 1: { cout << "enter element: ";
			T my_element;
			cin >> my_element;
			push(my_element);
			break;
		}
		case 2: { cout << "Removed element: " << pop() << endl;
			break; }
		case 3: { cout << "Number of elements: " << size() << endl;
			break; }
		case 4: { cout << "Top element: " << topele() << endl;
			break; }
		case 5: { display();
			break; }
		case 6: { break; }

		default: { cout << "invalid choice, exiting loop\n"; }
		}
		cout << "enter -1 to go to main menu: ";
		cin >> choice;
		if (-1 == choice)
			break;
	}

}

void main()
{
	int option=0,choice=0;
	
		while (1)
		{
			cout << "enter choice: 1.int, 2.float, 3.string, 4.exit\n";
			cin >> option;
			switch (option)
			{
			case 1: { Stack<int> int_obj;
				try {
					//s1.push(10);
				//	cout << s1.pop();
					int_obj.read();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break; }
			case 2: { Stack<float> float_obj;
				try {
					//s2.push(23.343534);
					//cout << s2.pop();
					float_obj.read();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}

				break; }
			case 3: { Stack<string> string_obj;
				try {
					//s3.push("navya");
					//cout << s3.pop();
					string_obj.read();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break; }
			case 4: break;
			default: cout << "invalid choice\n";
			}
			
			cout << "enter -1 to stop: ";
			cin >> choice;
			if (-1 == choice)
				break;
		}
	system("pause");
}