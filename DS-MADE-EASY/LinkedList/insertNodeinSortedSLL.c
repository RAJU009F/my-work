#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: insert node in sorted LL
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

void insertNodeSortedSLL(struct SLL **h)
{
	struct SLL *p,*q;
	int data;
	printf("Enter node data: ");
	scanf("%d",&data);
	if(!h)
	{
		*h=newNode(data);
		
	}
	p =*h;
	while(p && p->data<data)
	{
		q =p;
		p=p->next;
	
		
	}
	
	q->next = newNode(data);
	q->next->next = p;
	
	
}

int main()
	{
	
	struct SLL *head = newNode(1);
		head -> next = newNode(2);
		head->next->next = newNode(3);
		head->next->next->next = newNode(4);
		//struct SLL *temp=head->next->next->next->next = newNode(5);
		head->next->next ->next ->next  = newNode(6);
		head->next->next->next->next->next = newNode(7);
		head->next->next->next->next->next->next = newNode(8);
		head->next->next->next->next->next->next->next = newNode(9);
		struct  SLL *last=head->next->next->next->next->next->next->next->next = newNode(10);
		
	printf("sorted List before insertion \n");
	printList(head);
	
	insertNodeSortedSLL(&head);
	printf("sorted List after insert\n");
	printList(head);
	return 0;
	}