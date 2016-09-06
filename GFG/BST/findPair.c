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
# Problem Statement	: C: check sum in the TREE.
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
	struct BT *r;
	int data;
	
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
bool sumExistsUtil(struct BT *root, struct BT *tail, int X)
{
	while(root != tail)
	{
		if(root->data + tail->data == X)
		{	printf("%d %d", root->data, tail->data);
			return true;}
		else if(root->data + tail->data > X)
			tail = tail->l;
		else
			root = root->r;
		
		
		
		
	}
	
	
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
bool sumExists(struct BT *root, int X)
{
	if(!root)
		return false;
	struct BT *head = NULL;
	struct BT *tail = NULL;
	BTtoDLL(root, &head, &tail);

	return sumExistsUtil(head, tail, X);
	
	
}



int main()
{
	struct BT  *root = Node(3);
	root->l = Node(-3);
	root->l->r = Node(1);
	root->l->r->r = Node(2);
	root->r = Node(4);
	root->r = Node(9);
	root->r = Node(9);
	
	if(sumExists(root, 10))
		printf("present");
	
	return 0;
}

