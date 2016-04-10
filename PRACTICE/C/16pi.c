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
	
struct BT *insert(struct BT *root,int d)
	{
		if(!root)
			return (nn(d));
			
		if(root->data>d)
			{
				root->l=insert(root->l,d);
			}
		else
			root->r=insert(root->r,d);
			
			
		return root;				
	
	}	
	
	
struct BT *t2dll(struct BT *root)
	{
		struct BT *left,*right;
		if(root->l)
			{left=t2dll(root->l);
			
			for(;left->r;left=left->r);
			
			left->r=root;
			root->l=left;
			}
		if(root->r)
			{right=t2dll(root->r);
			
			for(;right->l;right=right->l);
			
			right->l=root;
			root->r=right;
					
			}
			
		return root;
	
	
	
	
	}	
	
	
struct BT *tdll(struct BT *root)
	{
		if(!root)
			return NULL;
			
		root=t2dll(root);
		
		while(root->l)
			root=root->l;
		
		
		return root;		
	
	
	
	
	
	}	
	
	
void print(struct BT *root)
	{
		while(root)
			{
				printf("[%d]--",root->data);
				root=root->r;
			
			}
	
	}	
	
void reverse(struct DLL **h)
	{
		if(!(*h))
			return ;
			
		struct DLL *cur,*t;
		
	cur=*h;
	while(cur)
		{
			t=cur->prev;
			cur->prev=cur->next;
			cur->next=t;
			
			cur=cur->prev;
				
		
		
		}
		if(t)
		*h=t->prev;
		
	
	
	}	
	
main()
	{
		struct BT *rt=NULL;
		rt=insert(rt,10);
		insert(rt,11);
		insert(rt,6);
		insert(rt,2);
		insert(rt,1);
		insert(rt,9);
		insert(rt,7);
		insert(rt,3);
		
		struct BT *h=tdll(rt);
		
		print(h);
	
	
	}	
	
