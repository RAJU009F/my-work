#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct BT 
	{
		struct BT *r;
		struct BT *l;
		
		int data;
	
	
	};
	
struct S
	{
	
		int s;
		int top;
		struct BT *a[];
	
	
	
	};	
	
	
struct S *create(int si)
	{
		struct S *stack=(struct S *)malloc(sizeof(struct S));
		stack->s=si;
		stack->top=-1;
		*stack->a=(struct BT **)malloc(sizeof(struct BT *)*si);
		
		return stack;
	
	
	
	}
	
int isFull(struct S *s)
	{
		return s->top==MAX-1;
	
	}	
	
int isEmpty(struct S *s)
	{
		return s->top==-1;
	
	}	
	
struct BT *Top(struct S *s)
		{
			if(isEmpty(s))
			return NULL;
			
		return s->a[s->top];
		
		}	
void push(struct S *s,struct BT *root)
	{
		if(isFull(s))	
			return;
			
		s->a[++s->top]=root;	
	
	
	
	}	
struct BT *pop(struct S *s)	
	{
		if(isEmpty(s))
			return NULL;
			
		return s->a[s->top--];	
			
	
	
	}
		
	
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT) );
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		
		return root;
		
		
	
	
	
	}	
	
void printarray(int path[],int n)
	{
		int i;
		for(i=0;i<n;i++)
			{
				printf("[%d]\t",path[i]);
			
			
			}
			
		printf("\n\n");	
	
	
	}	
void printpath(struct BT *root,int path[],int level)
	{
		if(!root)
			return;
		path[level++]=root->data;	
		if(!root->l && !root->r)
			printarray(path,level);
		else
			{				
					
				printpath(root->l,path,level);
				printpath(root->r,path,level);
			
			
			}	
	
	
	
		
	}
	
void print_post(struct BT *root)
	{
		if(!root)
			return;
			
		struct S *s=create(MAX);
		
		do
		{
			while(root)
				{
					if(root->r)
						push(s,root->r);
					push(s,root);
					
					root=root->l;		
				
				
				
				}
			root=pop(s);
				if(root->r && root->r==Top(s))
					{
						pop(s);
						
						push(s,root);
						root=root->r;
						
					}
				else
					{
						printf("[%d]\t",root->data);
						root=NULL;
					
					
					}	
		
		
		}while(!isEmpty(s));	
	
	
	}		
	
	
main()
	{
		struct BT *rt=nn(5);
		rt->l=nn(6);
		rt->r=nn(4);
		rt->l->r=nn(3);
		rt->l->l=nn(7);
		rt->r->r=nn(8);
		
		rt->r->l=nn(10);
		
		int path[100];
		printpath(rt,path,0);
		printf("\n\n\nPOST::\n\n");
		print_post(rt);
		
	
	
	}	
