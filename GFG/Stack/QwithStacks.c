// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: implement Q with stacks
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct stack 
{
	struct stack *next;
	int data;
	
};

struct stack *createStack()
{
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));
	if(!s)
		return NULL;
	s->next = NULL;
	
	return s;
	
}

bool isEmpty(struct stack *s)
{
	
	return s==NULL;
}

struct stack *newNode(int data)
{
	struct stack *node =  (struct stack *) malloc(sizeof(struct stack));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	
	return node;
}

void push(struct stack **s, int data)
{
	if(!*s)
		*s = newNode(data);
	else
	{
		struct stack *t = newNode(data);
		t->next = *s;
		*s = t;
	}
	
	
}

int pop(struct stack **s)
{
	if(isEmpty(*s))
	{
		printf("Empty\n");
		return -1;
	}
	
	struct stack *t = *s;
	*s = t->next;
	int data = t->data;
	
	free(t);
	return data;
	
}



void NQ(struct stack **s1, struct stack **s2, int data)
{
	push(s1, data);
	
	
}
int DQ(struct stack **s1, struct stack **s2)
{
	//printf("DQ");
	if(isEmpty(*s1))
	{
		printf("Q is Empty\n");
		return -1;
		
	}
	if(!isEmpty(*s1))
	{
		while(!isEmpty(*s1))
		{
			
			push(s2, pop(s1));
			
		}
		
	}
	
	int data =   pop(s2);
	while(!isEmpty(*s2))
	{
		push(s1, pop(s2));
	}
	
	return data;
	
}
implementQ()
{
	struct stack *s1 = NULL;// createStack();
	struct stack *s2 = NULL;//createStack();
	NQ(&s1, &s2, 1);
	NQ(&s1, &s2, 2);
	NQ(&s1, &s2, 3);
	
	printf("%d\n", DQ(&s1, &s2));
		printf("%d\n", DQ(&s1, &s2));
		NQ(&s1, &s2, 100);
		NQ(&s1, &s2, 200);
		NQ(&s1, &s2, 300);
	printf("%d\n", DQ(&s1, &s2));
	printf("%d\n", DQ(&s1, &s2));
	NQ(&s1, &s2, 900);
	printf("%d\n", DQ(&s1, &s2));
		printf("%d\n", DQ(&s1, &s2));
	printf("%d\n", DQ(&s1, &s2));
	
}



int main()
{
	
	implementQ();
	//implementQwithSingleStack();
	

	return 0;
}
