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
# Problem Statement	: Flaatern the linked list in sorted order
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------
i
=======================
*/

struct Node
{
		struct Node *r;
		struct Node *d;
		int data;

} ;



void printList(struct Node *head)
{
	
	while(head)
	{		
		printf ("%d ", head->data);
		head =  head->d;
	}
	
}

struct Node *flatternListUtil(struct Node *a, struct Node *b)
{
	if(!a && !b)
		return NULL;
	if(!a )
		return b;
	if(!b)
		return a;
	struct Node *res = NULL;
	
	if(a->data < b->data)
	{
		res = a;
		res->d= flatternListUtil(a->d, b);
		
	}else
	{
		res = b;
		res->d = flatternListUtil(a, b->d);
		
	}
	
	return res;
	
	
	
}

void flatternList(struct Node **head)
{
	if(!(*head) || !(*head)->r )
			return;
	
	struct Node *temp =  *head;
	struct Node *cur = *head;
	while(cur->r)
	{
		temp =  cur->r->r;
		cur =  flatternListUtil(cur, cur->r );
		cur->r =temp; 
	}
	
	*head = cur;
	
	
	
}

struct Node *newNode(int data)
{
	struct Node * node =  (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->d = NULL;
	node->r = NULL;
	return node;
	
}

void push(struct Node **head, int data)
{
	struct Node *node =  newNode(data);
	node->d = *head;
	*head =  node;
	
	
}



	


int main()
{
	
	struct Node *head = NULL;
	push(&head, 30);
	push(&head, 8);
	push(&head, 7);
	push(&head, 5);
	
	

	push(&(head->r), 20);
	push(&(head->r), 10);
	
	push(&(head->r->r), 50);
	push(&(head->r->r), 22);
	push(&(head->r->r), 19);
	
	push(&(head->r->r->r), 45);
	push(&(head->r->r->r), 40);
	push(&(head->r->r->r), 35);
	push(&(head->r->r->r), 20);
	
	
	
	flatternList(&head);	
	printList(head); 	
	
}

