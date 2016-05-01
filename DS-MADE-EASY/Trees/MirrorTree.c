#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: Mrirror of tree
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

struct BT  *Mirror(struct BT *root)
{
	if(root)
	{
		struct BT *temp;
		Mirror(root->l);
		Mirror(root->r);
		temp = root->l;
		root->l = root->r;
		root->r = temp;
		
		
		
	}
	
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

bool areMirrors(struct BT *root1, struct BT *root2)
{
	if(!root1 && !root2)
			return true;
		
	if(!root1 || !root2)
			return false;
	if(root1->data != root2->data)
			return false;
	else
		return ( areMirrors(root1->l, root2->r) && areMirrors(root1->r, root2->l));	
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
		printf("tree before:\n");
		printPreOrder(root);
		struct BT *root1 = Mirror(root);
		printf("Tree After Mirror:\n");
		printPreOrder(root1);
		
		if(areMirrors(root, root1))
			printf("\n\nMirrors\n");
		else
			printf("\nNot mirros\n");

		
	return 0;
	}