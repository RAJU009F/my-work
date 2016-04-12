#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Type 				: LinkedLists
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/
// Sinlgy Linked List
struct SLL
{
	int data;
	struct SLL *next;
};
struct SLL *newNode(int data)
{
	struct SLL *node =  (struct SLL *) malloc(sizeof(struct SLL));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
	
}

void addNodes(struct SLL **h,  int data)
{
	struct SLL *cur = *h;
	while(cur->next)
	{
		cur = cur->next;
		
	}
	cur->next = newNode(data);
	
}
void extendList(struct SLL **h, int n)
{
	int i;
	srand(n);
	for(i=0;i<n;i++)
	{
		addNodes(h, rand()%100);
		
	}
	
}
void printList(struct SLL *h)
{
	while(h)
	{
		printf("[%d]->",h->data);
		h= h->next;
		
		
	}
	
	printf("NULL\n");
	
	
}

void lengthSLL(struct SLL *h)
{
	int count=0;
	while(h)
	{
		h = h->next;
		count++;
	}
	printf("\nLength: %d \n",count);
	
	
}

void insertSLL(struct SLL **h ,int data, int pos)
{
	
	
	
	
}

int main()
	{
	
	struct SLL *head = newNode(1);
	int n=10;
	extendList(&head,n);
	lengthSLL(head);
	printList(head);
	
	return 0;
	}