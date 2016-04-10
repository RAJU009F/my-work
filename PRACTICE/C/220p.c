#include<stdio.h>
#include<stdlib.h>

struct BT
	{
	
		struct BT *l,*r;
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

void print(struct BT *root)
	{
		if(root)
			
			{
				printf("%d ",root->data);
				
				if(root->l)
					{
						printf("[ ");
						print(root->l);	
					}	
				if(root->r)
					{
						print(root->r);
						printf("] ");
					
					
					}	
				else
					{
						printf("- ]");
					
					}		
			
			
			}
	
	
	
	}
void printp(struct BT *root)
	{
		if(root)
			{
			
				printf("[%d]\t",root->data);
				
				printp(root->l);
				printp(root->r);
			}
	
	
	}	
	
main()
	{
		
		struct BT *rt=nn(56);
		rt->l=nn(453);
		rt->l->r=nn(45);
		rt->l->l=nn(56);
		rt->r=nn(545);
		rt->r->l=nn(33);
		rt->r->r=nn(454);
		printp(rt);
		printf("\n\n");
		printf("\n\n");
		print(rt);
		printf("\n\n");printf("\n\n");
	
	}
