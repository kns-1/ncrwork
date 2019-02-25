#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class PLL
{
public:
	struct node
	{
		T coef;
		int power;
		struct node *link;
	}*first, *last, *firstnn;

	PLL()
	{
		first = NULL, last = NULL, firstnn=NULL;
	}

	void create();
	void polyadd(struct node *l1, struct node *l2);
	void display(struct node *f);
};

template<class T>
void PLL<T>::polyadd(struct node *l1, struct node *l2)
{
	struct node *nn=NULL, *t1 = l1, *t2 = l2, *tempo = NULL;
	while (t1!=NULL && t2!=NULL)
	{
		nn = new node;
		nn->link = NULL;
		if (NULL==firstnn)
		{
			firstnn = nn;
			tempo = nn;
		}
		else {
				tempo->link = nn;
				tempo = tempo->link;
		}
			if (t1->power == t2->power)
			{
				nn->coef = t1->coef + t2->coef;
				nn->power = t1->power;
				t1 = t1->link;
				t2 = t2->link;
			}
			else if (t1->power > t2->power)
			{
				nn->coef = t1->coef;
				nn->power = t1->power;
				t1 = t1->link;
			}
			else
			{
				nn->coef = t2->coef;
				nn->power = t2->power;
				t2 = t2->link;
			}
	}
	if (t1 == NULL)
	{
		tempo->link = t2;
	}
	if (t2 == NULL)
	{
			tempo->link = t1;
	}

display(firstnn);
}



template<class T>
void PLL<T>::create()
{
	int ch;

	do
	{
		struct node *nd;
		nd = new node;
		cout << "enter coefficent and power: ";
		cin >> nd->coef>>nd->power;
		nd->link = NULL;

		if (first == NULL)
		{
			first = nd, last = nd;
		}
		else
		{
			last->link = nd;
			last = nd;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
}

template<class T>
void PLL<T>::display(struct node *f)
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
			cout << temp->coef<<" x^"<<temp->power << " -> ";
			temp = temp->link;
		}
		cout << temp->coef << " x^" << temp->power << endl;
	}
}


void main()
{
	int n, ch;
	do
	{
		cout << "enter choice: 1.int, 2.float, 3.exit\n";
		cin >> n;
		switch (n)
		{
		case 1: { PLL<int> l1; PLL<int> l2;
			cout << "LIST - 1" << endl;
			l1.create();
			cout << "LIST - 2" << endl;
			l2.create();
			l1.display(l1.first);
			l2.display(l2.first);
			l1.polyadd(l1.first, l2.first);
			break; }
		case 2: { PLL<float> l3; PLL<float> l4;
			cout << "LIST - 1" << endl;
			l3.create();
			cout << "LIST - 2" << endl;
			l4.create();
			l3.display(l3.first);
			l4.display(l4.first);
			l3.polyadd(l3.first, l4.first);
			break; }
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
	} while (ch != -1);
	_getch();
}