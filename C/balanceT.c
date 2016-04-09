// Balance Checking

#include<stdio.h>
#include<stdlib.h>
struct BST
	{
	struct BST *l;
	struct BST *r;
	int data;
	
	};
	
int isBalanced(struct BST *root, int *h)
{
	int lh=0,rh=0,l=0,r=0;
	
	if(!root)
	{
		*h = 1;
		return 1;
	}
	l = isBalanced(root->l,&lh);
	r = isBalanced(root->r,&rh);
	
	if(lh>rh)
		*h = lh +1;
	else
		*h = rh +1;
	
	if((lh-rh)>1 || (rh-lh>1))
		return 0;
	return l&r;
	
}
	
struct BST *newNode(int data)
{
	
	struct BST *node = (struct BST *) malloc(sizeof(struct BST ));
	node ->l = node -> r = NULL;
	node->data = data;
	
}
	
	
	int main()
	{
		
		struct BST *root = newNode(1); 
		root->l = newNode(2);
		root->r= newNode(3);
		root->l->l = newNode(4);
		root->l->r = newNode(5);
		root->l->r->l = newNode(7);
		root->r->l = newNode(6);
		root->l->r->l->l = newNode(17);
		int h = 0;
		isBalanced(root, &h)?printf("Balanced\n\n"):printf("Not Balanced\n\n");
		
	}