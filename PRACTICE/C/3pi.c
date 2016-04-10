#include<stdio.h>
#include<stdlib.h>

struct BT
	{
		struct BT *l;
		struct BT *r;
		int data;
	
	
	};
	
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		
		return root;
	
	
	}	
int has(struct BT *root)
	{
		if(!root)
			return 1;
			
		if(!root->l && !root->r)
			return 1;
		int lt=0;
		int rt=0;
		
		if(root->l)
			lt=root->l->data;
			
		if(root->r)
			rt=root->r->data;
			
		if((root->data==rt+lt)&&has(root->l)&&has(root->r))
			return 1;
		else
			return 0;				
				
	
	
	
	
	}	
	
main()
	{
	
	struct BT *rt=nn(6);
	rt->l=nn(3);
	rt->r=nn(3);
	rt->l->r=nn(18);
	rt->l->l=nn(2);
	rt->r->r=nn(2);
	rt->r->l=nn(1);
	
	if(has(rt))
		printf("\nHas Childrn sum property::\n\n");
	else
		printf("\nNO\n");	
	
	
	
	}	
