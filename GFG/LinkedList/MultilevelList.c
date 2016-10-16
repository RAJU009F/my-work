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
# Problem Statement	: print the multiplevel list level by level
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
	struct Node *c;
	struct Node *next;
	int data;

};

struct Node *newNode(int data)
{
	
	struct Node *node =  (struct Node *)malloc(sizeof(struct Node));
	node->c = NULL;
	node->next = NULL;
	node ->data= data;
	
	return node;
	
}

void push(struct Node **head,  int data)
{
	struct Node *node =  newNode(data);
	node->c = *head;
	*head = node;

}

void printList(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head =  head ->next;
	}
	
}

void flattenList(struct Node **head)
{
	if(!(*head))
		return ;
	struct Node *cur = *head;
	struct Node *tail = *head;
	while(tail->next)
	{
		tail  =  tail -> next;
		
	}
	
	while(cur && cur != tail)
	{
		if(cur->c)
		{
			tail->next = cur->c;
			tail = tail->next;
			struct Node *temp = tail;
			while(temp->next)
				temp =  temp->next;
			tail =  temp;
			
		}
		
		
		cur=  cur->next;
		
	}
	
	
}

int main()
	{
	
		struct Node *head = NULL;
		push(&head, 11);
		push(&head, 7);
		push(&head, 12);
		push(&head, 5);
		push(&head, 10);
		
		// struct Node *head1 = NULL;
		
		// push(&head1, 13);
		// push(&head1, 20);
		// push(&head1, 4);
		// struct Node *head2 = NULL;
		// push(&head2, 6);
		// push(&head2, 17);
		// struct Node *head3 = NULL;
		// push(&head3, 8);
		// push(&head3, 9);
		// struct Node *head4 = NULL;
		// push(&head4, 15);
		// push(&head4, 19);
		// struct Node *head5 = NULL;
		// push(&head5, 2);
		// struct Node *head6 = NULL;
		// push(&head6, 16);
		// struct Node *head7 = NULL;
		// push(&head7, 3);
		
		
		
		// head->c = head1;
		// head->next->next->next->c= head2;
		// head2->c =  head3;
		// head3->c = head4;
		// head1->next->c =  head5;
		// head1->next->next->c =  head6;
		// head6->c = head7;
		
		push(&(head->c->next), 101000);
		push(&(head->c->next), 10100);
		push(&(head->c->next), 1010);
		push(&(head->c->next), 101);
		
		push(&(head->next), 2);
		push(&(head->next->c), 200);
		push(&(head->next->c), 2000);
		push(&(head->next->c), 20000);
		push(&(head->next->c), 1200);
		push(&(head->next->c->c), 12030);
		
		push(&(head->next->next), 3);
		push(&(head->next->next->next), 4);
		push(&(head->next->next->next->next), 5);
		push(&(head->next->next->next->next->next), 6);
		push(&(head->next->next->next->next->next->next), 7);
		push(&(head->next->next->next->next->next->next->next), 8232323);
		push(&(head->next->next->next->next->next->next->next->c), 8444);
		push(&(head->next->next->next->next->next->next->next->c), 87777);
		push(&(head->next->next->next->next->next->next->next->c), 877);
		push(&(head->next->next->next->next->next->next->next->c), 8);
		push(&(head->next->next->next->next->next->next->next->c->next), 80000);
		push(&(head->next->next->next->next->next->next->next->c->next->c), 80002);
		push(&(head->next->next->next->next->next->next->next->c->next->c), 80001);
		flattenList(&head);
		printList(head);
	}