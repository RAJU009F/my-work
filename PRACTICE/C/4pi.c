#include<stdio.h>
#include<stdlib.h>
int count[3];
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
void width(struct BT *root,int level)
	{
		
		if(root)
			{
				count[level]++;
				
				width(root->l,level+1);
				width(root->r,level+1);
			
			
			
			}
	
	
	
	}	
	
int isbalanced(struct BT *root,int *h)
	{
		int lh=0;
		int rh=0;
		int l;
		int r;
		if(!root)
			{
				*h=0;
				return 1;
			
			
			}
		l=isbalanced(root->l,&lh);
		r=isbalanced(root->r,&rh);
		
		*h=(lh>rh?lh:rh)+1;
		
		if(abs(lh-rh)>=2)
			return 0;
		
		return l&&r;		
			
	
	
	
	
	}	
int hassum(struct BT *root,int sum)
	{
		if(!root)
			return sum==0;
			
		int s=sum-root->data;
		
		if(hassum(root->l,s)||hassum(root->r,s))
			return 1;
		else
			return 0;		
	
	
	
	
	
	
	
	
	}	
	
	
main()
	{
		struct BT *rt=nn(7);
		
		rt->l=nn(7);
		rt->r=nn(454);
		rt->l->r=nn(3);
		rt->l->l=nn(5);
		rt->r->r=nn(4534);
		rt->r->l=nn(5);
		
		
		int level=0;	
		width(rt,level);	
		int max=count[0];	
		int i;
		for(i=0;i<3;i++)
			{
				if(count[i]>max)
					{
						max=count[i];
						level=i;
					}
			}
			
			
			
		printf("LEvel :: %d and MAXWidth:: %d\n\n ",level,max);	
		int h=0;
		if(isbalanced(rt,&h))
			printf("\nBalanced::\n\n");
		else
			printf("\nNot Balanced::\n\n");	
			
		if(hassum(rt,466))
			printf(" HAS sum::\n");
		else
			printf("NO ::\n" );		
			
			
	
	
	
	}	
