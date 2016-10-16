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
# Problem Statement	: Merge Sort
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

struct BT 
{
	struct BT *l;
	int data;
	struct BT *r;
	
};

struct Node *newNode(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
	node->data = data;
	node->next = NULL;
	return node;
	
}

void push(struct Node **head,  int data)
{
	struct Node *node =  newNode(data);
	node->next =  *head;
	*head =  node;
	

}

struct BT *LinkedListToBSTUTIL(struct Node **head,  int l, int r)
{
		if(l>r)
			return NULL;
		int mid =  l+(r-l)/2;
		struct BT *left =  LinkedListToBSTUTIL(head, l, mid-1);
		struct BT *root =  (struct BT *) (malloc(sizeof(struct BT )));
		
		root->data =  (*head)->data;
		root->l = left;
		
		*head = (*head)->next;
	
		root->r =  LinkedListToBSTUTIL(head,  mid+1,  r);
		
		return root;
}

struct BT *LinkedListToBST(struct Node **head)
{
	
	return LinkedListToBSTUTIL(head, 0,  9);
}


void inorder(struct BT *root)
{
	if(!root)
			return;
	inorder(root->l);
	printf("%d ", root->data);
	inorder(root->r);
	
}

int main()
{
	struct Node *head = NULL;
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	struct BT *root = LinkedListToBST(&head);
	
	inorder(root);
	
	
}
