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
	char data;
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

struct BT *buildTree(char arr[], int *index, int n)
{
	if(*index>=n)
		return NULL;
	struct BT *root = newNode(arr[*index]);
	(*index)++;
	if(root->data == 'L')
	{root->l= NULL;
     root->r = NULL;
	 return root;
	 }
	 else
	 {
		 root->l = buildTree(arr, index, n);
		 root->r = buildTree(arr, index, n);
		 
		 
	 }
	 
	 return root;
	
	
}
void printPreOrder(struct BT *root)
{
	if(root)
	{
		
		printf("[%c]\t",root->data);
		printPreOrder(root->l);
		printPreOrder(root->r);
		
	}
	
}
int main()
	{
		char pre[] = {'I', 'L', 'I', 'L', 'L'};
		int index = 0;
		printf("fdfdf\n");
		struct BT *root =buildTree(pre,&index, sizeof(pre)/sizeof(pre[0]));
		printf("fdfdf\n");
		printPreOrder(root);
	
	return 0;
	}