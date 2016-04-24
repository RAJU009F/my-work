#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Queue
# Problem Statement	: Q 
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
	return (q->r==NULL && q->f==NULL);
	
}
struct Queue *inializeQ()
{
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	if(!q)
			return NULL;
	q->r = (struct SLL *) malloc(sizeof(struct SLL));
	q->f = (struct SLL *) malloc(sizeof(struct SLL));
	
	return q;
}
void NQ(struct Queue **q ,int data)
{
	struct SLL *node = newNode(data);
	(*q)->r->next = newNode;
	(*q)->r = newNode;
	if(!(*q)->f))
		(*q)->f = (*q)->r;
}

void printQ(struct Queue *q)
{
	if(isEmpty(q))
		return ;
	printf("[\t");
	while(q->f)
	{
		printf("%d\t", q->f->data);
		
	}
	printf("]\t")
	
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
		NQ(&Q,1);
		NQ(&Q,2);
		NQ(&Q,3);
		NQ(&Q,4);
		NQ(&Q,5);
		NQ(&Q,6);
		printQ(Q);
		printf("[\t");
		while(!isEmpty(Q))
		{
			int data = DQ(&Q);
			printf("%d\t", data);
			
		}
		printf("]\t");
			
	return 0;
	}