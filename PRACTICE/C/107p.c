/* /*construction of tree from its pre order*/ 

#include<stdio.h>

#include<stdlib.h>

struct BST 
    {
        struct BST *l;
        struct BST *r;
        int data;
    
    };
    
struct BST *nn(int);

struct BST *buildBST(int *,int *,int,int, int);
void printpre(struct BST *);


main()
    {
        int pre[]={10, 5, 1, 7, 40, 50};
        int size=sizeof(pre)/sizeof(pre[1]);
        int index=0;
        struct BST *rt=buildBST(pre,&index,0,size-1,size);
    
    printpre(rt);
    printf("\n");
    
    }
    
struct BST *buildBST(int p[],int *in,int l,int h,int end)
    {
        if(h>=end||l>h)
            return NULL;
            
            struct BST *root=nn(p[*in]);
            ++*in;
            
            if(l==h)
                return root;
             int i=l;
             for(i;i<=h;++i)
                if(p[i]>root->data)
                    break;
                    
             root->l=buildBST(p,in,*in,i-1,end);
             root->r=buildBST(p,in,i,h,end);
             
             return root;          
    
    
    
    
    
    
    
    }  
    
    
 struct BST *nn(int d)
    {
        struct BST *root=(struct BST *)malloc(sizeof(struct BST ));
        root->data=d;
        root->r=root->l=NULL;
        
        return root;
        
    


    }         
  void printpre(struct BST *root)
    {
    
        if(root)
            {
                
                printpre(root->l);
                printf("[%d]\t",root->data);
                printpre(root->r);
            
            }
    
    }  
