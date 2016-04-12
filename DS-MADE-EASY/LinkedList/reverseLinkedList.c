#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists 
# Problem Statement	: reverse LL
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct SLL
{
	int data;
	struct SLL *next;
};

struct SLL *newNode(int data)
{
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));
	
	if(!node)
			return;
		
		node->next = NULL;
		node->data = data;
		
		return node;
	
	
}

void printList(struct SLL *h)
{
	while(h)
	{
		printf("[%d]->",h->data);
		h=h->next;
	}
	printf("NULL\n");
	
	
}

void reverseSLL(struct SLL **h)
{
	if(!*h || !(*h)->next)
		return;
	struct SLL *p,*q=NULL, *curr=*h;
	while(curr)
	{
		p = curr;
		curr = curr ->next;
		p->next = q;
		q =p;
		
		
		
	}
	*h = p;
	
	
	
}

void reverseRSLL(struct SLL *curr, struct SLL **head)
{
	if(!curr)
		return ;
	if(!(curr->next))
	{
		*head =curr;
		return;
		
	}
	reverseRSLL(curr->next, head);
	curr->next->next = curr;
	curr ->next = NULL;
	
	
	
}
int main()
	{
		struct SLL *head = newNode(1);
		head -> next = newNode(2);
		head->next->next = newNode(3);
		head->next->next->next = newNode(4);
		struct SLL *temp=head->next->next->next->next = newNode(5);
		head->next->next ->next ->next ->next = newNode(6);
		head->next->next->next->next->next->next = newNode(7);
		head->next->next->next->next->next->next->next = newNode(8);
		head->next->next->next->next->next->next->next->next = newNode(9);
		struct  SLL *last=head->next->next->next->next->next->next ->next ->next ->next = newNode(10);
		
		printf("list before reverse:\n");
		printList(head);
		reverseSLL(&head);
		printf("SLL after reverse:\n");
		printList(head);
		reverseRSLL(head,&head);
		printf("SLL after Re-reverse:\n");
		printList(head);
	
	return 0;
	}