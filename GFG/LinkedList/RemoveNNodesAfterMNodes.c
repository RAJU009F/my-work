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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: remove N nodes after M nodes
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------
i
=======================
*/

struct Node
	{
		struct Node *next;
		int data;
	};

struct Node *newNode(int data)
{
	
	struct Node *node = (struct Node *)malloc(sizeof(struct Node) );
	node->data = data;
	node->next = NULL;
	
	return node;
	
}
	
void push(struct Node **head, int data)
{
	struct Node *node =  newNode(data);
	node->next = *head;
	*head = node;
	
	
	
}
	
void printList(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head =  head->next;
		
	}
	
	
}

void removeNNodesafterMNodes(struct Node **head, int m, int n)
{
	if(!(*head))
		return;
	struct Node *cur = *head;
	struct Node *temp=NULL;
	
	while(cur)
	{
		
		int count = 0;
		while(cur && count<m-1)
		{
			cur =  cur->next;
			count++;	
		}
		if(cur)
		{
			temp  = cur->next;
			count = 0;
			while(temp && count<n)
			{
				struct Node *dummy =  temp;
				temp = temp ->next;
				free(dummy);
				count++;
			}
			
		}else
			return;
		// if(temp)
			cur->next =  temp;
		cur =  cur->next;
		
	}
	
	
	
}
	
int main()
{
	struct Node *head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	push(&head, 9);
	push(&head, 10);
	
	printList(head);
	removeNNodesafterMNodes(&head, 2, 3);
	printf("\n\n");
	printList(head);
	

}	
	
