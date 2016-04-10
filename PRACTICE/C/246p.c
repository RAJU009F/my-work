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
struct BT *built(int *pre,int *p,int l,int h,int end)
	{
		if(l>h|| h>end)
			return NULL;
			
		struct BT *root=nn(pre[*p]);
		
		++*p;
		
		
			
		int i;
		for(i=l;i<=h;i++)
			{
				if(pre[i]>root->data)
					break;
			
			
			}
		if(l==h)
			return root;
		else
		{			
		root->l=built(pre,p,*p,i-1,end);
		root->r=built(pre,p,i,h,end);
		}
	return root;		
			
	
	
	}	
	
	
void print_pre(struct BT *root)
	{
		if(root)
			{
			printf("[%d]\t",root->data);
			print_pre(root->l);
			print_pre(root->r);
			
			
			}
	
	
	}	
int hasch_pro(struct BT *root)
	{
		
		int lt=0;
		int rt=0;
		if(!root || (!root->l && !root->r))
			return 1;
			
		else
		{
			if(root->l)
				lt=root->l->data;
			if(root->r)
				rt=root->r->data;
					
			
			if(root->data==lt+rt && hasch_pro(root->l)&&hasch_pro(root->r))
				return 1;
			else	
				return 0;
			
		}	
	
		
	
	}	
	
	
main()
	{
	
	int pre[]={1,4,57,8,9,45,3,45,90,89};
	
	int p=0;
	struct BT*rt=built(pre,&p,0,9,10);
	
	print_pre(rt);
	
	if(hasch_pro(rt))
		printf("Yes it:\n\n");
	else
		printf("\nNo :\n\n");	
	
	}
