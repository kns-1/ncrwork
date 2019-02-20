#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class SLL
{
	struct node
	{
		T data;
		struct node *link;
	}*first, *last;
public:
	SLL()
	{
		first = NULL, last = NULL;
	}
	void read();
	void push();
	void pop();
	void display();
};

template<class T>
void SLL<T>::read()
{
	int n, ch;
	do
	{
		cout << "choose option: 1.push, 2.pop, 3.display, 4.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:	push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);

}



template<class T>
void SLL<T>::push()
{
	struct node *nn = NULL;
	nn = new node;
	cout << "enter element: ";
	cin >> nn->data;
	nn->link = NULL;
	if (first == NULL)
	{
		first = nn;
		last = nn;
	}
	else 
	{
		last->link = nn;
		last = nn;
	}
}

template<class T>
void SLL<T>::pop()
{
	if (first == NULL)
	{
		cout << "stack list empty" << endl;
		return;
	}
	else
	{
		struct node *temp = first;
		while (temp->link != last)
			temp = temp->link;
			cout << "Removed element is: " << temp->link->data << endl;
			last = temp;
			last->link = NULL;
		}
}

template<class T>
void SLL<T>::display()
{
	if (first == NULL)
	{
		cout << "stack list empty" << endl;;
		return;
	}
	else
	{
		struct node *temp = first;
		cout << "List is: ";
		while (temp->link != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->link;
		}
		cout << temp->data << endl;
	}
}

void main()
{
	int n, ch;
	do
	{
		cout << "enter choice: 1.int, 2.float, 3.char, 4.exit\n";
		cin >> n;
		switch (n)
		{
		case 1: { SLL<int> l1;
			l1.read();
			break; }
		case 2: { SLL<float> l2;
			l2.read();
			break; }
		case 3: { SLL<char> l3;
			l3.read();
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}