#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: BS Trees
# Problem Statement	: a]. insert node into BST b]. delete node c]. verify the tree is BST or not 
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

void printInorder(struct BST *root)
{
	if(!root)
			return;
		
		printInorder(root->l);
		printf("[%d]\t",root->data);
		printInorder(root->r);
	
	
	
}
struct BST *inorderPre(struct BST *root)
{
	if(!root)
		return NULL;
	if(root->l)
	{struct BST *cur = root->l;
		while(cur->r)
				cur= cur->r;
			
		return cur;	
	}
	
	
}

struct BST *deleteNode(struct BST *root, int key)
{
	
	if(!root)
		return NULL;
	if(root->data>key)
		root->l = deleteNode(root->l, key);
	else if(root->data<key)
		root->r =  deleteNode(root->r, key);
	else
	{
		if(!root->l && !root->r)
		{free(root);
		return NULL;
		}else if(root->l && root->r)
		{
			struct BST *temp = inorderPre(root);
			root= temp;
			root->l =  deleteNode( root->l, temp->data);
		}else
		{
			root = root->l?root->l:root->r;
			
		}
		
		
		
		
	}
	
	return root;
	
}

// verify BST
bool isBST(struct BST *root, int *prev)
{
	if(!root)
		return true;
	
	if(!isBST(root->l, prev))
		return false;
	if(root->data<*prev)
		return false;
	*prev = root->data;
	
	return isBST(root->r, prev);
	
	
	
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
		
	deleteNode(root,3);
			printf("\nafter deletion\n\n");
			printInorder(root);
	int prev=INT_MIN;		
	if(isBST(root, &prev))
			printf("\nBST\n");
	else
			printf("\nNot BST\n");

	return 0;
	}