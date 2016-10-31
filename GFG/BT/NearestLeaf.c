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
# Problem Statement	: find the nearest leaf node
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
	struct Node *r;
	struct Node *l;
	char data;
};

struct Node *newNode(char data)
	{
		struct Node *node =  (struct Node *) malloc(sizeof(struct Node));
		node->data =  data;
		node->l = node->r = NULL;
		
		return NULL;
	
	}
	
void findDist(struct Node *root, struct Node **leaf,  int level,  int *dist)
	{
		if(!root)
			return;
		if(!root->l && !root->r)
			{
				if(level < *dist)
					{
						*dist = level;
						*leaf = root;
					}
			return;
			}
		else
			{
				findDist(root->l, leaf, level+1, dist );
				findDist(root->r, leaf, level+1, dist);
			
			}
	
	}
bool nearestLeafofUtil(struct Node *root, char key, struct Node **leaf, int *dist, int *min)
	
	
	{
		if(!root)
			return false;
		if(root->data == key)
			{
			if(!*leaf)
				findDist(root, leaf, 0, min );
			return true;
			}
			
		else if(nearestLeafofUtil(root->l, key, leaf, dist, min))
		{
			*dist = *dist +1;
			struct Node *rleaf = NULL;
			int rmin = 0;
			findDist(root->l, &rleaf, *dist+1, min);
			if(rmin<*min)
				{*leaf = rleaf;
					*min =  rmin;
				}
			return true;
		}else if (nearestLeafofUtil(root->r, key, leaf, dist, min))
			{
				*dist = *dist +1;
			struct Node *rleaf = NULL;
			int rmin = 0;
			findDist(root->r,&rleaf, *dist+1, min);
			if(rmin<*min)
				{*leaf = rleaf;
					*min =  rmin;
				}
			
			return true;
			
			}else
			return false;
		
	
	}
	
void nearestLeafof(struct Node *root, char key)
		{
			if(!root)
				return;
		struct Node *leaf =  NULL;
		int dist = 0;
		int min = 0;
		nearestLeafofUtil(root, key,  &leaf, &dist, &min);
		
		if(leaf)
			printf("Nearest Leaf: %d,  dist : %d", leaf->data, dist);
		
		
		
		
		}

int main()
	{
	struct Node *root        = newNode('A');
    root->l              = newNode('B');
    root->r              = newNode('C');
    root->r->l       = newNode('E');
    root->r->r       = newNode('F');
    root->r->l->l = newNode('G');
    root->r->l->l->l = newNode('I');
    root->r->l->l->r = newNode('J');
    root->r->r->r      = newNode('H');
    root->r->r->r->l= newNode('K');
	
	nearestLeafof(root, 'H');
	
	}
