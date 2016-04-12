#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Memory efficient LinkedLists 
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct MLL
{
	int data;
	struct MLL *pd;
};
struct MLL *newNode(int data)
{
	struct SLL *node =  (struct MLL *) malloc(sizeof(struct MLL));
	if(!node)
		return NULL;
	node->data = data;
	node->od = NULL;
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
void extendList(struct SLL **h)
{
	int i,n;
	printf("Enter number of nodes to be added : ");
	scanf("%d",&n);
	srand(n);
	for(i=0;i<n;i++)
	{
		addNodes(h, rand()%100);
		
	}
	
}
void printSLL(struct SLL *h)
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
int main()
	{
	struct MLL *head = newNode(1);
		
	
	return 0;
	}