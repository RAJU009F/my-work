#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: Diameter of tree
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

int diameterBT(struct BT *root, int *h)
{
	int lh=0; int rh =0 ;
	int ld=0;
	int rd=0;
	if(!root)
	{
		*h = 0;
		return 0;
	}
	
	ld =  diameterBT(root->l, &lh);
	rd =  diameterBT(root->r, &rh);
	
	*h =  lh > rh ? lh : rh +1;
	
	return lh+rh+1>(ld>rd?ld:rd)? lh+rh+1:(ld>rd?ld:rd );
	
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
		int height = 0 ;
	printf("\n Diameter of tree :[%d] ",diameterBT(root, &height));
	
	
	return 0;
	}