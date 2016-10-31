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
# Problem Statement	: Construct FULL  Binary tree from Pre order and post order treversal
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
	node->l = NULL;
	node->r  = NULL;
	node->data = data;
	
	return node;
	
}

struct Node *makeFUllBTUtil(int pre[],  int post[], int *preIndex, int l, int  h, int size  )
{
	
	if(*preIndex >= size || l>h)
		return NULL;
	int i;
	
	struct Node *node =  newNode(pre[*preIndex]);
	
	if(l==h)
		return node;
		++(*preIndex);
	for(i=l; i<=h; i++)
			if(pre[*preIndex] == post[i])
				break;
	
	if(l<=h)
	{
		node->l =  makeFUllBTUtil(pre, post, preIndex, l, h, size);
		node->r =  makeFUllBTUtil(pre, post, preIndex, i+1, h, size);
		
	}
	
	return node;
}
struct Node *makeFUllBT(int pre[],  int post[], int size)
{
	int preIndex= 0;
	return makeFUllBTUtil(pre, post, &preIndex, 0, size-1, size);
	
}

void preOrder(struct Node *root)
{
	if(!root)
		return;
	printf("%d ", root->data);
	preOrder(root->l);
	preOrder(root->r);
	
	
}
int main()
{
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	
	struct Node *root= makeFUllBT(pre, post, sizeof(pre)/sizeof(pre[0]));

		preOrder(root);
		
	
}