#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct BT
{
	struct BT *l;
	int data;
	struct BT *r;
};

// create a BT Node

struct BT *newNode(int data)
{
		struct BT *node = (struct BT *)malloc(sizeof(struct BT));
		if(!node)
			return node;
		
		node ->data = data;
		node ->l = node->r = NULL;
		
	return node;	
}
int find(int in[], int i, int n, int data)
{
	
	while(i<=n)
	{
		if(in[i]==data)
			return i;
		i++;
	}
	return i;
	
}

struct BT *constructBT(int in[], int start, int end, int pre[], int *prein)
{
	if(start>end)
			return NULL;
	struct BT *root =  newNode(pre[*prein]);
	(*prein)++;
	
	if(start == end)
			return root;
	int inIndex =  find(in, start, end, root->data);
	root->l = constructBT(in, start, inIndex-1, pre, prein);
	root->r  =  constructBT(in,inIndex+1, end,pre, prein);
	
	return root;
}
void printPreOrder(struct BT *root)
{
	
	if(root)
	{
		printf("[%d]\t",root->data);
		printPreOrder(root->l);
		printPreOrder(root->r);
	}
	
	
}

int main()
	{
		
		int pre[] = {1,2,4,5,3,6,7};
		int in[] = {4,2, 5,1, 6,3,7};
		int prein = 0;
		struct BT *root = constructBT(in, 0, 6, pre, &prein);
		
		printPreOrder(root);
	
	
	return 0;
	}