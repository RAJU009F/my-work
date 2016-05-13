#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
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

struct Graph
{
	int V;
	int E;
	int **arr;
};

struct SLL 
{
	int data;
	struct SLL *next;
	
};
struct Queue
{
	struct SLL *fr;
	struct SLL *rr;
	
};

struct Graph *initializeG(struct Graph **G)
{
	
	struct Graph *g =  (struct Graph *) malloc(sizeof(struct Graph));
	if(!g)
		return;
	g->V = 6;
	g->E = 6;

	g->arr =(int **) malloc(sizeof(g->V*g->V));

	int u, v;
	for(u=0; u<g->V; u++)
	{
		
		for(v=0;v<g->V;v++)
			g->arr[u][v] = 0;
	}
	
	*G = g;
	return g;
}


void DFSUtil(struct Graph *g, int u, int visited[])
{
	visited[u] = 1;
	int v;
	for(v =0; v<g->V; v++)
			if(g->arr[u][v] && !visited[v])
				DFSUtil(g, v, visited);
	
	
}
void DFS(struct Graph *g)
{
	
	int Visited[g->V];
	int i;
	for(i=0; i<g->V; i++)
		DFSUtil(g, i, Visited);
	
	
	
	
	
}

void BFSUtil(struct Graph *g, int u, int visited[])
{
	int v;
	struct Queue *q = NULL;
	//NQ(q,u);
	//while(!isEmpty(q))
	{
		//u = DQ(q);
		visited[u] = 1;
		for(v=0; v<g->V; v++)
		{
			if(!visited[v] && g->arr[u][v])
				//NQ(q,v);
			
		}
		
		
		
	}
	
	
	
}
void BFS(struct Graph *g)
{
	
	int visited[g->V];
	int i;
	for(i=0; i<g->V; i++)
		BFSUtil(g. i,visited);
	
}


int main()
	{
		//printf("csnbksdn");
		struct Graph *g =  NULL;
	initializeG(&g);
	printf("%d",g->V);
	int u, v;
	for(u=0; u<g->V; u++)
	{
		for(v=0;v<g->V;v++)
			printf("%d %d : %d\n",g->arr[u][v]);
	}
	
	return 0;
	}
