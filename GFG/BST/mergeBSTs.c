// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BST
# Problem Statement	: Java: Merge two BSTs 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
struct BT
{
	int data;
	struct BT *l;
	struct BT *r;	
};

struct Stack{
	
	struct BT *data;
	struct Stack *next;
	
};

struct Stack *createS()
{
	struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
	if(!s)
		return;
	s->data = NULL;
	s->next = NULL;
	
	return s;
}

struct Stack *newNode(struct BT *data)
{
	struct Stack *node =  (struct Stack *) malloc(sizeof(struct Stack));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	
	return node;
}


void push(struct Stack **s,  struct BT *data)
{
	struct Stack *temp = newNode(data);
	if(!(*s))
	{
		
		
		*s = temp;
	}else
	{
		temp->next = *s;
		*s = temp;
	}
	
	
}

bool isEmpty(struct Stack *s)
{
	return s == NULL;
}

struct BT  *pop(struct Stack **s)
{
	if(isEmpty(*s))
		return NULL;
	struct BT *data = (*s)->data;
	struct Stack *t = *s;
	*s = (*s)->next;
	
	free(t);
	return data;	
}


void inorder(struct BT *root)
{
	printf("\ninorder called");
	if(root)
	{
		inorder(root->l);
		printf("%d\t", root->data);
		inorder(root->r);
		
	}
	
	
}

void mergeTrees(struct BT *root1, struct BT *root2)
{
	if(!root1 && !root2)
		return;
	
	if(!root1)
	{
		inorder(root2);
		return;	
	}
	
	if(!root2)
	{
		inorder(root1);
		return;		
	}
	
	struct Stack *s1 = createS();
	struct Stack *s2 = createS();
	
	while(!isEmpty(s1) || !isEmpty(s2) || root1 || root2)
	{
		
		if(root1 || root2)
		{
			if(root1)
			{
				push(&s1, root1);
				root1 = root1->l;
				
			}
			if(root2)
			{
				push(&s2, root2);
				if(root2->data == 6)
					printf("6");
				root2 = root2->l;
				
			}
			
			
			
		}else
		{
			if(isEmpty(s1))
			{
				printf("kkk");
				while(!isEmpty(s2));
				{
					root2 = pop(&s2);
					root2->l = NULL;
					inorder(root2);
				}
				return;
			}
			
			if(isEmpty(s2))
			{
				while(!isEmpty(s1));
				{
					root1 = pop(&s1);
					root1->l = NULL;
					inorder(root1);
				}
				return;
			}
			
			
			root1  =  pop(&s1);
			root2 = pop(&s2);
			
			if(root2->data > root1->data)
			{
				printf("%d ", root1->data);
				root1 = root1->r;
				//printf("sdsd");
				push(&s2, root2);
				//printf("sdsd");
				root2 = NULL;
				
			}else
			{
				printf("%d ", root2->data);
				root2 = root2->r;
				push(&s1, root1);
				root1 = NULL;
				
				
			}
				
			
			
			
		}
		
		
		
		
		
	}
	
	
	
	
}

struct BT *newNodeT(int data)
{
	struct BT *node  =  (struct BT *) malloc(sizeof(struct BT));
	node -> data = data;
	node -> l = node->r = NULL;
	
	return node;
	
	
}

int main()

{
	struct BT *root1 = NULL;
	struct BT *root2 = NULL;
	
	root1 = newNodeT(3);
	root1->l = newNodeT(1);
	root1->r = newNodeT(5);
	
	
	root2 = newNodeT(4);
	root2->l = newNodeT(2);
	root2->r = newNodeT(6);
	
	mergeTrees(root1, root2);
	
	return 0;
}