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

bool isBalancedUtil(struct Node *root, int *mxh, int *mnh)
{
	if(!root)
	{
		*mnh = *mxh = 0;
		return true;
	}
	int lmnh , lmxh;
	int  rmnh, rmxh;
	
	return isBalancedUtil(root->l, &lmnh, &lmxh)==false;
	return isBalancedUtil(root->r, &rmnh, &rmxh)==false;
	
	*mnh =  (lmnh>rmnh?lmnh:rmnh)+1;
	*mxh =  (lmxh>rmxh?lmxh:rmxh)+1;
	
	return (*mxh <= (2*(*mnh)));
	
}
		
bool isBalanced(struct Node *root)
	{
		if(!root)
			return;
		
		int mxh = 0;
		int mnh = 0;
	return isBalancedUtil(root, &mxh, &mnh);
	
	}
		
		
int main()
		{
			struct Node *root =  newNode(10);
			root->l = newNode(5);
			root->r = newNode(100);
			root->r->l =  newNode(50);
			root->r->r =  newNode(150);
			root->r->r->r  =  newNode(40);
			
			isBalanced(root)?printf("Balanced"):printf("Not balanced");	
		
		}


