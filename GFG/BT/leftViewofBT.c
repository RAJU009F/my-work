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
# Topic or Type 	: GFG/BT
# Problem Statement	: Left view of BT / right view of tree
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
	
	
struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
	if(!node)
		return;
	node->l  =  NULL;
	node->r = NULL;
	node->data = data;
	
	return node;
	
}
void printLeftViewUtil(struct Node *root, int *maxlevel, int level)
{
	if(!root)
		return;
	
	if(*maxlevel < level)
	{
		printf("%d", root->data);
		(*maxlevel)++;
	}
	
	printLeftViewUtil(root->l, maxlevel, level+1);
	printLeftViewUtil(root->r, maxlevel, level+1);
}

void printRightViewUtil(struct Node *root, int *maxlevel, int level)
{
	if(!root)
		return;
	
	if(*maxlevel < level)
	{
		printf("%d", root->data);
		(*maxlevel)++;
	}
	
	printRightViewUtil(root->r, maxlevel, level+1);
	printRightViewUtil(root->l, maxlevel, level+1);
}
void printLeftView(struct Node *root)
{
	
	if(!root)
		return;
	
	int maxlevel  =0;
	
	printLeftViewUtil(root, &maxlevel, 1);
	
}

void printRightView(struct Node *root)	
{
	if(!root)
		return;
	int maxlevel = 0;
	printRightViewUtil(root, &maxlevel,  1);
	
}
	
int main()
		{
			struct Node *root = newNode(1);
			root->l =  newNode(2);
			root->r = newNode(3);
			root->l->l =  newNode(4);
			root->l->r =  newNode(5);
			root->r->l =  newNode(6);
			root->r->r =  newNode(7);
			
			printf("Left View:\n");
			printLeftView(root);
			printf("\nRight view :\n");
			printRightView(root);
			
		return 0;
		}