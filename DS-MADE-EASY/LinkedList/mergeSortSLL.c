#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: 
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
		else if(!h2)
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


void splitList(struct SLL **source, struct SLL **front, struct SLL **back)
{
	struct SLL *fPtr, *sPtr;
	
	if(!*source || !(*source)->next)
	{
			*front = *source;
			*back = NULL;
		
	}else
	{
		fPtr = *source;
		fPtr = (*source) ->next;
		while(fPtr)
		{
			fPtr = fPtr->next;
			if(fPtr)
			{
				sPtr = sPtr->next;	
				fPtr = fPtr->next;	

						
			}
			
		}
		
		
		*front = *source;
		*back = sPtr->next;
		sPtr->next = NULL;
		printList(*front);
		printList(*back);
	}
	
	
	
}
void mergeSort(struct SLL **h)
{
		struct SLL *a, *b;
		struct SLL *head = *h;
		if(!*h || !((*h)->next))
		{	return;}
		
		splitList(h, &a, &b);
		
		mergeSort(&a);
		mergeSort(&b);
		
		printList(a);
		printList(b);
		//printList(b);
		return;
		*h= mergeLists(a, b);
	
	
	
	
	
}


int main()
	{
		struct SLL *head1 = newNode(11);
		head1 -> next = newNode(2);
		head1->next->next = newNode(13);
		/*head1->next->next->next = newNode(43);
		head1->next->next->next->next = newNode(5);
		head1->next->next ->next ->next ->next = newNode(62);
		head1->next->next->next->next->next->next = newNode(7);
		head1->next->next->next->next->next->next->next = newNode(800);
		head1->next->next->next->next->next->next->next->next = newNode(9);
		head1->next->next->next->next->next->next ->next ->next ->next = newNode(10);*/
		printf("Before|\n");
		printList(head1);
		mergeSort(&head1);
		printf("After");
		printList(head1);
	
	return 0;
	}