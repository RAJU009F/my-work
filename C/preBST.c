#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


struct BT {
	struct BT *l;
	struct BT *r;
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
		
void printinorder(struct BT *root)
{
	if(!root)
			return;
	printinorder(root->l);
		printf("[%d]->",root->data);
	printinorder(root->r);	
	
	
}
		


struct BT *createBSTutil(int pre[], int *preindex, int key, int min, int max , int size)
	{
	
	if(*preindex>=size)
		return NULL;
	
		struct BT *root=NULL;
	if(key>min && key<max)
	{
		root = newnode(key);
	*preindex = *preindex +1;
	
	if(*preindex < size)
	{
		root->l = createBSTutil(pre, preindex, pre[*preindex], min, key, size);
		
		root->r = createBSTutil(pre, preindex, pre[*preindex],  key, max, size);
		
	}
		
		
	}
	
	
	return root;
	
	}
struct BT *createBST(int pre[], int size)
	{
	
		int preindex=0;
		return createBSTutil(pre, &preindex, pre[0], INT_MIN, INT_MAX, size);
		
	
	
	}


int main()
	{
		int pre[] =  {10, 5, 1, 7, 40, 50};
		
		struct BT *root=createBST(pre, sizeof(pre)/sizeof(pre[0]));
	
	printinorder(root);
	
	}