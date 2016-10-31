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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: find the height of the tree given their indexs
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
	struct Node *node =  (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->l = node->r = NULL;
	
	return node;
	
	
	
}
	
void serializeTree(struct Node *root, FILE *fp)
		{
			if(!root)
				{
					fprintf(fp, "%d", -1);
					return;
					
				}
			fprintf(fp, "%d", root->data);
			serializeTree(root->l, fp);
			serializeTree(root->r, fp);
		
		
		}

void deserializeTree(struct Node **root, FILE *fp)
{
		int val;
	if(! fscanf(fp, "%d", &val) || val == -1)
	{
		return;
		
	}
	
	*root = newNode(val);
	deserializeTree(&((*root)->l), fp);
	deserializeTree(&((*root)->r), fp);
	
	
}

void inorder(struct Node *root)
{
	if(!root)
		return;
	
	inorder(root->l);
	printf("%d ", root->data);
	inorder(root->r);
	
	
	
}

		
int  main()
		{
			struct Node *root = newNode(1);
			root->l  =  newNode(2);
			root->r  =  newNode(3);
			root->l->l =  newNode(4);
			root->l->r = newNode(5);
			root->r->l=  newNode(6);
			root->r->r = newNode(7);
			
			FILE *fp  = fopen("tree.txt", "w");
			
			serializeTree(root, fp);
			fclose(fp);
			struct Node *root1 = NULL;
			FILE *fp1 = fopen("tree.txt", "r");
			
			deserializeTree(&root1, fp1);
			fclose(fp1);	
			inorder(root1);
			
		
		}