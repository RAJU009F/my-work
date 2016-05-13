#include<iostream>
#include<list>
using namespace std;
/*

# Author			: @RAJ009F
# Topic or Type 	: Graph
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/


class Graph
{
	int V;
	list<int > *adj;
	bool hasCycleUtil(int u,  int parent[], bool visited[]);
	
	public:
	Graph(int V);
	bool hasCycle();
	void addEdge(int u,  int v);
	
	
	
};

bool Graph::hasCycleUtil(int u,  int parent[], bool visited[])
{
	visited[u] = true;
	list<int>:: iterator i;
	for(i = adj[u].begin(); i!=adj[u].end(); i++)
	{
		int v = *i;
		
		if(!visited[u])
		{
			parent[v] = u;
			if(hasCycleUtil(v, parent, visited))
				return true;
			
	}else if(v != parent[u])
			return true;
		
		
		
		
		
	}
	
	return false;
	
	
	
}
Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int >[V];
	
	
}
void Graph::addEdge(int u, int v)
{
	
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::hasCycle()
{
	int *parent =  new int[V];
	bool *visited = new bool[V];
	int i;
	for(i=0; i<V; i++)
	{
		parent[i] = -1;
		visited[i] = false;
	}
	for(i=0; i<V; i++)
	{
		if(hasCycleUtil(i, parent, visited))
			return true;
		
	}
	
	return false;
}

int main()
{
	 Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.hasCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
	
	return 0;
}
