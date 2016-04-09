// BST solutions for GFG
#include<stdio.h>
#include<stdlib.h>
struct BST	
	{
	
	int data;
	struct BST *l;
	struct BST *r;
	
	};

void findCommon(struct BST *root1, struct BST *root2)
{
	if(!root1 && !root2)
			return ;
	if (!root1 || !root2)
			return;

	findCommon(root1->l, root2->l);
		if(root1->data == root2->data)
			printf("%d",root1->data);
	findCommon(root1->r, root2->r);
	
	
}

struct BST *createNode(int data)
{
	
	struct BST *node = ( struct BST *)malloc(sizeof(struct BST));
	if(!node)
		return NULL;
		node->l = node->r=NULL;
		node->data = data;
		
	return node;
}
	
struct BST *insert(struct BST *root, int data)
{
	if(!root)
			return createNode(data);
	if(root->data >data)
			root->l = insert(root->l, data);
	else
			root->r = insert(root->r, data);
	
	
	return root;
	
}
void inorder(struct BST *root)
{
	if(!root)
		return;
	inorder(root->l);
	printf("\t[%d]",root->data);
	inorder(root->r);
	
	
}
int main()
		{
		
		struct BST *root1= NULL;
		 root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);
		struct BST *root2= NULL;
		  root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
		
		inorder(root1);
		printf("\n");
		inorder(root2);
		printf("\n");
		findCommon(root1, root2);
		}
		
		