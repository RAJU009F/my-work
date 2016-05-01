#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: LCA in BT 
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

struct BT *LCA(struct BT *root, struct BT *a, struct BT *b)
{
	if(!root)
			return NULL;
	if(root->data == a->data || root->data == b->data)
			return root;
	struct BT *left =  LCA(root->l, a, b );
	struct BT *right =  LCA(root->r, a,b);
	if(left && right)
			return root;
	else
		return left?left:right;
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
	
		struct BT *lca =  LCA(root, newNode(6), newNode(7));
		if(lca)
			printf("LCA [%d]\n", lca->data);
	return 0;
	}