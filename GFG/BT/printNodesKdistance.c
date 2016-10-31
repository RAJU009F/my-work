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
# Problem Statement	: print the nodes with k distance 
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
	struct Node  *r;
	int data;
};


struct Node *newNode(int data)
		{
			struct Node *node =  (struct Node *) malloc(sizeof(struct Node ));
			node->data =data;
			node->r = node->l = NULL;
			return node;		
		}
		
int targetNodeLevel(struct Node *root, struct Node *node, int level)
			{
				if(!root)
					return 0;
					
			if(root==node)
				return level;
			int lvl = targetNodeLevel(root->l, node, level+1);
			if(lvl>0)
				return lvl;
				
			return targetNodeLevel(root->r, node, level+1);
			
			}
		
void printNodeswithinKdistance(struct Node *root,  struct Node *node, int k)
	{
	
		if(!root)
			return;
			
		// find the target and its level

			// int nodeLevel = targetNodeLevel(root,  node, 1);
	
			
		// print nodes in level nodeLevel-k  i.e nodes above the node 

			// printNodeswithinKdistanceUtil(root, nodeLevel-k);
		
		// print nodes k level below from  given node
			// printNodeswithinKdistanceUtil(node, k);
	
	}
	
void printNodeswithinKdistanceUtil(struct Node *root, int k)
{
	if(!root)
			return;
		
		if(k==0)
		{
			printf("%d ", root->data);
			
			
		}
		
	printNodeswithinKdistanceUtil(root->l, k-1);
	printNodeswithinKdistanceUtil(root->r, k-1);
	
	
}	

bool printkNodesLCA(struct Node *root, struct Node *target, int k, int *i)
{
	if(!root)
		return false;
	
	if(root == target)
	{
		
		return true;}
	if(printkNodesLCA(root->l, target, k, i))
	{	
		(*i)++;
		if(k-(*i)>0)
			printNodeswithinKdistanceUtil(root->r, k-(*i)-1);
		if(*i == k)
			printf("%d", root->data);
		return true;
		
	}else if(printkNodesLCA(root->r, target, k, i))
	{
		(*i)++;
		if(k-(*i)>0)
			printNodeswithinKdistanceUtil(root->l, k-(*i)-1);
		if(*i == k)
			printf("%d", root->data);
		return true;
		
	}else
		return false;
	
	
	
	
}

	
int kDistanceNodes(struct Node *root,  struct Node *target, int k)
{
	if(!root)
		return -1;
	
	if(root==target)
	{
		printNodeswithinKdistanceUtil(target, k);
		return 0;
	}
	
	int dl  =  kDistanceNodes(root->l, target, k);
	
	if(dl !=-1)
	{
		if(dl+1 == k)
			printf("%d ", root->data);
		else
			printNodeswithinKdistanceUtil(root->r, k-dl-2);
		return dl+1;
	}
	
	int dr =  kDistanceNodes(root->r, target, k);
	
	if(dr != -1)
	{
		if(dr+1 == k)
			printf("%d ", root->data);
		else
			printNodeswithinKdistanceUtil(root->l, k-dr-2);
		
		return dr+1;
		
	}
	
	
	return -1;
}

		
int main()
{
	struct Node *root = newNode(1);
		root->l = newNode(2);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		
		root->r = newNode(3);
		root->r->l = newNode(6);
		root->r->l->r = newNode(8);
		root->r->r = newNode(7);
		
		kDistanceNodes(root, root->l->r, 2);
		int i =0 ;
		printkNodesLCA(root, root->l->r, 2, &i);
		
		
}