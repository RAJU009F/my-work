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
# Problem Statement	: find the distance between two nodes
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
struct Node *findLCA(struct Node *root, struct  Node *node1, struct Node *node2)
{
	if(!root)
		return NULL;
	if(root==node1 || root== node2)
		return root;
	struct Node *left =  findLCA(root->l, node1, node2);
	struct Node *right = findLCA(root->r, node1, node2);
	
	if (left &&right)
		return root;
	return left?left:right;
	
}
		
bool finddist(struct Node *lca, struct Node *node, int *i)
{
	if(!lca)
		return false;
	if(lca == node)
			return true;
		
	if(finddist(lca->l, node , i))
	{
		*i = *i +1;
		return true;
		
	}else if(finddist(lca->r, node, i))
	{
		*i = *i +1;
		return true;
	}else
		return false;
	
	
}		
		
int distance(struct Node *root,  struct Node *node1, struct Node *node2)	
{
	if(!root)
		return -1;
	// step-1 find the LCA
	struct Node *lca =  findLCA(root, node1, node2);
	if(!lca)
		return -1;
	
	int i=0;
	int j=0;
	
	finddist(lca , node1, &i);
	finddist(lca, node2, &j);
	//printf("%d", i+j);
return j+i;	
	
	
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
	
	printf("%d", distance(root, root->r->l->r, root->r->r));
	}
	
	
	
	