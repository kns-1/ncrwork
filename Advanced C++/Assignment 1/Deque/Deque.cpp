#include<iostream>
using namespace std;


template<class T>
class DequeClass
{
	struct node
	{
		T data;
		struct node *rlink, *llink;
	}*front, *rear;
	
public:
	DequeClass()
	{
		front = rear = NULL;
	}

	void operation(int flag);

	void insert_front();
	void insert_rear();
	void delete_front();
	void delete_rear();

	void display();
};

template<class T>
class StackClass:public DequeClass<T>
{
	
};

template<class T>
class QueueClass:public DequeClass<T>
{

};


template<class T>
void DequeClass<T>::display()
{

	if (NULL == front)
	{
		throw "Dequeue Empty\n";
	}

	else
	{
		cout << "The elements are: ";
		struct node *temp = front;
		while (NULL != temp)
		{
			cout << temp->data << " ";
			temp = temp->rlink;
		}
		cout << "\n";
	}
}


template<class T>
void DequeClass<T>::insert_front()
{
	struct node *my_node = NULL;
	cout << "Enter element: ";
	T element = 0;
	cin >> element;
	my_node = new node;
	my_node->data = element;
	my_node->llink = NULL;
	my_node->rlink = NULL;

	if (NULL == front)
	{
		front = my_node;
		rear = my_node;
	}
	else
	{
		my_node->rlink = front;
		front->llink = my_node;
		front = my_node;
	}
}

template<class T>
void DequeClass<T>::insert_rear()
{
	struct node *my_node = NULL;
	cout << "Enter element: ";
	T element = 0;
	cin >> element;
	my_node = new node;
	my_node->data = element;
	my_node->llink = NULL;
	my_node->rlink = NULL;

	if (NULL == rear)
	{
		front = my_node;
		rear = my_node;
	}
	else
	{
		my_node->llink = rear;
		rear->rlink = my_node;
		rear = my_node;
	}
}

template<class T>
void DequeClass<T>::delete_front()
{
	
	if (NULL == front)
	{
		throw "Dequeue Empty\n";
	}
	
	struct node *del_node = NULL;
	if (NULL == front->rlink && NULL == front->llink)
	{		
		del_node = front;
		rear = NULL;
		front = NULL;
	}
	else
	{
		del_node = front;
		front = front->rlink;
		front->llink = NULL;
	}
	cout << "Deleted element is: " << del_node->data << "\n";
	delete del_node;
}

template<class T>
void DequeClass<T>::delete_rear()
{
	if (NULL == rear)
	{
		throw "Dequeue Empty\n";
	}
	struct node *del_node = NULL;
	if (NULL == rear->rlink && NULL == rear->llink)
	{
		del_node = rear;
		rear = NULL;
		front = NULL;
	}
	else
	{
		del_node = rear;
		rear = rear->llink;
		rear->rlink = NULL;	
	}
	cout << "Deleted element is: " << del_node->data << endl;
	delete del_node;
}



template<class T>
void DequeClass<T>::operation(int flag)
{
	int choose_operation = 0, choice=0;
	do
	{
		cout << "Choose operation:\n 1.insert_front (stack)\n 2.insert_rear (queue)\n 3.delete_front (stack, queue)\n 4.delete_rear\n 5.Display Elements\n 6.EXIT\n";
		cin >> choose_operation;
	
		switch (choose_operation)
		{
		case 1: { 
			if (3 == flag)
			{
				cout << "\nInvalid operation for queue, choose 2.insert_rear option\n";
				break;
			}
			insert_front();
				break; }
		case 2: { if (2 == flag)
		{
			cout << "\nInvalid operation for stack, choose 1.insert_front option\n";
			break;
		}
				
					insert_rear();
				break; }
		case 3: { 
				try
				{
					delete_front();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break; }
		case 4: { if (2 == flag)
		{
			cout << "\nInvalid operation for stack, choose 3.delete_front option\n";
			break;
		}
				if (3 == flag)
				{
					cout << "\nInvalid operation for queue, choose 3.delete_front option\n";
					break;
				}
				try
				{
					delete_rear();
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break; }
		case 5: { try
		{
			display();
		}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
			break; }
		case 6: break;
		default: cout << "Invalid operation choice\n";
		}
		cout << "Enter -1 to exit operation menu\n";
		cin >> choice;	
	} while (-1 != choice);

}

void choose_deque_type()
{
	int data_type_option = 0, choice=0;

	do
	{
		cout << "Choose data type: 1.int, 2.float, 3.EXIT\n";
		cin >> data_type_option;

		switch (data_type_option)
		{
		case 1: { DequeClass<int> dq_obj1;
			dq_obj1.operation(1);
			break; }
		case 2: { DequeClass<float> dq_obj2;
			dq_obj2.operation(1);
			break; }
		case 3: break;
		default: cout << "Invalid data type option\n";
		}
		cout << "Enter -1 to EXIT data type menu\n";
		cin >> choice;
	} while (-1 != choice);
	
}

void choose_stack_type()
{
	int data_type_option = 0, choice = 0;

	do
	{
		cout << "Choose data type: 1.int, 2.float, 3.EXIT\n";
		cin >> data_type_option;

		switch (data_type_option)
		{
		case 1: { //DequeClass<int> *dq_obj3;
			StackClass<int> stk_obj1;
			//	dq_obj3 = &stk_obj1;
			stk_obj1.operation(2);
			break; }
		case 2: { //DequeClass<float> *dq_obj4;
			StackClass<float> stk_obj2;
			//dq_obj4 = &stk_obj2;
			stk_obj2.operation(2);
			break; }
		case 3: break;
		default: cout << "Invalid data type option\n";
		}
		cout << "Enter -1 to EXIT data type menu\n";
		cin >> choice;
	} while (-1 != choice);

}

void choose_queue_type()
{
	int data_type_option = 0, choice = 0;

	do
	{
		cout << "Choose data type: 1.int, 2.float, 3.EXIT\n";
		cin >> data_type_option;

		switch (data_type_option)
		{
		case 1: { //DequeClass<int> *dq_obj5;
			QueueClass<int> q_obj1;
			//_obj5 = &q_obj1;
			q_obj1.operation(3);
			break; }
		case 2: { // DequeClass<float> *dq_obj6;
			QueueClass<float> q_obj2;
			//dq_obj6 = &q_obj2;
			q_obj2.operation(3);
			break; }
		case 3: break;
		default: cout << "Invalid data type option\n";
		}
		cout << "Enter -1 to EXIT data type menu\n";
		cin >> choice;
	} while (-1 != choice);

}


void choose_data_structure()
{
	int data_structure_option = 0, choice = 0;
	do
	{
		cout << "Enter option: 1.Deque, 2.Stack, 3.Queue, 4.EXIT\n";
		cin >> data_structure_option;
		switch (data_structure_option)
		{
		case 1: { choose_deque_type(); break; }
		case 2: { choose_stack_type(); break; }
		case 3: { choose_queue_type(); break; }
		case 4: break;
		default: cout << "Invalid data structure option\n";
		}
		cout << "Enter -1 to terminate application\n";
		cin >> choice;
	} while (-1 != choice);

}


void main()
{
	choose_data_structure();
	system("pause");
}