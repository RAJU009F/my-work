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
	int data;
	struct stack *next;
	
};

struct stack *newNode(int data)
{
	struct stack *node =  (struct stack *) malloc(sizeof(struct stack));
	if(!node)
		return NULL;
	node->data =data;
	node->next = NULL;
	
	return node;
	
}

bool isEmpty(struct stack *s)
{
	return s==NULL;
}
void push(struct stack **s, int data)
{
	if(isEmpty(*s))
	{
		*s = newNode(data);
		
	}else{
		struct stack *t = newNode(data);
		t->next = *s;
		*s = t;
		
	}
	
}

int pop(struct stack **s)
{
	if(isEmpty(*s))
		return -1;
	struct stack *node = *s;
	*s = node->next;
	int d = node->data;
	free(node);
	return d;
	
	
}

void nextGreaterElemnts(int arr[],  int n)
{
	
	struct stack *s =NULL;
	
	if(n<=0)
		return;
	
	push(&s, arr[0]);
	int i, element, next;
	for(i=1; i<n; i++)
	{
		next = arr[i];
		if(!isEmpty(s))
		{
			element = pop(&s);
			while(element<next)
			{
				
				printf("%d ==> %d\n", element, next);
				if(isEmpty(s))
					break;
					element = pop(&s);
				
				
			}
			
			
			if(element>next)
				push(&s,element );
			
			
		}
		
		push(&s, next);
		
		
	}
	
	
	while(!isEmpty(s))
		printf("%d==>%d\n",pop(&s), -1);
	
}


int main()
{
	
	int arr[] = {11, 13, 21, 3};
	nextGreaterElemnts(arr, sizeof(arr)/sizeof(arr[0]));	
	return 0;
}