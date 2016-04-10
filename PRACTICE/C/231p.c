#include<stdio.h>
#include<stdlib.h>

struct BT 
	{
		struct BT *l;
		struct BT *r;
		int data;
	
	
	};
	
	
struct BT *built(int *,int *,int ,int );

struct BT *nn(int );



int search(int *,int ,int ,int);
void printin(struct BT *);
main()
	{
		int in[]={1,2,3,4,5};
		int pre[]={5,3,1,2,4};
		
		struct BT *rt=built(in,pre,0,7);
		
		printin(rt);
	
	}
	
void printin(struct BT *root)	
		{
			if(root)
				{
					printin(root->l);
					printf("[%d]\t",root->data);
					printin(root->r);
				
				
				}
		
		}
		
		
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT));
		
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		
		return root;
		
	
	
	}		
	
struct BT *built(int *in,int *pre,int s,int e)
	{
		static int pin=0;
		
		if(s>e)
			return NULL;
			
		struct BT *root=nn(pre[pin]);
		
		++pin;
			
		if(s==e)
			return root;
				
		int i=search(in,s,e,root->data);
				
		root->l=built(in,pre,s,i-1);
		root->r=built(in,pre,i+1,e);
				
				return root;
			
	
	
	
	
	
	}	
int search(int in[],int s,int n,int d)
	{
		int i=s;
		for(i;i<=n;i++)
			{
				if(in[i]==d)
					return i;
			
			}
	
	
	}	
	
