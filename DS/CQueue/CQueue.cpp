#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 5

int f = -1, l = -1;
template <class T>
class Queue
{
	T q[MAX];
public:

	void insert(T ele);
	void read();
	int size();
	T remove();
	void display();
};

template<class T>
void Queue<T>::display()
{
	if (f == -1)
	{
		cout << "queue empty" << endl;
		return;
	}
	cout << "The elements are: ";
	if (l < f)
	{
		for(int i=l;i<=f;i++)
			cout << q[i] << " ";
	}
	else
	{
		for (int i = l; i <= MAX - 1; i++)
			cout << q[i] << " ";
		for (int i = 0; i <= f; i++)
			cout << q[i] << " ";
	}
	cout << endl;
}


template<class T>
int Queue<T>::size()
{
	if (f == -1 || l == f + 1)
	{
		cout << "queue empty" << endl;
		return NULL;
	}
	return (f - l + 1);
}

template <class T>
void Queue<T>::insert(T ele)
{
	if ((f - l + 1) == MAX)
	{
		cout << "queue full" << endl;
		return;
	}
	
	if (f == -1|| l==f+1)
	{
		f = l = 0;
		q[f] = ele;
	}	
	else
		q[++f] = ele;
}

template <class T>
T Queue<T>::remove()
{
	if (f == -1)
	{
		cout << "queue empty" << endl;
		return NULL;
	}
	if (l == f + 1)
	{
		l = 0; f = 0;
	}
	return q[l++];
}

template<class T>
void Queue<T>::read()
{
	int n, ch;
	while (1)
	{
		cout << "choose option: 1.insert, 2.remove, 3.size, 4.display, 5.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:	T ele;
			cout << "enter element: ";
			cin >> ele;
			insert(ele);
			break;
		case 2: cout << "Removed element: " << remove() << endl;
			break;
		case 3: cout << "Number of elements: " << size() << endl;
			break;
		case 4: display();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
		if (ch == -1)
			break;
	}

}

void main()
{
	int n, ch;

	while (1)
	{
		cout << "enter choice: 1.int, 2.float, 3.char, 4.exit\n";
		cin >> n;
		switch (n)
		{
		case 1: Queue<int> s1;
			s1.read();
			break;
		case 2: Queue<float> s2;
			s2.read();
			break;
		case 3: Queue<char> s3;
			s3.read();
			break;
		}
		cout << "enter -1 to stop: ";
		cin >> ch;
		if (ch == -1)
			break;
	}
	_getch();
}