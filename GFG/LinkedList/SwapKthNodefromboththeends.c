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
# Problem Statement	: swap kth node from both the ends without data exchnage
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct Node 
	{
		struct Node *next;
		int data;
	};
	
void swapKthNodefromBothEnds(struct Node **href, int k)
{
	//  count noof nodes in list;
	
	struct Node *cur = *href;
	int  n = 0; 
	int i;
	while(cur)
	{
		n++;
		cur =  cur->next;
	}
	
	// check n < k 
	if(k> n)
		return;
	
	//  check if middle nodes
	if(2*k-1 == n)
		return ;
	
	// find kth node from start;
	
	struct Node *x = *href;
	struct Node *x_prev = NULL;
	for(i=1; i<k; i++ )
	{
		x_prev = x;
		x =  x->next;
	}
	
	// find kth node from end
	struct Node *y = *href;
	struct Node *y_prev = NULL;
	for(i=1; i<n-k+1; i++ )
	{
		y_prev = y;
		y =  y->next;
	}

	
	//swap now
		if(x_prev)
		x_prev->next = y;
		if(y_prev)
		y_prev->next = x;
		
	struct Node *temp  =  x->next;
	x->next = y->next;
	y->next = temp;
	
	
	//  update href if k =1 or k=namespace
	
	if(k==1)
		*href = y;
	
	if(k==n)
		*href = x;
	
	
	
		
	
	
}	

struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
	if(!node )
		return ;
	node->data =  data;
	node->next =  NULL;
	
	return node;
	
}
void push(struct Node **head,  int data)
{
	struct Node *node = newNode(data);
	node->next = *head;
	*head =  node;
	
}	
void printList(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head =  head ->next;
		
	}
	
	printf("\n");
}	
	
int main()
	{
			struct Node *head =  NULL;
			push(&head, 10);
			push(&head, 9);
			push(&head, 8);
			push(&head, 7);push(&head, 6);
			push(&head, 5);
			push(&head, 4);
			push(&head, 3);
			push(&head, 2);
			push(&head, 1);
			printList(head);
	swapKthNodefromBothEnds(&head,  2);
			printList(head);
			
			swapKthNodefromBothEnds(&head,  1);
			printList(head);
			
			swapKthNodefromBothEnds(&head,  10);
			printList(head);
			
			
	}