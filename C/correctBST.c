// correct the BST

#include<stdio.h>
#include<stdlib.h>

struct BT 
	{
	
	struct BT *l;
struct BT	*r;
	int data;
	
	};
	
struct BT *newnode(int data)
		{
			struct BT *node = (struct BT *) malloc(sizeof(struct BT));
			if(!node)
				return NULL;
			node->data = data;
				node ->l = node->r = NULL;
				
			return node;
		
		
		}
		
correctBSTUtil(struct BT *root, struct BT **f, struct BT **m, struct BT **l, struct BT **prev)
{
		if(root)	
		{
			correctBSTUtil(root->l, f, m ,l ,prev);
			
			if(*prev && root->data< (*prev)->data)
			{
				if(!*f) 
				{
					*f = *prev;
					*m = root;
				}else
				{
					
					*l = root;
				}
				
			}
			*prev = root;
			
			correctBSTUtil(root->r, f, m ,l ,prev);
			
		}
	
	
	
}
void swap(int *n, int *m)

{
	*n = *n ^ *m;
	*m = *n ^ *m;
	*n = *n ^ *m;
	
}
void correctBST(struct BT *root)
{
	struct BT *prev, *first, *last, *middle=NULL;
	prev = first =last = middle=NULL;
	correctBSTUtil(root, &first, &middle, &last , &prev);
	
	if(last && first)
			swap(&(first->data), &(last->data));
	else if(first && middle)
			swap(&(first->data), &(middle->data));
	
	
}

void printinorder(struct BT *root)
{
	if(!root)
			return;
	printinorder(root->l);
		printf("[%d]->",root->data);
	printinorder(root->r);	
	
	
}




int main()
		{
		
		struct BT *root = newnode(6);
		root->l = newnode(10);
		root->r =  newnode(2);
		root->l->l = newnode(1);
		root->l -> r = newnode(3);
		root->r->r = newnode(12);
		root->r -> l =newnode(7);
		printf(" BST Before correction :: \n");
		printinorder(root);
		correctBST(root);
		printf(" BST after correction :: \n");
		printinorder(root);
		}
	