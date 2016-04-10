#include<stdio.h>
#include<stdlib.h>

struct BT 
	{
		struct BT *l,*r;
		int data;
		
	
	};
	
struct BT *nn(int d )
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT) );
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		
		return root;
		
		
	
	
	}	

struct BT *built(int *pre,int *post,int *pin,int l,int s,int end)
	{
		if(l>s || s>=end)
			return NULL;
			
			
		struct BT *root=nn(pre[*pin]);
		
		++*pin;
		
		if(l==s)
				return root;
		int i;
		for(i=l;i<=s;i++)
			{
				if(post[i]==pre[*pin])
					break;
					
				
			
			}	
			
			
			
			if(i<=s)
				{
				
					root->l=built(pre,post,pin,l,i,end);
					root->r=built(pre,post,pin,i+1,s,end);
					
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
	
main()
	{
		int pre[]={4,6,8,9,3,2,5};
	
		int post[]={9,2,3,5,4,8,6};
		
		int pin=0;
		struct BT *rt=NULL;
		rt=built(pre,post,&pin,0,6,7);
		
		print_pre(rt);
	
	}	
