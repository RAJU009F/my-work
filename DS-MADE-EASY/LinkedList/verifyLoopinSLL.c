#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: a. Check Loop terminated or not, And b. find the LOOP start node
# Description		:
# Complexity		: O(n)
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
	
	struct SLL *node  =  (struct SLL *) malloc(sizeof(struct SLL));
	if(!node)
		return;
	node ->data = data;
	node->next = NULL;
	return node;
	
}

void findLoopStartNode(struct SLL *h)
{
	int flag = 0;
	if(!h)
	{printf("List Empty\n");
		return;
	}
	struct SLL *sPtr, *fPtr;
	sPtr = fPtr = h;
	while(sPtr && fPtr)
	{
		fPtr = fPtr ->next;
		if(!fPtr)
			break;
		if(fPtr == sPtr)
		{
			flag =1;
			break;
			
		}
		fPtr =fPtr->next;
		if(!fPtr)
			break;
		if(fPtr==sPtr)
		{
			flag =1;
			break;
			
		}
		
		sPtr = sPtr ->next;
	}
	
	if(flag)
	{
		printf("loop exists\n");
		//count the loop length;
		struct SLL *loopNode = sPtr;
		int count = 1;
		
		while(fPtr->next !=sPtr)
		{
			fPtr = fPtr ->next;
			//sPtr = sPtr ->next;
			count++;			
		}
		printf("length:%d\n",count);
		sPtr = h;
		// find the loop start node
		while(1)
		{
			fPtr = loopNode;
			while(fPtr->next !=loopNode && fPtr->next !=sPtr)
					fPtr = fPtr->next;
			if(fPtr->next == sPtr)
					break;
			sPtr = sPtr->next;
			
			
		}
	
		
		printf("loop start node: [%d]\n",sPtr->data);
		// remove the loop;
		fPtr->next = NULL;
		
		
	}else
		{
			
			printf("Loop doesn't exists\n");
		}

	
	
}

int loopExists(struct SLL *h)
{
	if(!h)
		return 0;
	struct SLL *sPtr, *fPtr;
	sPtr = fPtr = h;
	
	while(sPtr && fPtr)
	{
		fPtr = fPtr ->next;
		if(!fPtr)
				return 0;
		if(fPtr == sPtr)
				return 1;
		fPtr = fPtr -> next;
		if(!fPtr)
				return 0;
		if(fPtr == sPtr)
				return 1;
		sPtr = sPtr ->next;	
		
		
	}
	
	return 0;
	
	
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
		last ->next = temp;
		if(loopExists(head))
			printf("loop exists\n");
		else
			printf("No Loop found\n");
		findLoopStartNode(head);
		printList(head);
		
	return 0;
	}