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
# Topic or Type 	: GFG/BT
# Problem Statement	:   construct the Ancestor matrix 
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
			struct Node *node  =  new Node;
			node->data = data;
			node->l = NULL;
			node->r = NULL;
		
		}
		
int countNodes(struct Node *root)
{
	if(!root)
		return 0;
	
	return countNodes(root->l)+1+countNodes(root->r);
	
	
	
}

void printAncestorMatrixUtil(struct Node *root, int mat[][], vector<int> ans)
{
	
	if(!root)
			return;
		
	int data =  root->data;

	for(int i=0 ;i<ans.size(); i++)
			mat[ans[i]][data] = 1;
		ans.push_back(data);
		printAncestorMatrixUtil(root->l, mat, ans);
		printAncestorMatrixUtil(root->r, mat, ans);
		ans.pop_back();
	
	
}

void printAncestorMatrix(struct Node *root)
	{
		if(!root)
			return;
		int n = countNodes(root);
		
		int mat[n][n];
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n ; j++)
			{
			mat[i][j] = 0;
				
			}

			
		}
		
		vector<int> ans;
		
		printAncestorMatrixUtil(root, mat, ans);
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n ; j++)
			{
			cout<<mat[i][j] << " ";
				
			}
			cout<<endl;
			
		}
		
	
	}
		
int main()
			{
			
				struct Node *root  =  newNode(5);
				root->l =  newNode(1);
				 root->l->l =  newNode(0);
				 root->l->r  =  newNode(4);
				 root->r = newNode(2);
				 root->r->l = newNode(5);
				
				printAncestorMatrix(root);
			
			
			}