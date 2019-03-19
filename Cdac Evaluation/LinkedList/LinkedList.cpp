#include<iostream>
using namespace std;

template <class T>
class LLClass
{
	int list_size = 0;
public:
	struct node
	{
		T data;
		struct node *link;
	}*root, *last;

	LLClass()
	{
		root = NULL;
		last = NULL;
	}

	void create();
	void insert();
	void deletion();
	void display();
	void reverse();
	void read();
};


template<class T>
void LLClass<T>::create()
{
	struct node *newnode = NULL;
	T element = 0;
	int choice = 0;
	do
	{
		newnode = new node;
		cout << "Enter element: ";
		cin >> element;
		newnode->data = element;
		newnode->link = NULL;

		if (NULL == root)
		{
			root = newnode;
			last = newnode;
			list_size++;
		}
		else
		{
			last->link = newnode;
			last = newnode;
			list_size++;
		}
		cout << "Enter -1 to stop: ";
		cin >> choice;
	} while (-1 != choice);
}



template<class T>
void LLClass<T>::insert()
{
	struct node *newnode = NULL, *temp = NULL;
	T element = 0;

	newnode = new node;
	cout << "Enter element: ";
	cin >> element;
	newnode->data = element;
	newnode->link = NULL;

	if (NULL == root)
	{
		root = newnode;
		last = newnode;
		list_size++;
	}
	else
	{
		temp = root;
		cout << "Enter position to insert: 1.beginning, 2.middle, 3.end\n";
		int pos = 0;
		cin >> pos;
		switch (pos)
		{
		case 1: {
			newnode->link = root;
			root = newnode;
			list_size++;
			break;
		}

		case 2: {
			struct node *temp = root;
			cout << "enter the position number: ";
			int pos_num = 0;
			cin >> pos_num;
			if (pos_num > list_size)
			{
				cout << "invalid position\n";
				break;
			}
			if (0 == pos_num)
			{
				newnode->link = root;
				root = newnode;
			}

			else if (list_size == pos_num)
			{
				last->link = newnode;
				last = newnode;
			}

			else
			{
				for (int i = 0; i < pos_num - 1; i++)
					temp = temp->link;

				newnode->link = temp->link;
				temp->link = newnode;
			}
			list_size++;
			break;
		}
		case 3: {
			last->link = newnode;
			last = newnode;
			list_size++;
			break;
		}
		default: cout << "invalid position\n";
		}
	}
}


template<class T>
void LLClass<T>::deletion()
{
	if (NULL == root)
	{
		cout << "List empty, terminating application\n";
		system("pause");
		exit(0);
	}

	struct node *newnode = NULL, *temp = NULL, *delnode = NULL;
	T element = 0;

	cout << "Enter element to delete: ";
	cin >> element;

	if (element == root->data)
	{
		delnode = root;
		root = root->link;
	}
	else if (element == last->data)
	{
		struct node *temp = root;
		while (temp->link != last)
			temp = temp->link;

		temp->link = NULL;
		delnode = last;
		last = temp;
	}
	else
	{
		temp = root;
		int flag = 0, pos_num = 0;
		while (temp != NULL)
		{
			if (element == temp->data)
			{
				flag = 1;
				break;
			}
			temp = temp->link;
			pos_num++;
		}
		if (0 == flag)
			cout << "element not found\n";
		else
		{
			temp = root;
			for (int i = 0; i < pos_num - 1; i++)
				temp = temp->link;

			delnode = temp->link;
			temp->link = delnode->link;
		}
	}


	delete delnode;
}

template<class T>
void LLClass<T>::display()
{

	if (NULL == root)
	{
		cout << "List empty, terminating application\n";
		system("pause");
		exit(0);
	}

	int option = 0;
	cout << "enter direction: 1. forward, 2.reverse\n";
	cin >> option;
	cout << "The list is: ";
	switch (option)
	{
	case 1: {
		struct node *temp = root;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << endl;
		break;
	}
	case 2: {
		reverse();
		break;
	}
	default: cout << "Invalid direction\n";
	}
}

template<class T>
void LLClass<T>::reverse()
{
	struct node *one = NULL, *two = NULL, *three = NULL;

	one = root;
	last = one;
	two = root->link;
	three = two->link;

	while (NULL != three)
	{
		two->link = one;
		one = two;
		two = three;
		root = three;
		three = three->link;
	}
	root->link = one;
	last->link = NULL;
	cout << "After reverse, list is: ";
	struct node *temp = root;
	while (NULL != temp)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;

}

template<class T>
void LLClass<T>::read()
{
	int choice = 0, option = 0;
	do
	{
		cout << "enter option: 1. create , 2. insert, 3.delete, 4.display, 5.reverse\n";
		cin >> option;
		switch (option)
		{
		case 1: create();
			break;
		case 2: insert();
			break;
		case 3: deletion();
			break;
		case 4: display();
			break;
		case 5: reverse();
			break;
		default: cout << "invalid choice\n";
		}

		cout << "Enter -1 to close menu: ";
		cin >> choice;
	} while (-1 != choice);
}


void main()
{
	int choice = 0, option = 0;
	do
	{
		cout << "enter option: 1. int, 2.float\n";
		cin >> option;
		switch (option)
		{
		case 1: { LLClass<int> obj1;
			obj1.read();
			break; }
		case 2: { LLClass<float> obj2;
			obj2.read();
			break; }
		default: cout << "invalid choice\n";
		}

		cout << "Enter -1 to terminate program: ";
		cin >> choice;
	} while (-1 != choice);

	system("pause");
}