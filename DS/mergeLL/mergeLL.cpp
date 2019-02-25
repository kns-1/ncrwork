#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class MLL
{
public:
	struct node
	{
		T data;
		struct node *link;
	}*first, *last, *firstnn;

	MLL()
	{
		first = NULL, last = NULL, firstnn=NULL;
	}

	void create();
	void display(struct node *f);
	void merge(MLL<T> &l2);
};

template<class T>
void MLL<T>::merge(MLL<T> &l2)
{
	struct node *nn=NULL, *t1 = first , *t2 = l2.first, *temp=NULL;
	
	while (t1!=NULL && t2!=NULL)
	{
		nn = new node;
		nn->link = NULL;
		if (firstnn == NULL)
		{
			firstnn = nn;
			temp = nn;
		}
		else {
			temp->link = nn;
			temp = temp->link;
		}
		if (t1->data <= t2->data)
		{
			nn->data = t1->data;
			t1 = t1->link;
		}
		else
		{
			nn->data = t2->data;
			t2 = t2->link;
		}
	}
	if (t1 == NULL)
	{
		temp->link = t2;
	}
	if (t2 == NULL)
	{
		temp->link = t1;
	}
	
	display(firstnn);
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
void MLL<T>::display(struct node *f)
{
	if (f == NULL)
	{
		cout << "list empty" << endl;;
		return;
	}
	else
	{
		struct node *temp = f;
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
			l1.display(l1.first);
			l2.display(l2.first);
			l1.merge(l2);
			break; }
		case 2: { MLL<float> l3; MLL<float> l4;
			cout << "LIST - 1" << endl;
			l3.create();
			cout << "LIST - 2" << endl;
			l4.create();
			l3.display(l3.first);
			l4.display(l4.first);
			l3.merge(l4);
			break; }
		case 3: { MLL<float> l5; MLL<float> l6;
			cout << "LIST - 1" << endl;
			l5.create();
			cout << "LIST - 2" << endl;
			l6.create();
			l5.display(l5.first);
			l6.display(l6.first);
			l5.merge(l6);
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}