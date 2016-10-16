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
# Problem Statement	: split LinkedList alternatively
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct SLL 
{
	struct SLL *next;
	int data;
	
};

struct SLL *newNode(int data)
{
	struct SLL *node =  (struct SLL *) malloc(sizeof(struct SLL ));
	if(!node)
		return NULL;
	node->data = data;
	node->next =  NULL;
	return node;
}

void push(struct SLL **head, int data)
{
	struct SLL *node = newNode(data);
	node->next =  *head;
	*head =  node;
	
}


void printSLL(struct SLL *head)
{
	
	while(head)
	{
		printf("%d ", head->data);
		head =  head->next;
		
	}
	printf("\n");
	
	
}

void split(struct SLL **head,  struct SLL **head1)
{
	if(!(*head)||!(*head)->next)
		return;
	
	struct SLL *cur1 = *head;
	struct SLL *cur2 = *head1 = (*head)->next;
	
	while(cur2 && cur2->next)
	{
		cur1->next =  cur2->next;
		cur1 =  cur1->next;
		cur2->next =  cur1->next;
		
		cur2 =  cur2->next;
		
		
	}
	
	cur1->next = NULL;
	
	
	
	
	
}

int main()
{
	struct SLL *head =  NULL;
	
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	struct SLL *head2 =  NULL;
	printSLL(head);
	split(&head, &head2);
	
	printSLL(head);
	printSLL(head2);
	
}


