// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: Given BT is like Red black tree height  balanced or not
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

struct Node 
	{
		struct Node *l;
		struct Node *r;
		int data;	
	};
	
	
struct Node *newNode(int data)
		{
			struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
			node->data =data;
			node->r = node->l = NULL;
			return node;		
		}

int getHeight(struct Node *root)
{
	if(!root)
			return 0;
		
	int left =  getHeight(root->l);
	int right =  getHeight(root->r);
	
	return (left>right?left:right)+1;
	
	
	
}

void printNodesKDistancefromLeafUtil(struct Node *root,  int path[],  int pathLen,  bool visited[], int k)
{
	if(!root)
			return;
		
	path[pathLen] = root->data;
	visited[pathLen] = false;
	pathLen++;
	
	if(!root->l && !root->r && pathLen-k-1>=0 && !visited[pathLen-k-1])
	{
		printf("%d ", path[pathLen-k-1]);
		visited[pathLen-k-1] =true;
		return;
	}
	
	printNodesKDistancefromLeafUtil(root->l, path, pathLen,  visited, k);
	printNodesKDistancefromLeafUtil(root->r, path, pathLen, visited, k);
	
	
}

void printNodesKDistancefromLeaf(struct Node *root)
{

	if(!root)
		return;
		
		int height =  getHeight(root);
		int path[height];
		bool visited[height] ;
		memset(visited, false, sizeof(visited));
		
		printNodesKDistancefromLeafUtil(root, path, 0, visited,  1);

}		
		
int main()
	{
		struct Node *root = newNode(1);
		root->l = newNode(2);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		
		root->r = newNode(3);
		root->r->l = newNode(6);
		root->r->l->r = newNode(8);
		root->r->r = newNode(7);
		printNodesKDistancefromLeaf(root);
	
	}
