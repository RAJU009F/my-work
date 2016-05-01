#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: find nextsibling and ptraverse tree and print nextsibling data
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
	struct BT *ns;
};

// create a BT Node

struct BT *newNode(int data)
{
		struct BT *node = (struct BT *)malloc(sizeof(struct BT));
		if(!node)
			return node;
		
		node ->data = data;
		node ->l = node->r = node->ns= NULL;
		
	return node;	
}

void findNextSibling(struct BT *root)
{
	
	if(!root)
			return;
		if(root->l)
			root->l->ns = root->r;
		if(root->r)
			root->r ->ns =  root->ns?root->ns->l:NULL;
		findNextSibling(root->l);
		findNextSibling(root->r);
	
	
}

void printNexSibling(struct BT *root)
{
	if(root)
	{
		if(root->ns)
			printf("[%d]\t",root->ns->data);
		else
			printf("[%d]\t",root->data);
		printNexSibling(root->l);
		printNexSibling(root->r);
		
		
		
	}
	
	
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
		
		findNextSibling(root);
		printNexSibling(root);
	return 0;
	}