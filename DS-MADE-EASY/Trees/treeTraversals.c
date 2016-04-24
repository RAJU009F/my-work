#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: 
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
//========== Stack operations======

struct SLL *inializeStack()
{
	struct SLL *s = (struct SLL *)malloc(sizeof(struct SLL));
	if(!s)
		return NULL;
	s->next = NULL;
	s->data = (struct BT *) malloc(sizeof(struct BT));
	s->data = NULL;
	if(!s->data)
		return NULL;
	
	return s;
	
}

struct SLL *newNodeS(struct BT *data)
{
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));
	node->data = data;
	node->next = NULL;
	
	return node;
	
}

int isEmpty(struct SLL *s)
{
	return s==NULL;
	
}
void push(struct SLL **s, struct BT *data)
{
	struct SLL *node = newNodeS(data);
	node->next = *s;
	(*s) = node;

}
struct BT *pop(struct SLL **s)
{
	
	if(isEmpty(*s))
	{
		return NULL;
		
	}
	struct SLL *temp = *s;
	struct BT *node = temp->data;
	*s = (*s)->next;
	free(temp);
	return node;
	
	
}
struct BT *top(struct SLL *stack)
{
	if(isEmpty(stack))
		return NULL;
	return stack->data;
	
}

//============== Queue implementation===============
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


// ======================Inorder =================
void printInorder_I(struct BT *root)
{
	
	if(!root)
		return;
	
	struct SLL *stack = inializeStack();
	//push(&stack, root);
	
	while(1)
	{
		while(root)
		{
		
			push(&stack, root);
			root = root->l;
			
			
		}
		if((isEmpty(stack)))
			return;
		else
		{
			root = pop(&stack);
			printf("[%d]\t",root->data);
			root = root->r;
		}
		
		
		
		
	}
	
	
}
void printInorder(struct BT *root)
{
	if(root)
	{
		printInorder(root->l);
		printf("[%d]\t",root->data);
		printInorder(root->r);	
	}
	
	
	
}
//=======================preOreder==============
void printPreorder(struct BT *root)
{
	
	if(root)
	{
		printf("[%d]\t",root->data);
		printPreorder(root->l);
		printPreorder(root->r);
	}
	
	
}

void printPreorder_I(struct BT *root)
{
	if(!root)
		return ;
	struct SLL *stack = inializeStack();
	
	while(1)
	{
		while(root)
		{
			printf("[%d]\t",root->data);
			push(&stack,root);
			root = root->l;		
		}
		if(isEmpty(stack))
			return;
		root= pop(&stack);
		root = root ->r;
		
		
	}
	
}

//==============Post Order ===================

void printPostorder(struct BT *root)
{
	if(root)
	{
		printPostorder(root->l);
		printPostorder(root->r);
		printf("[%d]\t",root->data);
		
		
	}
		
	
}

void printPostorder_I(struct BT *root)
{
	if(!root)
			return ;
		
		struct SLL *stack = inializeStack();
		
		while(1)
		{
			if(root)
			{
				push(&stack, root);
				root= root->l;
				
				
			}
			else{ 
			if(isEmpty(stack))
				return;
			else if(!(top(stack)->r))
				{
					root = pop(&stack);
					printf("[%d]\t");
					
				
				if(top(stack)->r == root)
				{
					printf("[%d]\t",top(stack)->data);
					pop(&stack);
					
				}}
				
				
			
			
			if(isEmpty(stack))
				root =NULL;
			else
				root = top(stack)->r;
			
			}
			
		}
	
	
}




void printPostorder_II(struct BT *root)
{
	if(!root)
		return ;
	struct SLL *stack = inializeStack();
	do{
		
		while(root)
		{
			if(root->r)
				push(&stack,root->r);
			push(&stack,root);
			
			root = root->l;
			
		}
		
		root = pop(&stack);
		if(root->r &&top(stack)==root->r)
		{
			pop(&stack);
			push(&stack, root);
			root= root->r;
			
		}else
		{
			printf("[%d]\t",root->data);
			root = NULL;
		}
		
	}while(!isEmpty(stack));
	
	
}

//#===================Level orer traversal===============


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

void printRevLevelOrder(struct BT *root)
{
	if(!root)
		return;
	if(!root->l && !root->r)
	{
		printf("[%d]\t",root->data);
		return;	
	}
	
	struct SLL *s=inializeStack();
	struct Queue *q = initializeQ();
	NQ(q,root);
	while(!isEmptyQ(q))
	{
		root = DQ(q);
		push(&s,root);
		
		if(root->l)
			NQ(q,root->l);
		if(root->r)
			NQ(q,root->r);
		
		
		
	}
	
	while(!isEmpty(s))
	{
		printf("[%d]\t", pop(&s)->data);
	
	}
	
	
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
		printf("\nInorder:\n");
		printInorder(root);
		printf("\nInorder:\n");
		printInorder_I(root);
		printf("\nPreorder:\n");
		printPreorder(root);
		printf("\nPreorder:\n");
		printPreorder_I(root);
		printf("\nPostorder:\n");
		printPostorder(root);
		printf("\nPostorder:\n");
		printPostorder_II(root);
		printf("\nLevel order:\n");
		printLevelOrder(root);
		printf("\n Reve Level order:\n");
		printRevLevelOrder(root);
	
	return 0;
	}