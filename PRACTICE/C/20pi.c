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
		struct BT *root=(struct BT *)malloc(sizeof(struct BT));
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		return root;
	
	
	}
int search(int in[],int l,int h,int d)
	{
		int i=l;
		for(i;i<=h;i++)
			{
				if(in[i]==d)
					return i;
			
			
			}
	
	}	
		
struct BT *built(int in[],int pre[],int l,int h)	
	{
		static int p=0;
		if(l>h)
			return NULL;
			
			
			
		struct BT *root=nn(pre[p]);
		++p;
		int i=search(in,l,h,root->data);
		if(l==h)
			return root;
		
				root->l=built(in,pre,l,i-1);
				root->r=built(in,pre,i+1,h);			
			
			
			return root;
	
	
	
	}
	
void print_post(struct BT *root)
	{
		if(root)
			{
					
				printf("[%d]\t",root->data);
				print_post(root->l);
				print_post(root->r);
			
			
			
			}
	
	
	}	
	
	
main()
	{
		int in[]={1,2,3,4,5,6,7,8,9,45,12};
		int pre[]={2,1,3,9,8,7,5,6,4,12,45};
		struct BT *rt=built(in,pre,0,10);
		
		print_post(rt);
	
	}
