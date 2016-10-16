// # import java.io.*;
// # import java.lang.*;
// # import java.util.*;

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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: Dtect loop  and  remove
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


struct Node 
{
	
	struct Node *next;
	int data;
};

struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
	if(!node)
			return;
		
		 node->data =  data;
		 node -> next = NULL;
		 
	return node;	 
		
}


void push(struct Node **head, int data)
{
		struct Node *node =  newNode(data);
		
	
}

void detectAndRemoveLoop(struct Node *head)
{
	
	struct Node *sp = head;
	struct Node *fp = head;
	
	while(fp && fp->next)
	{
		fp = fp->next;
		if(fp == sp)
			break;
		fp = fp->next;
		sp = sp->next;
		
	}
	
	if(fp == sp)
	{
		sp =  head;
		
		while(sp != fp->next)
		{
			sp = sp ->next;
			fp =  fp->next;			
		}
		
		
		fp->next = NULL;
		
	}
	
	
}
void printlist(struct Node *head)
{
	if(!head)
		return;
	
	while(head)
	{
		
		printf("%d ", head->data);
		head =  head->next;
	}
	
	
}

int main()
{
	
	struct Node *head =  NULL;
	head =  newNode(10);
	head->next =  newNode(20);
	head->next->next = newNode(30);
	head->next->next->next =  newNode(40);
	head->next->next->next->next  =  newNode(5);
	head->next->next->next->next->next  = newNode(7);
	head->next->next->next->next->next->next   = newNode(78);
	
	head->next->next->next->next->next->next->next= head->next->next;
	
	detectAndRemoveLoop(head);
	
	printlist(head);
}