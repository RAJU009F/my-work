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
# Problem Statement	: print all the nodes without siblings
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
		
void printNodesWithtwoSiblings(struct Node *root)
			{
				if(!root)
					return;
				printNodesWithtwoSiblings(root->l);
				printNodesWithtwoSiblings(root->r);
				
				if(!root->l && root->r)

					printf("%d", root->r->data);
				if(!root->r && root->l)
					printf("%d", root->l->data);
			
			
			}
int main()
	{
	
	struct Node *root = newNode(1);
		root->l = newNode(2);
		//root->l->l = newNode(4);
		root->l->r = newNode(5);
		
		root->r = newNode(3);
		root->r->l = newNode(6);
		root->r->l->l = newNode(8);
		//root->r->r = newNode(7);
	
	printNodesWithtwoSiblings(root);
	}
	
			
		