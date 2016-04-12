#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	:  find the Nth node from end of the list
# Description		:
# Complexity		: O(n) with single Scan
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
			return NULL;
	node->next = NULL;
	node ->data = data;
	return node;	
	
}
void findNthNode(struct SLL *h)
{
	if(!h)
	{
		printf("empty list");
		return;}
		int n,k=1;
	printf("Enter the nth node to find:");
	scanf("%d",&n);
	struct SLL *NthNode,*lastNode;
	NthNode = lastNode = h;
	
	while(lastNode->next)
	{
		if(k-n>=0)
			NthNode = NthNode ->next;
		k++;
		lastNode = lastNode->next;
		
	}
	
	if(k<n)
	{printf("\nno node exists\n");
	return;}
	else
		printf("Nth node is: [%d]",NthNode->data);
	
}

int main()
	{
		struct SLL *head = newNode(1);
		
		head->next = newNode(2);
		head->next->next = newNode(3);
		head->next->next->next = newNode(4);
		head->next->next->next->next = newNode(5);
		head->next->next ->next ->next ->next = newNode(6);
		head->next->next->next->next->next->next = newNode(7);
		
		findNthNode(head);
	
	return 0;
	}