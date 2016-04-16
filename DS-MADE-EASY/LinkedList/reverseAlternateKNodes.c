#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: 
# Description		: reverse first k nodes ,  update head next to cur and skip k-1 elemnts then do the same for cur->next = previous steps.
					  STEP-2: get the first row 
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

struct SLL *reverseAlternateKNodes(struct SLL *h, int k)
{
	struct SLL *cur=h,*prev=NULL,*n;
	int count=0;
	
	while(cur && count <k)
	{
		n= cur->next; // next node
		cur->next = prev;
		prev = cur;
		cur = n;
		
		count++;
	}
		
	if(h)
		h->next= cur;
	// move k nodes 
	count = 0;
	while(count<k-1 && cur)
	{
		count++;
		cur = cur->next;
		
	}
	
	if(cur)
		cur->next = reverseAlternateKNodes(cur->next,k);
	
	
	return prev;	
}


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


int main()
	{
		struct SLL *head1 = newNode(1);
		head1 -> next = newNode(2);
		head1->next->next = newNode(3);
		head1->next->next->next = newNode(4);
		head1->next->next->next->next = newNode(5);
		head1->next->next ->next ->next ->next = newNode(6);
		head1->next->next->next->next->next->next = newNode(7);
		head1->next->next->next->next->next->next->next = newNode(8);
		head1->next->next->next->next->next->next->next->next = newNode(9);
		head1->next->next->next->next->next->next ->next ->next ->next = newNode(10);
		printf("Before|\n");
		printList(head1);
		head1=reverseAlternateKNodes(head1 ,3);
		printf("After");
		printList(head1);
		
		
	return 0;
	}