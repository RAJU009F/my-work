#include<stdio.h>
#include<stdlib.h>
//#inlcude<>


struct BT {
	struct BT *l;
	struct BT *r;
	int data;

};

struct BT *newNode(int data)
		{
			struct BT *node = (struct BT *) malloc(sizeof(struct BT));
			if(!node)
				return NULL;
			node->data = data;
				node ->l = node->r = NULL;
				
			return node;
		
		
		}
		



struct BT  *Ceil(struct BT *root, int key, struct BT **prev)
{
	if(root)
	{
		if(!Ceil(root->r, key, prev))
			return NULL;
		if(root->data==key)
				return root;
		 if(root->data<key)
				return (*prev);
	
			*prev = root;
		return Ceil(root->l, key, prev);
		
		
	}else
		
	return NULL;
	
	
	
}

int  Floorr(struct BT *root, int key, struct BT *prev)
{
	if(!root)
			return -1;
		
		Floorr(root->l, key, prev);
		
	
		if(root->data==key)
		{
			
			printf("%d", root->data);
			return 1;
		}
		if(root->data > key && prev)
		{
			printf("%d",prev->data);
			return 1;
			
		}
		prev = root;
		Floorr(root->r, key, prev);
	
}


struct BT  *Floor(struct BT *root, int key, struct BT **prev)
{
	
	if(root)
	{
		if(!Floor(root->l, key, prev))
			return 0;
		
		if(root->data==key)
				return root;
	 if(root->data>key )
				return (*prev);
		
			*prev = root;
		return Floor(root->r, key, prev);
		
		
	}else
	return NULL;
}

int main()
{
	struct BT *root =newNode(8);

    root->l = newNode(4);
    root->r = newNode(12);

    root->l->l = newNode(2);
    root->l->r = newNode(6);

    root->r->l = newNode(10);
    root->r->r = newNode(14);
	int i ;
	struct BT *prev = NULL;
	/*for (i=0; i<16 ; i++){
	
	struct BT *temp =Floor(root, i, &prev);
	if (temp)
		printf(" Floor of %d is %d\n\n",i, temp->data);
	prev = NULL;
	temp =Ceil(root,i, &prev);
	printf("Ceil of %d  is %d\n\n",i, temp->data);
	}*/
	printf("%d", Floorr(root, 5, prev));
}