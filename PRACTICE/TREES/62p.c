#include<stdio.h>
#include<stdlib.h>
struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };

struct BT *builtBT(int *,int *,int ,int);
struct BT *nn(int );
int search(int *,int, int ,int);
void printinorder(struct BT *);
struct BT *LCA(struct BT *,struct BT *,struct BT *);

struct BT *built(int pre[],int in[] ,int start,int n)
	{
		if(start>n)
			return NULL;
			
		
		static int pr=0;
		struct BT *root=nn(pre[pr++]);
		
			
			
		if(start==n)
			return root;
			
		int i=search(in,start,n,root->data);
			
		root->l=built(pre,in,start,i-1);
		root->r=built(pre,in,i+1,n);
			
			
		return root;
			
		
		
		
	
	}	



main()
    {
    
   int pre[]={3,5,2,6,7,1,4};
		
		int in[]={1,2,3,4,5,6,7};
    struct BT *r=builtBT(in,pre,0,7);
    
    printf("\n\n");
    printinorder(r);    
    printf("\n\n");
    
    struct BT *r=built(pre,in,0,7);
     printf("\n\n");
    printinorder(r);    
    printf("\n\n");
    
    }
struct BT *builtBT(int i[],int p[],int st,int en)
    {
        if(st>en)
            return NULL;
            
         static int pin=0;
         
        struct BT  *root=nn(p[pin]);
        ++pin;
        
        if(st==en)
            return root;
        
        int inin=search(i,st,en,root->data);
        
        root->l=builtBT(i,p,st,inin-1);
        root->r=builtBT(i,p,inin+1,en);
        
        return root;       
    
    
    
    
    
    }
    
 struct BT *nn(int dt)
    {
    
        struct BT *t=(struct BT *)malloc(sizeof(struct BT));
        t->data=dt;
        t->l=NULL;
        t->r=NULL;
        return t;            
    
    
    }   
    
    
 int search(int a[],int k,int m,int da)
    {
    
        int index;
    
        for(index=k;index<=m;index++)
            {
                if(a[index]==da)
                    return index;
            
            
            }
    
    }   
    
 void printinorder(struct BT *root)   
    {
        if(root)
            {
            
                printinorder(root->l);
                    printf("[%d]\t",root->data);
                printinorder(root->r);
            
            
            }
    
    
    }
    
    
struct BT *LCA(struct BT *root,struct BT *node1,struct BT *node2)   
    {
        if(!root)
            return NULL;
            
         if(root==node1 || root==node2)
            return root;
            struct BT *left = LCA(root->l,node1,node2);
           struct BT *right=LCA(root->r,node1,node2);
            if(left&&right)
                return root;
            else if(left)
                return left;   
            else if(right)
                return right; 
            else
                return NULL;     
    
    
    
    
    
    
    }    
