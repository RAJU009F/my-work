// # import java.io.*;
// # import java.lang.*;
// # import java.util.*;

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
# Problem Statement	: Merge Sort
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


struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
	if(!node)
		return NULL;
	node->data =  data;
	node->next = NULL;
	
	return node;
}
void push(struct Node **head, int data)
{
	struct Node *node =  newNode(data);
	node->next = *head;
	*head =  node;
	
}

void printList(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;	
	}	
}

struct Node *mergeLists(struct Node *a, struct Node *b)
{
	if(!a && !b)
		return NULL;
	if(!a)
		return b;
	if(!b)
		return a;
	struct Node *res = NULL;
	if(a->data>b->data)
		{	
			res = b;
			res->next =  mergeLists(a, b->next);
		}
		
		else
		
		{
			res = a;
			res->next= mergeLists(a->next, b);
			
		}
		
		return res;
	
}

void splitList(struct Node **head, struct Node **a,  struct Node **b)
{
	if(!(*head)||(!(*head)->next))
	{
		*a =  *head;
		*b = NULL;
		
	}
	
	struct Node *last = *head;
	struct Node *mid = *head;
	while(last->next && last->next->next)
	{
		mid =  mid->next;
		last = last->next->next;
	}
	

	*b = mid->next;
	mid->next = NULL;
	*a =  *head;
	
}

void mergeSort(struct Node **head)
{
	if(!(*head)||(!(*head)->next))
			return;
	
	struct Node *a;
	struct Node *b;
	splitList(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	
	*head =  mergeLists(a, b);
	
	
	
}



int main()
{
	struct Node *head =  NULL;
	push(&head, 1);
	push(&head, 4);
	push(&head, 14);
	push(&head, 41);
	push(&head, 15);
	push(&head, 16);
	push(&head, 18);
	push(&head, 19);
	push(&head, 31);
	printList(head);
	printf("\n");
	mergeSort(&head);
	printList(head);
	
	
	
}