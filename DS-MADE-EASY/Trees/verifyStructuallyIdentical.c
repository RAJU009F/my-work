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

int areIdentical(struct BT *root1, struct BT *root2)
{
	if(!root1 && !root2)
			return 1;
	if(!root1 || !root2)
			return 0;
		
	return (root1->data == root2->data  && areIdentical(root1->l, root2->l) && areIdentical(root1->r, root2->r));	

}

int main()
	{
		struct BT *root = NULL;
		root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		
		struct BT *root1= newNode(1);
		root1->l = newNode(2);
		root1->r = newNode(3);
	if(areIdentical(root, root1))
			printf("Identical \n");
	else
			printf("not idenitcal \n");
		
	
	return 0;
	}