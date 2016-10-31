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
# Problem Statement	: Mirror of N array Tree
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
	int data;
	vector<Node *> child;
	
	
};

struct Node *newNode(int data)
{
	struct Node *node =  new Node;
	node->data = data;
	return node;
	
}

void mirror( struct Node *root)
{
	
	if(!root)
		return;
	
	int n  =  root->child.size();
	
	if(n<2)
		return;
	for(int i=0; i<n; i++)
		mirror(root->child[i]);
	
	reverse(root->child.begin(), root->child.end());
}

void printTree(struct Node *root)
{
	if(!root)
			return;
	queue<struct Node *>q;

	q.push(root);
	
	while(!q.empty())
	{
		
		int n = q.size();
		
		while(n--)
		{
			
			struct Node  *node = q.front();
			q.pop();
			
			cout<< node->data<<" ";
			
			for(int i=0; i<node->child.size(); i++)
			{
				q.push(node->child[i]);
				
			}
			
			
			
		}	
		cout<<endl;
		
		
		
	}
	
	
}

int main()
{
	
	struct Node *root = newNode(10);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(56));
    (root->child).push_back(newNode(100));
    (root->child[2]->child).push_back(newNode(1));
    (root->child[3]->child).push_back(newNode(7));
    (root->child[3]->child).push_back(newNode(8));
    (root->child[3]->child).push_back(newNode(9));
 
	printTree(root);
	mirror(root);
	cout<<"Level Order Traversal"<<endl;
	printTree(root);
	
}