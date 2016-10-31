// import java.lang.*;
// import java.util.*;
// import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	:   Circular DLL from BT
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

struct Node 
	{
		struct Node *l;
		struct Node *r;
		int data;
	
	};
	
struct  Node *newNode(int data)
		{
			struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
			node->l = node->r = NULL;
			node->data = data;
			
			return node;
		
		}
	
void printCDLL(struct Node *head)
		{
			struct Node *cur = head;
			
			while(cur->r != head)
			{
				printf("%d ", cur->data);
				cur  = cur->r;
				
			}
		}
void BTtoCDLL(struct Node *root, struct Node **head, struct Node  **prev)
		{
			if(!root)
				return;
				
			BTtoCDLL(root->l, head, prev);
				
			if(!*head)	
				{
					*head = root;
					*prev = root;
				}
				
			else
				{
					root->l = *prev;
					(*prev)->r = root;
				}
				*prev  = root;
				
			BTtoCDLL(root->r, head, prev);	
			
		
		}
	
int main()
		{
		
			struct Node *root =  newNode(4);
			root->l = newNode(2);
			root->l->l = newNode(1);
			root->l->r  = newNode(3);
			root->r = newNode(6);
			root->r->l = newNode(5);
			root->r->r  = newNode(7);
			struct Node *head = NULL;
			struct Node *prev = NULL;
			
			BTtoCDLL(root, &head, &prev);
			prev->r = head;
			head->l = prev;
			printCDLL(head);
			
		}