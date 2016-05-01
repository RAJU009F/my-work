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

bool printAllAncestors(struct BT *root, struct BT *node)
{
		if(!root)
			return 0;
		
			if(root->data == node->data|| printAllAncestors(root->l, node)|| printAllAncestors(root->r, node))
			{
				printf("[%d]\t",root->data);
				return 1;
			}
			
			
			
			
		
		//else
			return 0;
}

bool printAllAncestors1(struct BT *root , struct BT *node)
{
	if(!root)
		return 0;
	if(root->data == node->data)
			return 1;
	if(printAllAncestors1(root->l, node) || printAllAncestors1(root->r, node))
	{
		printf("[%d]\t",root->data);
		return 1;
	}
	
	return 0;
	
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
	printAllAncestors1(root,newNode(7));
	
	
	return 0;
	}