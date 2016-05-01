#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: print all Root to leave paths
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

void printArray(int arr[] ,int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("[%d]\t",arr[i]);
	}
	
	printf("\n");
}
void printRoottoLeavePaths(struct BT *root, int arr[], int level)
{
	if(!root)
			return;
	arr[level++] = root->data;
	if(!root->l && !root->r)
	{	printArray(arr, level);
		return;}
	else
	{
		printRoottoLeavePaths(root->l, arr,  level);
		printRoottoLeavePaths(root->r, arr, level);
		
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
	int arr[100];
	int level = 0;
	printRoottoLeavePaths(root, arr, level );
	}