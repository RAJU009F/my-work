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
	
	
void mirror(struct BT *root,int level)
	{
		if(root)
			{
			
				if(level%2==0)
					{
						mirror(root->l,level+1);
						mirror(root->r,level+1);
						
						struct BT *t=root->l;
						root->l=root->r;
						root->r=t;
					
					
					}
				else
					{
					
					mirror(root->l,level+1);
					mirror(root->r,level+1);
						
					
					
					}	
			
			
			
			}
	
	
	
	}
	
print_inorder(struct BT *root)
	{
	
		if(root)
			{
			
				printf("[%d]\t",root->data);
				print_inorder(root->l);
				print_inorder(root->r);
			
			
			}
	
	
	}		
int cat(int n)
	{
		int sum=0,i;
		if(n<=1)
			return 1;
			
		else
			for(i=1;i<=n;i++)
				sum+=cat(i-1)+cat(n-1);
		return sum;			
	
	
	}
		
	
main()
	{
	
		struct BT *rt=nn(6);
		rt->l=nn(67);
		rt->r=nn(45);
		rt->l->r=nn(454);
		rt->r->r=nn(56);
		
		rt->l->l=nn(4545);
		rt->r->l=nn(45);
		
		print_inorder(rt);
		int level=0;
		mirror(rt,level);
		printf("\n\n");
		print_inorder(rt);
		
		printf("Catalan No:: %d \n\n",cat(3));
			
	
	}	

