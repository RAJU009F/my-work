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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: Max Sum Path
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
	struct Node *node =  (struct Node * ) malloc(sizeof(struct Node) );
	node->data = data;
	node->r= node->l = NULL;
	
	return node;
	
}
	
	
	
int max(int a, int b)
{
	return  a>b?a:b;
}
	
	
	
int maxSumPathUtil(struct Node *root, int *res)
		{
			if(!root)
				return 0;
			int l  =  maxSumPathUtil(root->l, res);
			int r =  maxSumPathUtil(root->r, res);
			
			int single_max =  max(max(l,r)+root->data, root->data);
			
			int top_max =  max(single_max, l+r+root->data);
			
			*res = max (*res, top_max);
			
			return single_max;
 			
		}
int maxSumPath(struct Node *root)
			{
				int res = 0;
				maxSumPathUtil(root, &res);
				return res;
			
			}
int main()
		{
		
			struct Node *root =  newNode(10);
			root->r =  newNode(10);
			root->r->r = newNode(-25);
			root->r->r->l = newNode(4);
			root->r->r->r = newNode(3);
			
			root->l =  newNode(2);
			root->l->l = newNode(20);
			root->l->r = newNode(2);
			
			printf("max path sum : %d", maxSumPath(root));
		}