/*construction of tree from its pre and post and in orders*/

#include<stdio.h>

#include<stdlib.h>


struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;
    };
    
 struct BT *nn(int);
 struct BT *build(int *,int *,int, int);
 int search(int *,int ,int ,int);
 struct BT *buildBT(int *,int *,int,int);
 
 void inorder(struct BT *);
 main() 
    {
        int i[]={1,2,3,4,5,6,7,8,9};
        int p[]={5,4,6,1,2,8,7,3,9};
        
        struct BT *rt=build(i,p,0,8);
       
        inorder(rt); 
    
    
    }
 
 struct BT *build(int in[],int p[],int start,int end)
    {
    
    
        if(start>end)
            return NULL;
            
            static int pin=0;
            
            struct BT *root=nn(p[pin]);
            pin;
            
            if(start==end)
                return root;
                
            int inin=(in,start,end,root->data);
            
            root->l=buildBT(in,p,start,inin-1);
            root->r=buildBT(in,p,inin+1,end);
            
            return root;    
    
    
    
    }
    
 struct BT *nn(int d)
    {
    
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
        
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        
        return root;
    
    } 
    
 int search(int a[],int start,int n,int x)
    {
        int i;
        for(i=start;i<=n;i++)
            {
                if(a[i]==x)
                    return i;
            
            }
    
    
    } 
    
 void inorder(struct BT *root)
    {
        if(root)    
            {
                printf("[%d]\t",root->data);
                inorder(root->l);
               
                inorder(root->r);
            
            
            }
    
    
    }       
    
    
    struct BT *buildBT(int i[],int p[],int st,int en)
    {
        if(st>en)
            return NULL;
            
         static int pin=0;
         
        struct BT  *root=nn(p[pin]);
        ++pin;
        
        if(st==en)
            return root;
        
        int inin=search(i,st,en,root->data);
        
        root->l=buildBT(i,p,st,inin-1);
        root->r=buildBT(i,p,inin+1,en);
        
        return root;       
    
    
    
    
    
    }
    

