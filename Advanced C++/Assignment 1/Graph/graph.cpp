#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class GraphClass
{
	int **adj_mat, *visited;
	int vertices;
public:
	GraphClass()
	{
		/*adj_mat = NULL;
		visited = NULL;
		vertices = 0;*/
		cout << "Inside default constructor\n";
	}

	/*GraphClass(const GraphClass &ob)
	{
		vertices = ob.vertices;
		adj_mat = new int*[vertices];
		for (int i = 1; i <= vertices; i++)
		{
			adj_mat[i] = new int[vertices];
			for (int j = 1; j <= vertices; j++)
				adj_mat[i][j] = ob.adj_mat[i][j];
		}

		visited = new int[vertices];
		for (int i = 1; i <= vertices; i++)
			visited[i] = ob.visited[i];
		cout << "Inside copy constructor\n";
	}*/
	void enter_adj_matrix();
	void bfs();
	void dfs();

	/*GraphClass operator =(GraphClass ob)
	{
		if (ob.adj_mat == NULL)
		{
			delete[] adj_mat;
		}
		if (ob.visited == NULL)
		{
			delete[] visited;
		}
		vertices = ob.vertices;
		adj_mat = new int*[vertices];
		for (int i = 1; i <= vertices; i++)
		{
			adj_mat[i] = new int[vertices];
			for (int j = 1; j <= vertices; j++)
				adj_mat[i][j] = ob.adj_mat[i][j];
		}
		visited = new int[vertices];
		for (int i = 1; i <= vertices; i++)
			visited[i] = ob.visited[i];

		return (*this);
	}*/


	~GraphClass()
	{
		cout << "Inside destructor\n";
		for (int i = 1; i <= vertices; i++)
		{
			cout << "Inside for loop\n";
			delete [] adj_mat[i];
		}
		cout << "after for loop\n";
		delete [] adj_mat;
		cout << "deleting visited\n";
		delete [] visited;
		/*adj_mat = nullptr;
		visited = nullptr;*/
		vertices = 0;
		cout << "Exiting Destructor\n";
	}

};

void GraphClass::enter_adj_matrix()
{
	
	cout << "Enter number of vertices: ";
	cin >> vertices;
	adj_mat = new int*[vertices];

	cout << "Enter matrix elements:\n";
	for (int i = 1; i <= vertices; i++)
	{
		adj_mat[i] = new int[vertices];

		for (int j = 1; j <= vertices; j++)
			cin >> adj_mat[i][j];	
	}

	visited = new int[vertices];
	for (int i = 1; i <= vertices; i++)
			visited[i] = 0;		



	cout << "The adjaceney matrix is:\n";
	for (int i = 1; i <= vertices; i++)
	{
		for (int j = 1; j <= vertices; j++)
			cout << adj_mat[i][j]<<" ";
		cout << "\n";
	}

	cout << "The visited matrix is:\n";
	for (int i = 1; i <= vertices; i++)
			cout << visited[i] << " ";
	cout << "\n";

}


void GraphClass::dfs()
{
	stack<int> sobj;

	cout << "DFS\n";
	int start_node = 0;
	cout << "Enter starting node: ";
	cin >> start_node;
	sobj.push(start_node);
	visited[start_node] = 1;

	while (!sobj.empty())
	{
		int current_node = sobj.top();
		cout << current_node << " ";
		sobj.pop();

		for (int j = 1; j <= vertices; j++)
		{
			if (1 == adj_mat[current_node][j] && !visited[j])
			{
				sobj.push(j);
				visited[j] = 1;
			}
		}
	}
	cout << "\n";
	for (int i = 1; i <= vertices; i++)
		visited[i] = 0;
}



void GraphClass::bfs()
{
	queue<int> qobj;

	cout << "BFS\n";
	int start_node = 0;
	cout << "Enter starting node: ";
	cin >> start_node;
	qobj.push(start_node);
	visited[start_node] = 1;

while(!qobj.empty())
{
	int current_node = qobj.front();
	cout<<current_node<< " ";
	qobj.pop();

		for (int j = 1; j <= vertices; j++)
		{
			if (1 == adj_mat[current_node][j] && !visited[j])
				{
					qobj.push(j);
					visited[j] = 1;
			    }
		}
	}
	cout << "\n";
	for (int i = 1; i <= vertices; i++)
		visited[i] = 0;
}
void main()
{
	GraphClass obj;
	obj.enter_adj_matrix();
	obj.bfs();
	obj.dfs();

	obj.~GraphClass();
	system("pause");
}