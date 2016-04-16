#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stack
# Problem Statement	: Stack implement using Linkedlist
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
	struct SLL *node =(struct SLL *) malloc(sizeof(struct SLL));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	
	return node;
}

int isEmpty(struct SLL *s)
{
	return s==NULL;
}
void push(struct SLL **s, int data)
{
	struct SLL *temp= newNode(data);
	temp->next =*s;
	*s = temp;
}
int pop(struct SLL **s)
{
	if(isEmpty(s))
		return -1;
	int data;
	struct SLL *temp =*s;
	*s=*s->next;
	data=temp->data;
	free(temp);
	
	return data;
	
	
}

int Top(struct SLL *s)
{
	
	if(isEmpty(s))
		return -1;
	else
		return s->data;
	
	
}

int main()
	{
	
	struct SLL *top = NULL;
		push(&top,1);
		push(&top,2);
		printf("[%d]\n",pop(top));
		push(&top, 3);
		push(&top,4);
		printf("[%d]\n",Top(top));
	return 0;
	}