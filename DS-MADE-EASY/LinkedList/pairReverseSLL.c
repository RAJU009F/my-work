#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: pair wise reverse the linked list
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

void swap(int *a, int *b)
{
	int temp = *a;
	*a= *b;
	*b =temp;
	
}
void pairReverseSLL_R(struct SLL **h)
{
	struct SLL *curr=*h;
	if(curr && curr->next)
	{
		swap(&curr->data, &curr->next->data);
		pairReverseSLL_R(&curr->next->next);
		
	}
	
	
	
}
void pairReverseSLL(struct SLL **h)
{
	struct SLL *p,*q;
	
	if(!*h || !(*h)->next)
		return;
	struct SLL *curr = *h;
	while(curr && curr->next)
	{
		swap(&curr->data, &curr->next->data);
			curr = curr->next->next;


		
	}
	
	
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
	
	printf("Before:\n");
	printList(head);
	printf("After:\n");
	pairReverseSLL(&head);
	printList(head);
	pairReverseSLL_R(&head);
	printf("after re paired:\n");
	printList(head);
	
	return 0;
	}