// import java.lang.*;
// import java.util.*;
// import java.io.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	:  linked list to bt
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

struct listNode
	{
		struct listNode *next;
		int data;		
	};
	
struct Node 
		{
		
			struct Node *l;
			struct Node *r;
			int data;
		
		};

void inorder(struct Node *root)
			{
				if(!root)
					return;
			inorder(root->l);
			cout<<root->data;
			inorder(root->r);	
			
			
			}
			
			
struct Node *newNode(int data)
{
	
	struct Node *node =  new Node;
	node->l = node->r = NULL;
	node->data = data;
	return node;
	
}
struct listNode *newListNode(int data)
{
	listNode *node =  new listNode;
	node->data = data;
	node->next = NULL;
	
	return node;
}

struct Node *listToBtUtil(struct listNode **head, int l, int h)
{
	if( !*head || l>h)
			return NULL;
	int m  = (h-l)/2+l;	
	struct Node *Left= listToBtUtil(head, l, m-1);	
	
	struct Node *root =  newNode((*head)->data);
	root->l = Left;
	
	*head = (*head)->next;
	root->r =  listToBtUtil(head, m+1, h);
	return root;
}

void listToBt(struct listNode **head, struct Node **root)
{
	
	int n =0; 
	listNode *cur =  *head;
	while(cur)
	{
		cur=cur->next;
		n++;
		
	}
	
	*root =  listToBtUtil(head, 0, n-1);
	
}
int main()
		{
			struct Node *root = NULL;;
			struct listNode *head =  newListNode(1);
			head->next =  newListNode(2);
			head->next->next = newListNode(3);
			head->next->next->next =  newListNode(4);
			head->next->next->next->next = newListNode(5);
			listToBt(&head, &root);
			inorder(root); 
		}