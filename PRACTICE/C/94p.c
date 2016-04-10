/*       REMOVING NODES OUT OF RANGE   */

#include<stdio.h>
#include<stdlib.h>

struct BST 
    {
        struct BST *l;
        struct BST *r;
        int data;
    };
    
struct BST *remove1(struct BST *,int,int);
void inorder(struct BST *);
struct BST *insert(struct BST * ,int);
struct BST *nn(int);


main()
    {
        struct BST *rt=NULL;
        rt=insert(rt,5);
        insert(rt,56);
        insert(rt,78);
        insert(rt,1);
        insert(rt,4);
        insert(rt,3);
        insert(rt,2);
        insert(rt,10);
        insert(rt,11);
        
        printf("\nBefore removal:");
        inorder(rt);
        rt=remove1(rt,3,11);
        
        
        printf("\nafter removal:");
        inorder(rt);
        printf("\n");
        
        
        
        
                
    
    }
    
struct BST *insert(struct BST *root,int d)
    {
        if(!root)
            return (nn(d));
            
          if(root->data>d)
                root->l=insert(root->l,d);
                
          if(root->data<d)
                root->r=insert(root->r,d);
                
                
           return root;             
    
    }    
struct  BST *nn(int d)
    {
        struct BST *t=(struct BST *)malloc(sizeof(struct BST));
        
        t->data=d;
        t->l=NULL;
        t->r=NULL;
        
        return t;
    
    
    }
    
struct BST *remove1(struct BST *root,int min,int max)
    {
    
        if(!root)
            return root;
            
            root->l=remove1(root->l,min,max);
            root->r=remove1(root->r,min,max);
            
            
        if(root->data<min)
            
            {
                struct BST *right=root->r;
                free(root);
                return right;
            
            
            
            }    
        if(root->data>max)
            {
            
                struct BST *left=root->l;
                free( root);
                return left;
            
            
            }
            
           return root; 
    
    
    }    
    
void inorder(struct BST *root)
    {
        if(root)
            {
            
                inorder(root->l);
                printf("[%d]\t",root->data);
                inorder(root->r);
            
            
            }
            
            
            
    
    
    }    
    
    


