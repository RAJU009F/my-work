#include<stdio.h>
#include<stdlib.h>

struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };
void mirror(struct BT *);    
struct BT *nn(int );
void printpre(struct BT *);    
    
    main()
        {
        
        struct BT *rt=nn(5);
        
        rt->l=nn(4);
        rt->r=nn(6);
        rt->l->l=nn(3);
        rt->l->r=nn(2);
        rt->r->l=nn(7);
        rt->r->r=nn(8);
        printf("\n\n");
        printpre(rt);
        mirror(rt);
        printf("\n\n");
        printpre(rt);  
        printf("\n\n\n"); 
        
        }
        
struct BT *nn(int dt)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT) );
        root->data=dt;
        root->l=NULL;
        root->r=NULL;
        return root;
    
    
    
    }        
    
    
 void printpre(struct BT *root)
    {
        if(root)
            {
            
                printf("[%d]\t",root->data);
                printpre(root->l);
                printpre(root->r);
            
            }
    
    
    }   
void mirror(struct BT *root)    
    {
        if(root)
            {
                mirror(root->l);
                mirror(root->r);
                
                struct BT *t=root->l;
                root->l=root->r;
                root->r=t;
                
            
            
            }
    
    
    
    }
    
