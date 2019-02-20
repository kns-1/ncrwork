#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class QLL
{
	struct node
	{
		T data;
		struct node *link;
	}*first, *last;
public:
	QLL()
	{
		first = NULL, last = NULL;
	}
	void read();
	void insert();
	void remove();
	void display();
};

template<class T>
void QLL<T>::read()
{
	int n, ch;
	do
	{
		cout << "choose option: 1.insert, 2.remove, 3.display, 4.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:	insert();
			break;
		case 2: remove();
			break;
		case 3: display();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);

}



template<class T>
void QLL<T>::insert()
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
void QLL<T>::remove()
{
	if (first == NULL)
	{
		cout << "queue list empty" << endl;
		return;
	}
	else
	{
		cout << "Removed element is: " << first->data << endl;
		first=first->link;
	}
}

template<class T>
void QLL<T>::display()
{
	if (first == NULL)
	{
		cout << "queue list empty" << endl;;
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
		case 1: { QLL<int> l1;
			l1.read();
			break; }
		case 2: { QLL<float> l2;
			l2.read();
			break; }
		case 3: { QLL<char> l3;
			l3.read();
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}