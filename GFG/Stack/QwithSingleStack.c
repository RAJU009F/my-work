// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include<stdbool.h>
 #include<limits.h>

// # // #include<iostream>
// # // #include<algorithm>
// # // #include<string>
// # // #include<vector>
// # // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: Q with single Stack
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/ 
struct stack 
{
	struct stack *next;
	int data;
	
};



bool isEmpty(struct stack *s)
{
	
	return s==NULL;
}

struct stack *newNode(int data)
{
	struct stack *node = (struct stack *)malloc(sizeof(struct stack));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	
	return node;
}
void push(struct stack **s, int data)
{
	if(isEmpty(*s))
	{
		*s = newNode(data);
		return;
	}
	
	struct stack *t =  newNode(data);
	t->next = *s;
	*s = t;
	
}
int pop(struct stack **s)
{
	if(isEmpty(*s))
		return -1;
	struct stack *t= *s;
	*s = t->next;
	int d = t->data;
	free(s);
	return d;
	
}

void insertAtBottom(struct stack **s, int data)
{
	if(isEmpty(*s))
	{ push(s, data);
		return;}
	int d =  pop(s);
	insertAtBottom(s, data);
	push(s, d);
	
}

void reverse(struct stack **s)
{
	if(isEmpty(*s))
		return;
	int d  = pop(s);
	reverse(s);
	insertAtBottom(s, d);
	
}

int DQ(struct stack **s)
{
	if(isEmpty(*s))
		return -1;
	// step-1 reverse stack
	reverse(s);
	//step-2 pop top element
	int d = pop(s);
	// step-3 reverse stack
	reverse(s);
	
	return d;
	
}
void NQ(struct stack **s, int data)
{
	push(s, data);
	
}
void implementQ()
{
	struct stack *s = NULL;
	NQ(&s, 1);
	NQ(&s, 2);
	NQ(&s, 3);
	printf("%d", DQ(&s));	
	NQ(&s, 4);
	printf("%d", DQ(&s));	
	printf("%d", DQ(&s));	
	printf("%d", DQ(&s));	
	
	
}
int main()
{

implementQ();	

return 0;
}