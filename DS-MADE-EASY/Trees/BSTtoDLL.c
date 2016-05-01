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

struct BST
{
	struct BST *l;
	int data;
	struct BST *r;
};

// create a BST Node
struct BST *newNode(int data)
{
		struct BST *node = (struct BST *)malloc(sizeof(struct BST));
		if(!node)
			return node;
		
		node ->data = data;
		node ->l = node->r = NULL;
		
	return node;	
}

void printInorder(struct BST *root)
{
	if(!root)
			return;
		
		printInorder(root->l);
		printf("[%d]\t",root->data);
		printInorder(root->r);
	
	
	
}

struct BST *insertBST(struct BST *root,  int data)
{
	if(!root)
	{
		root =  newNode(data);
		root->l = root->r= NULL;
		
		return root;
	}
	
	if(root->data> data)
		root->l = insertBST(root->l, data);
	else
		root ->r = insertBST(root->r, data);
	
	return root;
}


void printDLL(struct BST *head)
{
	printf("\n DLL ::\n\n");
	while(head)
	{
		printf("[%d]-> ",head->data);
		head = head ->r;
	}
	printf("\n");
	
}

void BSTtoDLL(struct BST *root, struct BST **head, struct BST **prev)
{
	if(!root)
		return;
	//static struct BST *prev =NULL;
	BSTtoDLL(root->l, head, prev);
	if(!*prev)
	{
		*head = root;
	}
	else
	{
		(*prev)->r = root;
		root->l = (*prev);
		
	}
	(*prev)= root;
	BSTtoDLL(root->r, head, prev);
	
	
}

struct BST *BSTtoDLL1(struct BST *root)
{
	if(!root)
			return NULL;
		
	if(root->l)
	{
		struct BST *left = BSTtoDLL1(root->l);
		for(;left->r; left = left->r);
		left ->r =root;
		root->l = left;
	}
	
	if(root->r)
	{
		
		struct BST *right = BSTtoDLL1(root->r);
		for(; right->l; right = right->l);
		right->l = root;
		root->r = right;
			
		
		
	}
	
return root;	
	
	
}
int main()
	{
		struct BST *root = insertBST(NULL,5);
		insertBST(root,2);
		insertBST(root,3);
		insertBST(root,6);
		insertBST(root,7);
		insertBST(root,1);
		insertBST(root,4);
		
		printInorder(root);
		struct BST *head = NULL;
		struct BST *prev = NULL;
		//BSTtoDLL(root, &head, &prev);
		//printDLL(head);
		//printInorder(root);
		
		head =  BSTtoDLL1(root);
		while(head->l)
			head = head->l;
		printDLL(head);
	return 0;
	}