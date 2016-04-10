#include<stdio.h>
#include<stdlib.h>


struct BT
    {
        struct BT *l;
        struct BT *r;
        int lc;
        int rc;
    
    
    };
    
    
int count(struct BT *);

main()
    {
    
         struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
         int res=count(root);
         
    
    
    }
int count(struct BT *root)
    {
        int lcnt,rcnt;
        
        lcnt=0;
        rcnt=0;
        if(root->l)
            {
            
            lcnt=1+count(root->l);
            root->lc=lcnt;
            
            }
            
         else
            root->lc=0;
            
         if(root->r)
            {
            
            rcnt=1+count(root->r)
            root->rc=rcnt;
            
            }
           else
            root->rc=0;
            
          return rcnt+lcnt;         
        
    
    
    
    
    }   
