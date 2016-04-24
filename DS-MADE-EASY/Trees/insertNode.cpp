#include<iostream>
#include<queue>
using namespace std;
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct BT
{
	struct BT *l;
	int data;
	struct BT *r;
};

// create a BT Node

struct BT *newNode(int data)
{
		struct BT *node = new BT;
		if(!node)
			return node;
		
		node ->data = data;
		node ->l = node->r = NULL;
		
	return node;	
}

void insertNode(struct BT **rt, int data)
{
	if(!*rt)
	{
		*rt = newNode(data);
		return;
	}
	queue<struct BT *> q;
	
	q.push(*rt);
	struct BT *root = *rt;
	while(q.empty())
	{
		root = q.front();
		q.pop();
		
		if(root->l)
		 q.push(root->l);
		else
		{
			root->l = newNode(data);
			return;
		}
		if(root->r)
			q.push(root->r);
		else
		{
			root->r = newNode(data);
			return;
			
		}
		
		
		
	}
	
	
	
}
void printPreOrder(struct BT *root)
{
	if(root)
	{
		cout<<"["<<root->data<<"]\t";
		printPreOrder(root->l);
		printPreOrder(root->r);
		
	}
	
}

int main()
	{
		struct BT *root = newNode(0);
		insertNode(&root, 1);
		insertNode(&root, 2);
		insertNode(&root, 3);
		insertNode(&root, 4);
		insertNode(&root, 5);
		insertNode(&root, 6);
		printPreOrder(root);
	return 0;
	}