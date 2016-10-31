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
# Problem Statement	:Check whether two nodes are cpousins
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
	struct Node  *r;
	int data;
};


struct Node *newNode(int data)
		{
			struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
			node->data =data;
			node->r = node->l = NULL;
			return node;		
		}


void getLevelandParent(struct Node *root, struct Node *target, int l, int *level, struct Node **parent)
{
	if(!root)
		return ;
	if(root->l == target||root->r == target)
	{
		*level = l+1;
		*parent = root;
		
	}
getLevelandParent (root->l, target, l+1, level, parent);


getLevelandParent (root->r, target, l+1, level, parent);
	
	
	
	
}
bool areCousins(struct Node *root, struct Node *node1, struct Node *node2)	
{
	
	struct Node *parent1=NULL; struct Node *parent2=NULL;
	int level1=0, level2=0;
	
	if(!root)
		return false;
	getLevelandParent(root, node1,0, &level1, &parent1);
	
	getLevelandParent(root, node2, 0, &level2, &parent2);
	
	return (level1==level2 && parent1!=parent2);
	
	
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
		
		areCousins(root, root->l, root->r->r)?printf("true"):printf("false");
		areCousins(root, root->r->r, root->l->l )? printf("true"):printf("false");
		
}		