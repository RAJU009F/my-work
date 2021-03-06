#include<iostream>
#include<queue>
using namespace std;
/*

# Author			: @RAJ009F
# Topic or Type 	: Trees
# Problem Statement	: max node in a tree
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
		struct BT *node = new BT;//(struct BT *)malloc(sizeof(struct BT));
		
		node ->data = data;
		node ->l = node->r = NULL;
		
	return node;	
}

void printMaxNode(struct BT *root)
{
	if(!root)
		return;
	
	queue<struct BT *> q;
	q.push(root);
	int max =0;
	
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		if(root->data>max)
			max = root->data;
		
		if(root->l)
			q.push(root->l);
		if(root->r)
			q.push(root->r);
		
		
		
	}
	
	cout<<"max node:"<<max;
}


int main()
	{
		struct BT *root = NULL;
		
		root = newNode(1);
		root->l = newNode(2);
		root->r = newNode(3);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		root->r->l = newNode(6);
		root->r->r = newNode(7);
		root->l->r->l = newNode(33);
		root->l->r->r = newNode(46);
		root->r->r->l = newNode(63);
		root->r->r->r = newNode(65);
		printMaxNode(root);
	
	return 0;
	}