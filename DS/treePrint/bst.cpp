#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class Tree
{
public:
	struct node
	{
		T data;
		struct node *lc=NULL, *rc=NULL;
	}*root;
	Tree()
	{
		root = NULL;
	}
	void insert();
	void deletion();
	void search();
	void display();
	void read();
	void inorder(struct node*);
	void preorder(struct node*);
	void postorder(struct node*);
};

template<class T>
void Tree<T>::search()
{
	if (root == NULL)
	{
		cout << "Tree empty" << endl;
		return;
	}
	else
	{
		T ele;
		int flag = 0;
		cout << "enter element: ";
		cin >> ele;
		struct node *temp = root;
		while (temp != NULL)
		{
			if (ele == temp->data)
			{
				flag = 1;
				cout << "Element found " << endl;
				break;
			}
			else if (ele < temp->data)
				temp = temp->lc;
			else
				temp = temp->rc;	
		}
		if (flag == 0)
			cout << "element not found" << endl;
	}
}

template <class T>
void Tree<T>::inorder(struct node *temp)
{
	if (temp != NULL)
	{
		inorder(temp->lc);
		cout << temp->data << " ";
		inorder(temp->rc);
	}
}
template <class T>
void Tree<T>::preorder(struct node *temp)
{
	if (temp != NULL)
	{
		cout << temp->data << " ";
		preorder(temp->lc);
		preorder(temp->rc);
	}
}
template <class T>
void Tree<T>::postorder(struct node *temp)
{
	if (temp != NULL)
	{
		postorder(temp->lc);
		postorder(temp->rc);
		cout << temp->data << " ";
	}
}

template<class T>
void Tree<T>::deletion()
{
	if (root == NULL)
	{
		cout << "Tree empty" << endl;
		return;
	}
	else
	{
		T ele;
		int flag = 0;
		cout << "enter element: ";
		cin >> ele;
		struct node *temp = root, *parent=NULL;
		while(temp!=NULL)
		{
			
			if (ele < temp->data)
			{
				parent = temp;
				temp = temp->lc;
			}
			else if(ele > temp->data)
			{
				parent = temp;
				temp = temp->rc;
			}
			if (ele == temp->data)
			{
				flag = 1;
				if (temp->lc == NULL && temp->rc == NULL) //leaf node
				{
					if (parent->lc == temp)
						parent->lc = NULL;
					else
						parent->rc = NULL;
					delete temp;
				}

				else if (temp->lc == NULL && temp->rc != NULL)  //one right child
				{
					parent->rc = temp->rc;
					delete temp;
				}
				else if (temp->lc != NULL && temp->rc == NULL) //one left child
				{
					parent->lc = temp->lc;
					delete temp;
				}

				else  //two children
				{
					struct node *max = temp->lc;
					struct node *max_parent = temp;
					int max_flag = 0;
					while (max->rc != NULL) //finding the largest element in the left subtree (Traverse right)
					{
						max_flag = 1;
						max_parent = max;
						max = max->rc;
					}
					temp->data = max->data;
					if (max_flag == 0)
						temp->lc = max->lc;
					if(max->lc != NULL && max_flag==1)
						max_parent->rc = max->lc;
					
					delete max;
				}


				break;
			}
		}
		if (flag == 0)
			cout << "element not found" << endl;

	}
	
}


template <class T>
void Tree<T>::read()
{
	int n,ch;
	do
	{
		cout << "enter 1.insert, 2.display, 3.search, 4.delete\n";
		cin >> n;
		switch (n)
		{
		case 1:insert(); break;
		case 2:display(); break;
		case 3:search(); break;
		case 4:deletion(); break;
		}
		cout << "enter -1 to exit menu: ";
		cin >> ch;
	} while (ch != -1);
}


template<class T>
void Tree<T>::insert()
{
	T ele = NULL;
	int ch;
	struct node *nn = NULL, *temp = NULL, *parent = NULL;
	do {
		cout << "enter element: ";
		cin >> ele;

		nn = new node;
		nn->data = ele;
		nn->lc = NULL;
		nn->rc = NULL;
		if (root == NULL)
			root = nn;
		else {
			temp = root;
			while (temp != NULL)
			{
				parent = temp;
				if (ele < temp->data)
					temp = temp->lc;
				else
					temp = temp->rc;
			}
			if (ele < parent->data)
				parent->lc = nn;
			else
				parent->rc = nn;
		}
			cout << "enter -1 to stop insertion: ";
			cin >> ch;
		} while (ch != -1);
	
}

template<class T>
void Tree<T>::display()
{
	if (root == NULL)
	{
		cout << "Tree empty" << endl;
		return;
	}
	int n;
	cout << "enter 1.inorder, 2.preorder, 3.postorder\n";
	cin >> n;
	
	switch (n)
	{
	case 1: inorder(root); break;
	case 2: preorder(root); break;
	case 3: postorder(root); break;
	}
	cout << endl;
}

void main()
{
	int ch;
	
	do
	{
		cout << "enter 1.int, 2.float, 3.char\n";
		cin >> ch;
		switch(ch)
		{
		case 1: {Tree<int> ob1;
			ob1.read();
			break; }
		case 2: { Tree<float> ob2;
			ob2.read();
			break; }
		case 3: { Tree<char> ob3;
			ob3.read();
			break; }
		} 
		cout << "enter -1 to stop the program: ";
		cin >> ch;
	} while (ch!=-1);

	_getch();
}