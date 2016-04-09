#include<stdio.h>
#include<stdlib.h>

struct BT{
	struct BT *l;
	struct BT *r;
	int data;

};

struct BT *newnode(int data)
{
	struct BT *node = (struct BT *)malloc(sizeof(struct BT));
	node->data = data;
	node->l = node->r = NULL;
	return node;
	
	
}


int Floor(struct BT *root, int key, struct BT **prev)
{
		if(!root)
				return -1;
		int t = Floor(root->l, key, prev);
		if(t!=-1)
				return t;
		
		if(root->data == key)
				return key;
			
		if(root->data>key && *prev)
				return (*prev)->data;
			
			*prev = root;
	return Floor(root->r, key, prev);
	
	
}

int FFloor(struct BT *root, int key)
{
	if(!root)
			return -1;
		if(root->data == key)
				return key;
		if(root->data>key)
				return FFloor(root->l, key);
		int f = FFloor(root->r, key);
			return (f<=key?f:root->data);
	
	
	
}



struct BT *Ceil(struct BT *root, int key, struct BT **prev)
{
	
	if(!root)
			return NULL;
		if(!Ceil(root->r, key, prev))
				return 0;
		if(root->data == key)
				return root;
		if(root->data<key )
				return *prev;
		*prev = root;
			return Ceil(root->l, key, prev);
	
	
	
}
int main()
	{
	
	struct BT *root = newnode(8);

    root->l = newnode(4);
    root->r = newnode(12);

    root->l->l = newnode(2);
    root->l->r = newnode(6);

    root->r->l = newnode(10);
    root->r->r = newnode(14);
	struct BT *prev = NULL;
	int i; 
	for(i=0; i< 16; i++){
		//int re = Floor(root, i, &prev);
		int r = FFloor(root, i);
		printf("Floor of  %d is %d\n",i,r);
		}
		
	prev = NULL; 
//struct BT *temp = Ceil(root, 6, &prev);
//p/rintf("%d", temp->data);	
	}