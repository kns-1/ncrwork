#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class LL
{
	struct node
	{
		T data;
		struct node *link;
	}*first, *last;
public:
	LL()
	{
		 first = NULL, last = NULL;
	}
	void read();
	void create();
	void insert();
	void remove();
	void display();
};

template<class T>
void LL<T>::read()
{
	int n, ch;
do
	{
		cout << "choose option: 1.create, 2.insert, 3.remove, 4.display, 5.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:	create();
			break;
		case 2: insert();
			break;
		case 3: remove();
			break;
		case 4: display();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
} while (ch != -1);

}


template<class T>
void LL<T>::create()
{
	struct node *nn;
	nn = new node;
	cout<<"enter element: ";
	cin >> nn->data;
	nn->link = NULL;

	if (first == NULL)
	{
		first = nn, last = nn;
	}
	else
	{
		last->link = nn;
		last = nn;
	}
	
}
template<class T>
void LL<T>::insert()
{
	struct node *nn=NULL,*temp=first;
	nn = new node;
	cout << "enter element: ";
	cin >> nn->data;
	nn->link = NULL;
	int ch;
	cout << "1.first, 2.middle, 3.end, 4.exit\n";
	cin >> ch;
	switch (ch)
	{
	case 1: nn->link = first;
		first = nn;
		break;
	case 2:	int pos;
		
		cout << "enter new position of node: ";
		cin >> pos;
		for (int i = 0; i < pos-1; i++)
			temp = temp->link;
		nn->link = temp->link;
		temp->link = nn;
		break;
	case 3: last->link = nn;
		last = nn;
		break;
	}

}

template<class T>
void LL<T>::remove()
{
	if (first == NULL)
	{
		cout << "list empty" << endl;
		return;
	}
	else
	{
		struct node *temp = first;
		int ch;
		cout << "1.first, 2.middle, 3.end, 4.exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "Removed element is: " << first->data << endl;
			first = first->link;
			break;
		case 2:	int pos;
			cout << "enter position of node: ";
			cin >> pos;
			for (int i = 0; i < pos-1; i++)
				temp = temp->link;
			cout << "Removed element is: " << temp->link->data << endl;
			temp->link = temp->link->link;
			break;
		case 3: while (temp->link != last)
			temp = temp->link;
			cout << "Removed element is: " << temp->link->data << endl;
			last = temp;
			last->link = NULL;
			break;
		}
	}
}

template<class T>
void LL<T>::display()
{
	if (first == NULL)
	{
		cout << "list empty" << endl;;
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
		case 1: {LL<int> l1;
			l1.read();
			break; }
		case 2: {LL<float> l2;
			l2.read();
			break; }
		case 3: {LL<char> l3;
			l3.read();
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}