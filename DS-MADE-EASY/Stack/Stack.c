#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stack
# Problem Statement	: stack implementation using arrays
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct Stack
{
	int size;
	int top;
	int *arr;
};

struct Stack *initStack(int size)
{
	struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
	if(!s)
			return NULL;
	s->size = size;
	s->top = -1;
	s->arr = (int *)malloc(sizeof(int)*size);
	
	return s;
	
	
}

int isEmpty(struct Stack *s)
{
	
	return s->top==-1;
	
}
int isFull(struct Stack *s)
{
	return s->top==s->size-1;
	
}

void doubleStack(struct Stack *s)
{
	s->size *=2;
	s->arr=realloc(s->arr, s->size);
	
}

void push(struct Stack *s, int data)
{
	
	if(isFull(s))
	{
		printf("stack overflow\n");
		doubleStack(s);
	}
		s->arr[++s->top] = data;
	
		
}

int pop(struct Stack *s)
{
	if(!isEmpty(s))
		return s->arr[s->top--];
	else
		
		{
			printf("stack underflow\n");
			return -1;
		}
	
}

int Top(struct Stack *s)
{
	if(isEmpty(s))
		return INT_MAX;
	return s->arr[s->top];
}

int main()
	{
		struct Stack *S = initStack(1);
		int i;
		for(i=0;i<10;i++)
		{push(S,i);
		
		printf("[%d]\n",S->arr[S->top]);
			}
			
		for(i=0;i<10;i++)
		{
			int data= pop(S);
			printf("[%d]\n",data);
			
			
		}
	
	return 0;
	}