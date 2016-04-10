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
		
		return  root;
		
	
	
	
	}	
struct BT *insert(struct BT *root,int d)
	{
		if(!root)
			return nn(d);
			
		if(root->data>d)
			root->l=insert(root->l,d);
		 if(root->data<d)
		 	root->r=insert(root->r,d);
		 	
		 return root;			
	
	
	}	
	
	
void printpost(struct BT *root)	

	{
		if(root)
			{
				
				printpost(root->l);
				printf("[%d]\t",root->data);
				printpost(root->r);
				
			
			
			}
	
	
	}
void mirror(struct BT *root)
	{
		if(root)
				{
					mirror(root->l);
					struct BT *t=root->l;
					root->l=root->r;
					root->r=t;
					
					mirror(root->r);
					 
					
					
				}
		
	
	
	}	
	
void mirror1(struct BT *root)
	{
		if(root)
				{
					mirror1(root->l);
					
					
					mirror1(root->r);
					struct BT *t=root->l;
					root->l=root->r;
					root->r=t;
					 
					
					
				}
		
	
	
	}		
	
main()
	
	
	{
		struct BT *rt=NULL;
		int i=5;
		int data;
		while(i--)
			{
				scanf("%d",&data);	
				rt=insert(rt,data);
			}
	
			//insert(rt,99);
			printpost(rt);
				printf("\n\n\n\n");
			struct BT *t=rt;
				//mirror(t);
				//printpost(t);
				printf("\n\n\n\n");
				
			mirror1(rt);
			
			printpost(rt);
			
			printf("\n\n\n\n");
			
			
	
	
	
	}
