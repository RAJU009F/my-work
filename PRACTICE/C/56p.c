#include<stdio.h>

#include<stdlib.h>
struct BT
    {
        struct BT *l;
        struct BT *r;
        int lc;
        int rc;
    
    
    };
    
int populate(struct BT *);
    
main()

    {
        int c;
        
        struct BT *root=malloc(sizeof(struct BT));
        
        c=populate(root);
            

    
    
    
    
    }
    
    
int populate(struct BT *root)
    {
        if(!root)
            return;
          populate(root->l);
          populate(root->r);  
         if(root->l)
            root->lc=root->l->lc+root->l->rc+1;
         else
            root->lc=0;
            
          if(root->r)
            root->rc=root->r->lc+root->r->rc+1;
          else
            root->rc=0;    
               
    
    
    
    
    }    
