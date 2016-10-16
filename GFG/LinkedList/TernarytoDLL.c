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
# Problem Statement	: Ternary Tree to Double Linked List
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

//  Ternary tree node 
struct Node 
{
	int data;
	
	struct Node *l;
	struct Node *m;
	struct Node *r;
	
};

void printTree(struct Node *root)
{
	if(!root)
		return;
	
	printf("%d ", root->data);
	printTree(root->l);
	printTree(root->m);
	printTree(root->r);
	
	
	
}


struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
	if(!node)
			return NULL;
		
	node->data = data;
	node->r = node->m= node->l = NULL;

	return node; 	
	
	
}
void push(struct Node *node,  struct Node **tail)
{
	
	if(!*tail)
	{
		*tail = node;
		node->m = node->r=node->l = NULL;
		
		
	}else
	{
		node->l =  *tail;
		node->m = NULL;
		node->r = NULL;
		(*tail)->r= node;
		*tail  = node;
		
		
	}
	
}
void TTtoDLLUtil(struct Node *root, struct Node **head,  struct Node **tail)
{
	
	if(!root)
		return;
	
	if(!*head)
		*head = root;
	struct Node *left = root->l;
	struct Node *right = root->r;
	struct Node *mid = root->m;
	
	push(root,  tail);
	TTtoDLLUtil(mid, head, tail );
	TTtoDLLUtil(left, head, tail );
	
	TTtoDLLUtil(right, head, tail );
	
	
	
}

void printDLL(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
			head=  head ->r;
	}
	
}
void TTtoDLL(struct Node *root, struct Node **head)
{
	if(!(root))
		return ;
	
	struct Node *tail =NULL;
	
	TTtoDLLUtil(root, head, &tail);
	
	
	
}

int main()
{
		struct Node *root =  NULL;
		root =  newNode(1);
		root->l =  newNode(2);
		root->m = newNode(3);
		root->r = newNode(4);
		root->l->l = newNode(5);
		root->l->m = newNode(6);
		root->l->r = newNode(7);
		root->m->l= newNode(8);
		root->m->m = newNode(9);
		root->m->r = newNode(10);
		root->r->l = newNode(11);
		root->r->m = newNode(12);
		root->r->r = newNode(13);
		root->l->l->l = newNode(14);
		root->l->l->m = newNode(15);
		root->l->l->r = newNode(16);
		
		printTree(root);
		
		struct Node *head= NULL;
		printf("\n");
		TTtoDLL(root, &head);
		printDLL(head);
	
}



