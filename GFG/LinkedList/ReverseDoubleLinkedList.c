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
# Problem Statement	: Reverse the double linked list
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct DLL
{
	struct DLL *pre;
	struct DLL *next;
	int data;
	
};

struct DLL *newNode(int data)
{
	struct DLL *node =  (struct DLL *) malloc(sizeof(struct DLL));
	if(!node)
		return NULL;
	node->data = data;
	node->next =  NULL;
	node->pre = NULL;
	
	return node;
	
}

void push(struct DLL **head,  int data)
{
	struct DLL *node =  newNode(data);
	if(!*(head))
	{	*head =  node;
		return;
		}
	node->next = *head;
	(*head)->pre = node;
	*head =  node;
	
} 

void printList(struct DLL *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head =  head->next;
		
	}
	
	
}

void reverse(struct DLL **head)
{
	if(!(*head) || !(*head)->next)
			return;
		
	struct DLL *cur =  *head;
	struct DLL *prev = NULL;
	
	while(cur->next)
	{
		struct DLL *temp = cur->next;
		cur->next = prev;
		cur->pre = temp;
		prev =  cur;
		cur =  temp;
		
	}
	cur->next =  prev;
	*head =  cur;

	
}

int main()

{
	
	struct DLL *head = NULL;
	push(&head, 2);
		push(&head, 4);
			push(&head, 8);
				push(&head, 12);
					push(&head, 10);
	
	printList(head);
	reverse(&head);
	printf ("after Reverse ");
	printList(head);
	
}