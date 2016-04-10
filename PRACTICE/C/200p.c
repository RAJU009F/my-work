#include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct BT
	{
		struct BT *l;
		struct BT *r;
		int data;
		
	
	
	};
	
struct S
	{
		int size;
		int top;
	struct BT *a[];
		
		
	
	};	
int isEmpty(struct S *s)
	{
		return(s->top==-1);
	
	
	}	
int isFull(struct S *s)
	{
		return s->top==s->size-1;
	
	}	
	
	
	
struct S *create(int s)
	{
		struct S *stack=(struct S *)malloc(sizeof(struct S));
		stack->size=s;
		stack->top=-1;
		*stack->a=(struct BT **)malloc(sizeof(struct BT *)*s);
		
		return stack;
	
	}
struct BT *pop(struct S *s)
	{
		if(isEmpty(s))
			return NULL;
		else
			return s->a[s->top--];	
	
	
	}	
struct BT *top(struct S *s)
	{
		
		if(isEmpty(s))
			return NULL;
		else
			return s->a[s->top];
	
	
	
	
	}
void push(struct S *s,struct BT *root)
	{
	
		if(isFull(s))
			return;
			
		else
			{
			
				s->a[++s->top]=root;
			
			
			}	
	
	
	}	
	
		
void printpost(struct BT *root)
	{
		if(!root)
			return ;
			
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
					
					if(root->r&&root->r==top(s))
						{
						
							pop(s);
							push(s,root);
							root=root->r;
						
						}
					else
						{
							printf(" [%d]  ",root->data);
							root=NULL;
						
						
						}
						
		
		
			} while(!isEmpty(s));	
			
	
	
	
	}		
	
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
			root->l=root->r=NULL;
			
			root->data=d;
			printf("created\n\n");
			return root;
	
	
	}
	
main()
	{
		struct BT *rt=nn(565);
		rt->l=nn(45);
		rt->l->r=nn(67);
		rt->l->l=nn(607);
		rt->r=nn(53);
		rt->r->l=nn(5656);
		rt->r->r=nn(565);
		
		printpost(rt);
	
	
	
	}	
	
	
	
	
