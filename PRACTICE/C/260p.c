#include<stdio.h>
#include<stdlib.h>

struct BST 
	{
		struct BST *l;
		struct BST *r;
		int data;	
	
	
	};
	
struct BST *nn(int d)
	{
		struct BST *root=(struct BST *)malloc(sizeof(struct BST ));
		root->l=NULL;
		root->r=NULL;
		root->data=d;
	
		return root;
	
	}	
	
struct BST *insert(struct BST *root,int d)
	{
		if(!root)
			return nn(d);
		if(root->data>d)
			{
			
				root->l=insert(root->l,d);
			
			
			}	
			
		else
			{
			
				root->r=insert(root->r,d);
			}	
	
	
		return root;
	
	}	
	
void print_inorder(struct BST *root)
	{
	
		if(root)
			{
				print_inorder(root->l);
				printf("[%d]\t",root->data);
				print_inorder(root->r);
			
			
			}
	
	
	
	}	
	
int lca(struct BST *root,struct BST *x,struct BST *y)
	{
		if(!root)
			return 0;
		while(1)
			{
				if((root->data>x->data && root->data<y->data)||(root->data>y->data && root->data<x->data))
					return 	root->data;
					
					if(x->data<root->data)
						root=root->l;
					else
						root=root->r;	
			
			
			
			}	
	
	
	
	
	}	
	
int LCA(struct BST *root,int d1,int d2)
	{
		if(!root)
			return 0;
		if(root->data==d1 ||root->data==d2)
			return root->data;
		int lt=LCA(root->l,d1,d2);
		int rt=LCA(root->r,d1,d2);
		
		if(lt&&rt)
			return root->data;
			
		return lt?lt:rt;			
	
	
	
	}
	
int LCA1(struct BST *root,int n1,int n2)
	{
		if(!root||root->data==n1 || root->data==n2)
			return -1;
			
		if((root->r && root->r->data==n1)||(root->r && root->r->data==n2))
			return root->data;
			
		
		if((root->l && root->l->data==n1)||(root->l && root->l->data==n2))
			return root->data;
				
				
		if(n1<root->data && n2<root->data)
			LCA1(root->l,n1,n2);
		if(n1>root->data && n2>root->data)
			LCA1(root->r,n1,n2);			
				
			
	
	
	
	}	
	
int cil(struct BST *root,int d)
	{
		if(!root)
			return 0;
		if(root->data<d)	
		 return cil(root->r,d);
		 
		int c=cil(root->l,d);
		return c>=d?c:root->data;	
	
	
	
	
	}		
	
int C(struct BST *root ,int d)
	{
		if(!root)
			return 0;
		static struct BST *t=NULL;	
			
		if(!C(root->r,d))
			return 0;	
		if(root->data==d)
			return root->data;
		if(root->data<d)
			return t->data;
			t=root;
		return C(root->l,d);		
	
	
	
	
	}	
int F(struct BST *root ,int d)
	{
		if(!root)
			return 0;
		static struct BST *t=NULL;	
			
		if(!F(root->l,d))
			return 0;	
		if(root->data==d)
			return root->data;
		if(root->data>d)
			return t->data;
			t=root;
		return F(root->r,d);		
	
	
	
	
	}	
	
struct BST *Max(struct BST *root)
	{
		if(!root)
			return NULL;
		root=root->r;	
		while(root->r)
			root=root->r;
		
		
		return root;		
			
			
	
	
	
	}	
struct BST  *delet(struct BST *root,int d)
	{
	
		if(!root)
			return;
			
		if(root->data>d)
			delet(root->l,d);
		if(root->data<d)
			delet(root->r,d);
			
		else
			{
				if(root->l && root->r)
					{
						struct BST *temp=Max(root->l);
					
						root->data=temp->data;
						
						root->l=delet(root->l,root->data);
						
					
					
					}
					
				else
					{
						struct BST *temp=root;
						
						if(!root->l)
							root=root->r;
						if(!root->r)
							root=root->l;	
							free(temp);
					
					}	
					
			
			
			
			
			}			
	
		return root;
	
	
	
	
	
	}	
	
int isbst(struct BST *root)
	{
		struct BST *prev=NULL;
		if(!root)
			return 1;
		if(!isbst(root->l))
			return 0;
		if(prev && prev->data>root->data)
			return 0;		
		return isbst(root->r);
	
	
	
	
	
	
	}	
	
main()
	{
		
	struct BST *rt=NULL;
	
		rt=insert(rt,8);
		insert(rt,16);
		insert(rt,1);
		insert(rt,6);
		
		insert(rt,34);
		insert(rt,67);
		insert(rt,3);
		insert(rt,2);
		insert(rt,0);
		//printf("\n\nLCA ::[%d]\n[%d]\n",lca(rt,nn(56),nn(43)),LCA1(rt,56,43));
		
		
	printf("ceil of::\t\n[%d]\n\n[%d]\n[%d]\n\n\n",cil(rt,8),C(rt,8),F(rt,8));
	print_inorder(rt);
	printf("\n\n");
	delet(rt,8);
	
		print_inorder(rt);
	printf("\n\n");
	
	if(isbst(rt))
		printf("\n\n:yes it is :\n\n");
	else
		printf("\n\nNo\n\n");	
	
	
	}	
	
