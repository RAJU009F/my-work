#include<stdio.h>
#include<stdlib.h>

struct BT 
	{
	struct BT *r;
	struct BT *l;
	int data;
	
	};
	
	
struct BT *newnode(int data)
		{
			
			struct BT *node = (struct BT *) malloc(sizeof(struct BT));
			node->data = data;
			node->l = node->r = NULL;
		
		return node;
		}
removeBT(struct BT *root, int min ,int max)
		{
			if(!root)
				return NULL;
				
			root->l = removeBT(root->l, min, max);
			root->r = removeBT(root->r, min, max);
			
			if(root->data> max)
				{
					struct BT *lchild = root->l;
					free(root);
					return lchild;
				
				}
		if(root->data < min)
			{
			
			struct BT *rchild = root->r;
			free(root);
			return rchild;
			
			}
		return root;
		
		
		}
struct BT *insert(struct BT *root, int data)
			{
				if(!root)
				{return newnode(data);
				
				}
				if(root->data >data)
					root->l = insert(root->l, data);
			else
					root->r = insert(root->r, data);
			
			
			return root;
			
			}
void inorder(struct BT *root)
{
	
	if(!root)
			return;
	inorder(root->l);
	printf("[%d]\t",root->data);
	inorder(root->r);	
	
	
}

void modifyBST(struct BT *root, int *pos)
{
	if(!root)
			return;
	modifyBST(root->l, pos);
	*pos = *pos + root->data;
	root->data = *pos;
	modifyBST(root->r, pos);
	
	
	
}

int main()
		{
		
		struct BT *root = NULL;
		
		   root = insert(root, 6);
		   printf("%d",root->data);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
	
	printf("Before Inorder of Tree:\n");
	inorder(root);
	removeBT(root, -10,13);
	printf("\n\nAfter remove Inorder of Tree:\n\n");
	inorder(root);
	int sum =0 ;
	modifyBST(root, &sum);	
	printf("After modify:\n");
	inorder(root);
		}