#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: find middle node and check the lenght is odd or even;
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
void middleNode(struct SLL *h)
{
	
	struct SLL *sPtr,*fPtr;
	sPtr = fPtr = h;
	if(!fPtr)
		return;
	
	while(fPtr&&fPtr->next)
	{
		fPtr = fPtr ->next->next;
		sPtr = sPtr ->next;
		
		
	}
	
	printf("Middle of node : %d\n",sPtr->data);
	
	
}

int verfiyOddEvenSLL(struct SLL *h)
{
	if(!h)
		return 0;
	
	struct SLL *p =h;
	while(p && p->next)
	{
		p = p->next->next;
	}
	
	if(p)
		return 1;
	return 0;
	
	
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
		
		middleNode(head);
	
	if(verfiyOddEvenSLL(head))
			printf("\nLenght is odd\n");
	else
			printf("\n lenght is even\n");
	return 0;
	}