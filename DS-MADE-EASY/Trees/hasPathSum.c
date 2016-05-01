#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: check if path with sum exists
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

bool hasPathSum(struct BT *root, int sum)
{
	
	if(!root)
			return sum ==0 ;
		
		int remSum = sum - root->data;
		
	return hasPathSum(root->l, remSum)|| hasPathSum(root->r, remSum);	
	
	
}

int main()
	{
			struct BT *root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		root->l->l = newNode(4);
		root->l->r =  newNode(5);
		root->r->l = newNode(6);
		root->r->r =  newNode(7);
		if(hasPathSum(root, 7))
			printf("path with sum 7 is present\n");
		else
			printf("no path found\n");
		
	}
	