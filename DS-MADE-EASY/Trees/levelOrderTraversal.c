#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: Level Order traversal  and find the height or levels
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct BT
{
	struct BT *l;
	int data;
	struct BT *r;
};


// create a BT Node

struct BT *newNode(int data)
{
		struct BT *node = (struct BT *)malloc(sizeof(struct BT));
		if(!node)
			return node;
		
		node ->data = data;
		node ->l = node->r = NULL;
		
	return node;	
}

struct SLL 
{
	struct BT *data;
	struct SLL *next;
	
};

struct Queue
{
	struct SLL *fr;
	struct SLL *rr;
	
};

struct SLL *newNodeQ(struct BT *data)
{
	struct SLL *node =  (struct SLL *)malloc(sizeof(struct SLL));
	node -> data = data;
	node->next = NULL;
	
}

struct Queue *initializeQ()
{
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	
	if(!q)
		return NULL;
	
	struct SLL *node = (struct SLL *) malloc(sizeof(struct SLL));
	
	q->fr = NULL;
	q->rr = NULL;
	
	return q;
	
	
}

int isEmptyQ(struct Queue *q)	
{
	return q->fr == NULL;
	
}


void NQ(struct Queue *q, struct BT *data)
{
	struct SLL *node = newNodeQ(data);
	
	if(!q->fr)
	{
		q->rr = node;
		q->fr = q->rr ;
		//printf("first node %d\n",data->data);
		return ;
	}
	else
		
	{
	q->rr->next = node;
	q->rr = q->rr->next;
	//printf("secode node %d\n",data->data);

}}

struct BT *DQ(struct Queue *q)
{
	
	if(isEmptyQ(q))
		return NULL;
	//printf("dq node %d\n",q->fr->data->data);
	struct SLL *node = q->fr;
	struct BT *data = node->data;
	
	if(q->fr == q->rr)
	{q->rr = q->fr = NULL;
		
	}
	
	else
	q->fr = q->fr->next;
	free(node);
	//printf("dq node %d\n",data->data);
	return data;
	
	
}

void printLevelOrder(struct BT *root)
{
	
	if(!root)
		return;
	
	struct Queue *q = initializeQ();
	
	NQ(q, root);
	
	while(!isEmptyQ(q))
	{
		root = DQ(q);
		printf("[%d]\t", root->data);
		
		if(root->l)
			NQ(q, root->l);
		if(root->r)
			NQ(q,root->r);
		
	}
	
	
	
}

void printLevel(struct BT *root)
{
	if(!root)
			return ;
	if(!root->l && !root->r)
	{
		printf("Level or Height : [%d]",1);
		return;
	}
	
	struct Queue *q= initializeQ();
	int level = 0;
	NQ(q, root);
	NQ(q, NULL);
	while(!isEmptyQ(q))

	{
		root = DQ(q);
		if(!root)
		{
			level++;
			if(!isEmptyQ(q))
				NQ(q, NULL);
			
			
			
		}else
		{
			if(root->l)
				NQ(q,root->l);
			if(root->r)
				NQ(q,root->r);
			
			
		}
		
		
		
		
	}
	
	
	printf("\nLevel or Height : [%d]\n",level);
	
}

int main()
	{
		struct BT *root = NULL;
		root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		root->r->l = newNode(6);
		root->r->r = newNode(7);
		root->l->r->l = newNode(33);
		root->l->r->r = newNode(46);
		root->r->r->l = newNode(63);
		root->r->r->r = newNode(65);
		printf("\nLevel order:\n");
		printLevelOrder(root);
		printLevel(root);
	
	return 0;
	}