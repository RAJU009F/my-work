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
	list<int> *adj;
	
	void APUtil(int u, bool visited[], int parent[],  int low[], int disc[], bool ap[]);
	
	public:
	Graph(int V);
	void addEdge(int , int );
	void AP();




};

void Graph:: APUtil(int u, bool visited[], int parent[],  int low[], int disc[], bool ap[])
{
	
	static int time = 0;
	int children=0;
	visited[u] = true;
	low[u] = disc[u] =  ++time;
	
	list<int>::iterator i;
	for(i=adj[u].begin(); i!=adj[u].end(); i++)
	{
		int v = *i;
		if(!visited[v])
		{
			
			parent[v] = u;
			children++;
			APUtil(v, visited, parent, low, disc, ap);
			low[u] = min(low[u], low[v]);
			
			if(parent[u] == -1 && children>1)
				ap[u] = true;
			if(parent[u] !=-1 && low[v]>=disc[u])
				ap[u] = true;
			
			
		}else if(v!=parent[u])
		{
			low[u] = min(low[u], disc[v]);
			
		}
		
	}
	
	
}

Graph::Graph(int V)
{
	this->V = V;
	adj =  new list<int>[V];
	
}

void Graph ::addEdge(int u, int v)

{
	
	adj[u].push_back(v);
	adj[v].push_back(u);
	
	
}

void Graph::AP()
{
	int *parent  = new int[V];
	int *low =  new int[V];
	int *disc = new int[V];
	bool *ap = new bool[V];
	bool *visited = new bool[V];
	int i;
	for(i=0; i<V; i++)
	{
		parent[i] = -1;
		ap[i] = false;
		visited[i] = false;
		
		
	}
	
	for(i=0; i<V; i++)
	{
		if(!visited[i])
			APUtil(i, visited, parent, low, disc, ap);
		
	}
	
	for(i=0; i<V;i++)
		if(ap[i])
			cout<<i<<" ";
}

int main()
{
	
	 Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();
	
	
	
	
}