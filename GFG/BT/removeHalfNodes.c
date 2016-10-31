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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: rmove the half nodes in tree
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
		struct Node *r;
		struct Node *l;
		int data;
		
	};
	
struct Node *newNode(int data)
		{
		
			struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
			if(!node)
				return NULL;
				
			node->data = data;
			node->l = NULL;
			node->r = NULL;
			
			return node;
		
		}

void inorder(struct Node *root)
			{
				if(!root)
					return ;
					
				printf("%d  ", root->data);
				inorder(root->l);
				inorder(root->r);
			
			
			
			}
		
struct Node *removeHalfNodes(struct Node *root)
			{
				if(!root)
					return NULL;

				
					root->l =  removeHalfNodes(root->l);
					root->r = removeHalfNodes(root->r);
					
					
				if(!root->l && !root->r)
					return root;
				else if(!root->l || !root->r)	
					return root->l?root->l:root->r;
				
				return root;
			
			}
			
			
	
int main()
		{
			struct Node *root = newNode(2);
			root->l= newNode(7);
			root->l->r = newNode(6);
			root->l->r->l =  newNode(1);
			root->l->r->r = newNode(11);
			
			root->r = newNode(5);
			root->r->r = newNode(9);
			root->r->r->l = newNode(4);
			
			inorder(root);
			removeHalfNodes(root);
			
			printf("\n");
			inorder(root);
			
		
		}