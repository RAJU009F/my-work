#include<stdio.h>
#include<stdlib.h>
struct BT
	{
		struct BT *l;
		struct BT *r;
		int data;
	};
struct BT *makeTree(int *, int *, int, int);
void inorder(struct BT *);
void preorder(struct BT *);
struct BT *newnode(int );	
int main()
{
int pre[] = {5,3,6,2,7,1,4,8,9};
int in[] = {1,2,3,4,5,6,7,8,9};

struct BT *root = makeTree(in, pre, 0, sizeof(pre)/sizeof(pre[0]));

printf("\t====inordeer====\n");
inorder(root);
printf("\t====preordeer====\n");
preorder(root);

return 0;
}	
struct BT *newnode(int data)
	{
		struct BT *newNode = (struct BT *)malloc(sizeof(struct BT));
		if(!newNode)
			{
				return NULL;
			}
		newNode -> data = data;
		newNode -> l = newNode -> r = NULL;
	return newNode;
	}
	
int search(int in[], int l, int h, int data)
		{
		int i=l;
	for(i=l;i<h;i++)
		{
			if(in[i] == data)
				return i;
		}
		
		
		}
struct BT *makeTree(int in[], int pre[], int st, int end)
	{
		static int preindex = 0;
		
		if(st>end)
			return NULL;
		struct BT *newNode = newnode(pre[preindex]);	
	++preindex;
	
	if(st == end)
		{
		
		return newNode;
		
		}
		
	
	int inindex = search(in, st, end, newNode->data);
	newNode -> l = makeTree(in, pre, st, inindex-1);
	newNode -> r = makeTree(in, pre, inindex+1, end);
	
	return newNode;
		
	
	}
void inorder(struct BT *root)
		{
			if(!root)
				return;
			inorder(root->l);
		printf("\t[%d]",root->data);			
		inorder(root->r);
		
		}
void preorder(struct BT *root)
		{
			if(!root)
				return;
			printf("\t[%d]",root->data);	
			preorder(root->l);
					
		preorder(root->r);
		
		}		