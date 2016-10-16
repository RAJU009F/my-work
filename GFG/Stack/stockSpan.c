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
# Problem Statement	: Stock span problem
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


int top(struct stack **s)
{
	
	if(isEmpty(*s))
		return -1;
	return (*s)->data;
	
}

void printArray(int arr[],  int n)
{
	printf("\n");
	int i;
	for(i=0; i<n ; i++)
		printf("%d ", arr[i]);
	
}

void calculateSP(int price[], int n ,int S[])
{
	S[0 ] = 1;
	
	struct stack *s = NULL;
	push(&s, 0);
	int i;
	for(i=0; i<n; i++)
	{
		while(!isEmpty(s) && price[top(&s)]<=price[i])
			pop(&s);
		
		S[i] = isEmpty(s)?i+1:i-top(&s);
		
		push(&s, i);
	}
	
}
int main()
{
	int price[] = {10, 4, 5, 90, 120, 80};
	int n  =  sizeof(price)/sizeof(price[0]);
	int S[n];
	calculateSP(price, n, S);
	
	printArray(S, n);
	
	
}