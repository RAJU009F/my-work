#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: elect the leader in a circle of n people.
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
		return NULL;
	
	node ->data =data;
	node ->next=NULL;
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
void electLeader(int M)
{
	int i;
	struct SLL *p,*q;
	
	int count;
	p= newNode(1);
	q =p;
	for(i=1;i<M*M;i++)
		{	
			p->next = newNode(i+1);
			p = p->next;
		}
	printList(q);
	p->next = q;
	struct SLL *cur=q;
	i=0;
	while(cur!=cur->next)
	{
			cur = cur->next ;
			i++;
			if(i%M==0)
				cur->next=cur->next->next;
		printf("%d\n",cur->data);
	}
		
	printf("Leader is %d\n",cur->data);
	
}

int main()
	{
	
		
		int M;
		scanf("%d",&M);
		electLeader(M);
		
		
	return 0;
	}