#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class DLL
{
	struct node
	{
		T data;
		struct node *rlink, *llink;
	}*first, *last;
public:
	DLL()
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
void DLL<T>::read()
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
void DLL<T>::create()
{
	struct node *nn;
	nn = new node;
	cout << "enter element: ";
	cin >> nn->data;
	nn->llink = NULL;
	nn->rlink = NULL;

	if (first == NULL)
	{
		first = nn, last = nn;
	}
	else
	{
		last->rlink = nn;
		last = nn;
	}

}
template<class T>
void DLL<T>::insert()
{
	struct node *nn = NULL, *temp = first;
	nn = new node;
	cout << "enter element: ";
	cin >> nn->data;
	nn->llink = NULL;
	nn->rlink = NULL;
	int ch;
	cout << "1.first, 2.middle, 3.end, 4.exit\n";
	cin >> ch;
	switch (ch)
	{
	case 1: nn->rlink = first;
		first->llink = nn;
		first = nn;
		break;
	case 2:	int pos;
		cout << "enter new position of node: ";
		cin >> pos;
		for (int i = 0; i < pos - 1; i++)
			temp = temp->rlink;
		nn->rlink = temp->rlink;
		temp->rlink->llink = nn;
		temp->rlink = nn;
		nn->llink = temp;
		break;
	case 3: last->rlink = nn;
		nn->llink = last;
		last = nn;
		break;
	}

}

template<class T>
void DLL<T>::remove()
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
			first = first->rlink;
			first->llink = NULL;
			break;
		case 2: {	int pos;
			cout << "enter position of node: ";
			cin >> pos;
			for (int i = 0; i < pos - 1; i++)
				temp = temp->rlink;
			cout << "Removed element is: " << temp->rlink->data << endl;
			temp->rlink = temp->rlink->rlink;
			temp->rlink->rlink->llink = temp;
			break; }
		case 3: if (first->rlink == NULL)
		{
			cout << "Removed element is: " << temp->data << endl;
			first = NULL;
			break;
		}
			while (temp->rlink != last)
			temp = temp->rlink;
			cout << "Removed element is: " << temp->rlink->data << endl;
			last = temp;
			last->rlink = NULL;
			break;
		}
	}
}

template<class T>
void DLL<T>::display()
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
		while (temp->rlink != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->rlink;
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
		case 1: { DLL<int> l1;
			l1.read();
			break; }
		case 2: { DLL<float> l2;
			l2.read();
			break; }
		case 3: { DLL<char> l3;
			l3.read();
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}