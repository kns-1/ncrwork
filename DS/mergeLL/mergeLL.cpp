#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class MLL
{
	struct node
	{
		T data;
		struct node *link;
	}*first, *last;
public:
	MLL()
	{
		first = NULL, last = NULL;
	}

	void create();
	void display();
	void merge(MLL<T> &l1,MLL<T> &l2);
};

template<class T>
void MLL<T>::merge(MLL<T> &l1, MLL<T> &l2)
{
	struct node *nn = NULL, *t1 = l1.first, *t2 = l2.first;
	while (t1->link!=NULL && t2->link!=NULL)
	{
		nn = t2;
		t2 = t2->link;
		nn->link = t1->link;
		t1->link = nn;
		t1 = t1->link->link; //update t1
	}
	if (t1->link == NULL)
		t1->link = t2;
	else
	{
		t2->link = t1->link;
		t2 = t2->link;
	}
}

template<class T>
void MLL<T>::create()
{
	int ch;
	
	do
	{
		struct node *nn;
		nn = new node;
		cout << "enter element: ";
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
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
}

template<class T>
void MLL<T>::display()
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
		case 1: { MLL<int> l1; MLL<int> l2;
			cout << "LIST - 1" << endl;
			l1.create();
			cout << "LIST - 2" << endl;
			l2.create();
			l1.merge(l1,l2);
			l1.display();
			break; }
		case 2: { MLL<float> l3; MLL<float> l4;
			cout << "LIST - 1" << endl;
			l3.create();
			cout << "LIST - 2" << endl;
			l4.create();
			l3.merge(l3,l4);
			l3.display();
			break; }
		case 3: { MLL<float> l5; MLL<float> l6;
			cout << "LIST - 1" << endl;
			l5.create();
			cout << "LIST - 2" << endl;
			l6.create();
			l5.merge(l5,l6);
			l5.display();
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}