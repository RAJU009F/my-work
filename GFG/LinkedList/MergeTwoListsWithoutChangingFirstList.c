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
# Problem Statement	: Merge Two lists without changing the  first list
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
	struct Node *node =  (struct Node *)malloc(sizeof(struct Node));
	if(!node)
		return;
	node->data = data;
	node->next = NULL;
	
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
		head = head->next;
		
	}
	printf("\n");
	
}

void swap(int *a,  int *b)
{
	int t =  *a;
	*a = *b;
	*b =t;
	
}
void mergeLists(struct Node **h1,  struct Node **h2)
{
	if(!(*h2)||!(*h2))
			return;
		
	struct Node *cur1 = *h1;
	struct Node *cur2 = *h2;
	while(cur1 && cur2)
	{
		
		if(cur1->data > cur2->data)
		{
			swap(&cur1->data, &cur2->data);
			if(cur2->next)
			{
				if(cur2->data > cur2->next->data)
				{
					swap(&cur2->data, &cur2->next->data);
					
				}
				
			}
			
			
		}
		cur1  =  cur1->next;
		
		
	}
	
	
}

int main()
	{
		struct Node *head1  =  NULL;
		struct Node *head2  = NULL;
		push(&head1, 10);
		push(&head1, 8);
		push(&head1, 7);
		push(&head1, 4);
		push(&head1, 2);
	

	
		
		
		push(&head2, 12);
		push(&head2, 3);
		push(&head2, 1);
		
		
		
		printList(head1);
		printList(head2);
		mergeLists(&head1,  &head2);
				printList(head1);
		printList(head2);
	
	}