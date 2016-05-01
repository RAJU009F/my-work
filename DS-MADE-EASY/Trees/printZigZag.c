#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: print Zig zig level order
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



struct SLL {
	
	struct BT *data;
	struct SLL *next;
	
};



struct SLL *inializeStack()
{
	struct SLL *s =  (struct SLL *) malloc(sizeof(struct SLL));
	if(!s)
			return NULL;
	//struct BT *node  = (struct BT *)malloc(sizeof(struct BT));
	s->next = NULL;	
	//s->data = (struct BT *)malloc(sizeof(struct BT));
		//if(!s->data)
		//	return NULL;
	s->data = NULL;
	//if(!s->data)
		//	return NULL;
	
	return NULL;
}



struct SLL *newNodeS(struct BT *data)	
{
	struct SLL *node =  (struct SLL *)malloc(sizeof(struct SLL));
		
		node->data =data;
		node->next = NULL;
		
		return node;
	
}

int isEmpty(struct SLL *s)
{
	return s==NULL;

}
void push(struct SLL **s, struct BT *data)
{
	
	struct SLL *node =  newNodeS(data);
	node->next = *s;
	*s = node;
	
}

struct BT *pop(struct SLL **s)
{
	if(isEmpty(*s))
			return NULL;
	else
	{struct SLL *temp = *s;
		*s = (*s)->next;
		struct BT *data = temp->data;
		free(temp);
		return data;
	}
	
}
void printS(struct SLL *s)
{
	while(s)
	{
		printf("[%d]", s->data->data);
		s= s->next;
		
	} 
	
}
/*
struct SLL
{
	struct BT *data;
	struct SLL *next;
	
	
};



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
	
} */
void printZigZag(struct BT *root)
{
	if(!root)
			return;
	struct SLL *stack1 =  inializeStack();
	struct SLL *stack2 = inializeStack();
	
	push(&stack1,root);
		while(!isEmpty(stack1) || !isEmpty(stack2))
		{
			while(!isEmpty(stack1))
			{
				//printf(" fslflsm " );
				root =  pop(&stack1);
				printf("[%d]\t",root->data);
				if(root->l)
					push(&stack2,root->l);
				if(root->r)
						push(&stack2, root->r);
				//printS(stack2);
				
			}
			//printf("dsdsd");
			printf("\n");
			//printf("dsdsd");
			while( !isEmpty(stack2))
			{
				//printf("dsdsd");
				root =  pop(&stack2);
				printf("[%d]\t", root->data);
				if(root->r)
					push(&stack1, root->r);
				if(root->l)
					push(&stack1, root->l);
			}
			printf("\n");
		}
	
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
		printZigZag(root);
	
	return 0;
	}