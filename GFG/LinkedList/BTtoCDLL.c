// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: BT to circular DLLL
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/
struct Node 
	{
		struct Node *l;
		int data;
		struct Node *r;
	
	
	};
	
	
struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->l = node->r = NULL;
	
	return node;
	
}	

void converttoCDLLUTil(struct Node *root, struct Node **head,  struct Node **prev)
{
	
	if(!root)
		return;
	
	converttoCDLLUTil(root->l, head, prev);
	
	if(!*prev)
	{
		
		*head =  root;
			
	}else
	{
		(*prev)->r = root;
		root->l = *prev;
		
	}
	
	*prev = root;
		converttoCDLLUTil(root->r, head, prev);
	
}	
void printList(struct Node *node)
{
	int count =0;
	while(node)
	{
		printf("%d ", node->data);
		node = node ->r;
		count++;
		
		if(count==20)
			break;
		
		
	}
	printf("\n");
	
}	
	
void converttoCDLL(struct Node *root, struct Node **head)
{
	if(!root)
		return ;
	
	struct Node *prev = NULL;
	
	converttoCDLLUTil(root, head, &prev);
	
	if(prev)
	{(prev)->r = *head;
		prev->r->l = prev;
	}
	
}
	
	
int main()
		{
			struct Node *root =  NULL;
			root = newNode(1);
			root->l = newNode(2);
			root->r = newNode(3);
			root->l->l = newNode(4);
			root->l->r = newNode(5);
			root->r->l = newNode(6);
			root->r->r = newNode(7);
			root->l->l->l = newNode(10);
			root->r->r->r = newNode(20);
			struct Node *head = NULL;
			printList(root);
			converttoCDLL(root, &head );

			printList(head);
		}


