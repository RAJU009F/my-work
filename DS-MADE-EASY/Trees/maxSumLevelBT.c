#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: max sum and level in BT
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

struct Queue *createQ()
{
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	if(!q)
			return NULL;
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));

	q->fr = NULL;
	q->rr = NULL;
	
	return q;
}

struct SLL *newNodeQ(struct BT *data)
{
	struct SLL *node =  (struct SLL *)malloc(sizeof(struct SLL));
	if(!node)
			return NULL;
	node->data=  data;
	node->next = NULL;
	
	return node;
	
	
}

int isEmpty(struct Queue *q)
{
	return q->fr == NULL;
	
}
	

void NQ(struct Queue *q, struct BT *data)
{
	if(isEmpty(q))
	{
		q->rr = newNodeQ(data);
		q->fr = q->rr;
		return;
	}else
	{
		struct SLL *node = newNodeQ(data);
		q->rr->next = node;
		q->rr = q->rr->next;
		
	}
	
	
	
}

struct BT *DQ(struct Queue *q)	
{
	if(isEmpty(q))
		return NULL;
	struct SLL *temp =  q->fr;
	struct BT *node =  temp->data;
	if(q->fr == q->rr)
			q->fr = q->rr = NULL;
	else
			q->fr = q->fr->next;
	free(temp);
	return node;
	
}



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


void findMaxSumLevel(struct BT *root)
{
	if(!root)
	{	printf("Tree is Empty\n");
		return;}
		
	struct Queue *q =  createQ();
	NQ(q, root);
	NQ(q,NULL);
	int maxSum = 0;
	int curSum = 0;
	int maxLevel = 0;
	int curLevel = 0;
	
	while(!isEmpty(q))
	{
		root =  DQ(q);
		
		if(!root)
		{
			if(!isEmpty(q))
				NQ(q, NULL);
			if(curSum>maxSum)
			{
				maxSum = curSum;
				maxLevel = curLevel;
				
			}
			curLevel++;
			curSum = 0;
		}else
		{
			curSum += root->data; 
			if(root->l)
				NQ(q, root->l);
			if(root->r)
					NQ(q, root->r);
			
			
			
		}
		
		
	}

printf(" Level [%d] with Maxsum [%d] \n",maxLevel, maxSum);
	
	
}


int main()
	{
		struct BT *root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		root->l->l = newNode(4);
		root->l->r =  newNode(5);
		root->r->l = newNode(6);
		root->r->r =  newNode(7);
	findMaxSumLevel(root);
	
	return 0;
	}