// import java.io.*;
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
# Problem Statement	: ROOT TO LEAF PATH WITH GIVEN SUM EXISTS
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
		int data;
		struct Node *l;
		struct Node *r;
	};
	
struct Node *newNode(int data)
{
	struct Node *node = (struct Node *) (malloc(sizeof(struct Node)));
	node->data = data;
	node->l = NULL;
	node->r  = NULL;
	return node;
	
}	
	
void preOrder(struct Node *node)
{
	if(!node)
		return;
	
	printf("%d ", node->data);
	preOrder(node->l);
	preOrder(node->r);
	
	
}	
	
struct Node *makeTree(int pre[], char preLN[],  int *i,  int n)
{
	int index  =  (*i);
	if(index==n)
		return NULL;
	struct Node *node = newNode(pre[index]);
	(*i)++;
	if(preLN[index] == 'N')
	{	
	
	node->l = makeTree(pre, preLN, i, n);
	node->r = makeTree(pre, preLN, i, n);
	}
	return node;
	
}	
	
int main()
		{
		int pre[] = {10, 30, 20, 5, 15};
        char preLN[] = {'N', 'N', 'L', 'L', 'L'};
		int i = 0;
		struct Node *root = makeTree(pre, preLN, &i, sizeof(pre)/sizeof(pre[0]));
		preOrder(root);
		
		
		}
