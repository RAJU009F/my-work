#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	:  Height of BT
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

int height(struct BT *root)
{
	if(!root)
		return 0;
	
	else
	{
		int l = height(root->l);
		int r = height(root->r);
		
		return (l>r?l:r) +1;
		
	}
	
	
}


int main()
	{
		struct BT *root = NULL;
		root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		root->r->l = newNode(6);
		root->r->r = newNode(7);
		root->l->r->l = newNode(33);
		root->l->r->r = newNode(46);
		root->r->r->l = newNode(63);
		root->r->r->r = newNode(65);
		printf("height of Tree:%d\n",height(root));
	
	
	return 0;
	}