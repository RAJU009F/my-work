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
	
struct BT *built(int *pre,char *pr,int *pin,int n)
	{
		if(*pin==n)
			return NULL;
		int index=*pin;	
		struct BT *root=nn(pre[*pin]);
		
			++*pin;
		if(pr[index]=='N')
			{
				root->l=built(pre,pr,pin,n);
				root->r=built(pre,pr,pin,n);
			
			
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
		int pre[]={1,2,3,4,5,56};
		char pr[]={'N','L','N','N','L','L'};
		int pin=0;
		struct BT *rt=built(pre,pr,&pin,6);
		print_pre(rt);
	}	
	
	
