// import java.lang.*;
// import java.util.*;
// import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	:  create Tree from Parent index array
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
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->l = node->r = NULL;
	
	return node;
	
}
	
void createBTUtil(int parent[], struct Node *created[],  int i, struct Node **root)
{
	if(created[i] != NULL)
			return;
	created[i] = newNode(i);
	// printf("%d", created[i]->data);
	if(parent[i] == -1)
	{*root= created[i];
		return;
	}
	if(created[parent[i]] == NULL)
			createBTUtil(parent, created, parent[i], root);
		
	if(!created[parent[i]]->l)
		created[parent[i]] -> l= created[i];
	else
			created[parent[i]]->r = created[i];
	
}

void createBT(int parent[],  struct Node **root, int n)
		{
			
			struct Node * created[n];
			int i=0;
			for(i=0 ;i<n ;i++)
					created[i] = NULL;
			for( i=0; i<n; i++)
					createBTUtil(parent, created, i, root);
			// for(i=0;i<n; i++)
					// printf("%d ",created[i]->data);
		
		}
void inorder(struct Node *root)
{
	
	if(!root)
			return;
		
		inorder(root->l);
		printf("%d", root->data);
		inorder(root->r);
	
	
}		
int main()
		
{
	int parent[] = {-1,0,0,1,1,3,5};
	struct Node *root = NULL;
	
	createBT(parent, &root, sizeof(parent)/sizeof(parent[0]));
	inorder(root);
}
