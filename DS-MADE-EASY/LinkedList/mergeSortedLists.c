#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: merge two sorted lists
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
struct SLL *mergeLists(struct SLL *h1, struct SLL *h2)
{
	struct SLL *result=NULL;

		if(!h1)
			return h2;
		if(!h2)
			return h1;
		if(h1->data>h2->data)
		{
			result =h2;
			result->next = mergeLists(h1, h2->next);
			
		}else
		{
			result = h1;
			result->next = mergeLists(h1->next,h2);
			
		}
	
	
	return result;
}
int main()
	{
	struct SLL *head1 = newNode(1);
		head1 -> next = newNode(2);
		head1->next->next = newNode(3);
		head1->next->next->next = newNode(4);
		struct SLL *temp=head1->next->next->next->next = newNode(5);
		head1->next->next ->next ->next ->next = newNode(6);
		head1->next->next->next->next->next->next = newNode(7);
		head1->next->next->next->next->next->next->next = newNode(800);
		head1->next->next->next->next->next->next->next->next = newNode(900);
		struct  SLL *last=head1->next->next->next->next->next->next ->next ->next ->next = newNode(1000);
		
		struct SLL *head2 = newNode(100);
		head2 ->next = newNode(200);
		head2-> next->next = newNode(300);
		head2->next->next->next = newNode(600);
	
		printf("List1:\n");
		printList(head1);
		printf("List2:\n");
		printList(head2);
		printf("Merged List:\n");
		struct SLL *result = mergeLists(head1 ,head2);

		printList(result);
	
	
	return 0;
	}