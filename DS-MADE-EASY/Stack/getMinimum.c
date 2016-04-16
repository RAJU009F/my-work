#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stacks
# Problem Statement	: 
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
	int min;
	struct SLL *next;
};

int isEmpty(struct SLL *s)
{
	return s==NULL;
	
}
struct SLL *newNode(int data)
{
	
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));
	if(!node)
			return NULL;
		node->next = NULL;
		node->data = data;
		node->min = data;
	
	return node;
	
}

void push(struct SLL **s, int data)
{
	struct SLL *node = newNode(data);
	node->next = *s;
	*s = node;
	if( (*s)->next && (*s)->min>node->next->min)
			(*s)->min = node->next->min;

	
}

int pop(struct SLL **s)
{
	
	struct SLL *node=*s;
	int data = node->data;
	*s = node->next;
	free(node);
	return data;
	
}

int getMin(struct SLL *s)
{
	if(!isEmpty(s))
		return s->min;
	else
		return INT_MIN;
}

void printStack(struct SLL *s)
{
	while(s)
	{
		printf("[%d]\t[%d]\n",s->data, s->min);
		s = s->next;
	}
	
	
}
int main()
	{
		struct SLL *top = NULL;
		push(&top, 100);
		push(&top,40);
		push(&top,2);
		push(&top, 3);
		push(&top, 7);
		push(&top,1);
		push(&top,0);
		push(&top,9);
		push(&top,2);
		printf("nsfknsd");
	printStack(top);
		
	
	return 0;
	}
	