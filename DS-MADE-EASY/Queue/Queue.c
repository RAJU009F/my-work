#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Queue
# Problem Statement	: Q implementation using LL
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

struct Queue
{
	struct SLL *f;
	struct SLL *r;
	
};

struct SLL *newNode(int data)
{
	struct SLL *node = (struct SLL *) malloc(sizeof(struct SLL));
	if(!node)
			return NULL;
	node->data = data;
	node->next = NULL;
	
	return node;
}

int isEmpty(struct Queue *q)
{
	//printf("%d %d" ,q->r->data, q->f->data);
	return q->f==NULL;
	
}
struct Queue *inializeQ()
{
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	struct SLL *node = (struct SLL *) malloc(sizeof(struct SLL));
	if(!q)
			return NULL;
 
	q->r=q->f = NULL;
	return q;
}
void NQ(struct Queue *q ,int data)
{
	struct SLL *node = newNode(data);
	if(!q->r)
	{q->r =node;
	q->f = q->r;
	return;} 
	(q)->r->next = node;
	(q)->r = node;
	if(!(q)->f)
		(q)->f = (q)->r;
}

void printQ(struct Queue *q)
{
	if(isEmpty(q))
		return ;
	struct SLL *cur = q->f;
	printf("[\t");
	while(cur)
	{
		printf("%d\t", cur->data);
		cur = cur->next;
	}
	printf("]\t");
	
}
int DQ(struct Queue **q)
{
	if(isEmpty(*q))
		return INT_MAX;
	struct SLL *node = (*q)->f;
	int data = node->data;
	(*q)->f = (*q)->f->next;
	free(node);
	return data;
	
	
}
int main()
	{
	
		struct Queue *Q = inializeQ();
		NQ(Q,1);
		NQ(Q,2);
		NQ(Q,3);
		NQ(Q,4);
		NQ(Q,5);
		NQ(Q,6);
		printQ(Q);
		printf("\n[\t");
		while(!isEmpty(Q))
		{
			int data = DQ(&Q);
			printf("%d\t", data);
			
		} 
		printf("]\t\n");
			
	return 0;
	}