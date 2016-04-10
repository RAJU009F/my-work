#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct BT 
	{
		struct BT *r,*l;
		int data;
	
	};
struct BT *nn(int d)
	{
	
		struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
		root->data=d;
		root->l=NULL;
		root->r=NULL;
		return root;
	}
int search(int *in,int st,int n,int d)
	{
		int i=st;
		for(i;i<n;i++)
			{
				if(in[i]==d)
					return i;
			
			}
	
	
	}	
	
struct BT *built(int *in,int *pre,int s,int n)	
	{
		if(s>n)
			return NULL;
			
		static int 	pin=0;
		
		struct BT *root=nn(pre[pin++]);
		int inin=search(in,s,n,root->data);	
		if(s==n)
			return root;
			
		
		
				root->l=built(in,pre,s,inin-1);
				root->r=built(in,pre,inin+1,n);
			
			
			
	
	
		return root;
	
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
	
void printpre(struct BT *root)
	{
		if(root)
			{
				printf("[%d]\t",root->data);
				printpre(root->l);
				printpre(root->r);
			
			}
	
	}	
void printarray(int *p,int n)
	{
		int i;
		for(i=0;i<n;i++)
			{
				printf("[%d]\t",p[i]);
			}
	
	
	
	}	
	
void printpaths(struct BT *root,int *p,int level)
	{
		
			
			
		if(!root->l&&!root->r)
			printarray(p,level)	;
			
		if(root)
			{
					p[level]=root->data;
					level++;
				printpaths(root->l,p,level);
				printpaths(root->r,p,level);
			
			}
	
	
	
	}	
int isBST(struct BT *root)
	{
		static struct BT *prev=NULL;
		if(root)
			{
				if(!isBST(root->l))
					return false;
					
				if(prev && prev->data>root->data)
					return false;
					
				prev=root;	
				return isBST(root->r);	
					
						
			
			
			
			
			}
	
		return true;
	}
	
int depth(struct BT *root,struct BT *node)
	{
		if(!root)
			return 0;
			
		if(root==node)
			return 1;
			
			int x=depth(root->l,node);
			int y=depth(root->r,node);
			
			return (x>y?x:y)+1;	
	
	}	
main()

	{
		/*struct BT *rt=nn(4);
			rt->l=nn(65);
			rt->r=nn(54);*/
			
				int pre[]={3,5,2,6,7,1,4};
		
		int in[]={1,2,3,4,5,6,7};
				
			
			struct  BT *rt=built(in,pre,0,6);
			
			printin(rt);
			
			printf("\n\n");
			printpre(rt);
			printf("\n\n");
			
		int p[100];
		
		if(isBST(rt))
			{
				printf("\nYES BST\n");
				
				
			}
		else
			printf("\nNO\n");	
		//printpaths(rt,p,0);	
		printf("depth::\t%d\t\n\n\n",depth(rt,nn(7)));	
	
	
	}
