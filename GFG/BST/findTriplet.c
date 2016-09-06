// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BST
# Problem Statement	: C:is tripletPresent in the TREE.
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct BT {
	
	int data;
	struct BT *l;
	struct BT *r;	
};

struct BT *Node(int data)
{
	struct BT  *node =  (struct BT *)malloc(sizeof(struct BT));
	if(!node)
		return NULL;
	node->data = data;
	node->l = NULL;
	node->r = NULL;
	
	return node;	
}

bool tripletPresentUtil(struct BT *head,  struct BT *tail, int X)
{
	printf("fsdfsd");
	while(head != tail)
	{
		if(X == head->data+tail->data)
			return true;
		if(X>head->data+tail->data)
			head = head->r;
		else
		{tail = tail->l;
		printf("%d", tail->data);}
		
		
	}
	return false;
}

void  BTtoDLL(struct BT *root, struct BT **head, struct BT **tail)
{
	if(!root)
		return ;
	if(root->l)
	BTtoDLL(root->l, head, tail);
	if(!(*tail))
		*head = root;
	else
	{	root->l = *tail;
		(*tail)->r = root;
	}
				
	(*tail) = root;
	if(root->r)
	BTtoDLL(root->r, head, tail);
}

void printDLL(struct BT *root)
{
	if(!root)
		return;
	while(root)
	{printf("%d\t",root->data);
	root = root->r;
}
	
}

bool tripletPresent(struct BT *root)
{
	
	if(!root)
		return false;
	struct BT *head = NULL;
	struct BT *tail = NULL;
	BTtoDLL(root, &head, &tail);
	printDLL(head);
	while(head->r != tail & (head->data<0))
	{
		
				if(tripletPresentUtil(head->r, tail, -1*head->data));
					return true;
		head = head->r;
	}
	
	
	
	return false;
}



int main()
{
	struct BT  *root = Node(3);
	root->l = Node(-3);
	root->l->r = Node(1);
	root->l->r->r = Node(2);
	root->r = Node(4);
	root->r = Node(9);
	
	if(tripletPresent(root))
		printf("present");
	else
		printf("\nNot Present");
	return 0;
}
