/*        TREE TO  DLL    */  

#include<stdio.h>

#include<stdlib.h>




struct BT  
    {
    struct BT *l;
    struct BT *r;
    int data;
    
    };
    

struct BT *b2dll(struct BT *);
void printdll(struct BT *);
 struct BT *b2dll1(struct BT *root);
 struct BT *nn(int );
main()
    {
        struct BT *rt=nn(5);
        rt->l=nn(4);
        rt->l->l=nn(3);
        rt->l->r=nn(2);
        rt->l->l->l=nn(1);
        
        rt->r=nn(6);
        rt->r->l=nn(7);
        rt->r->r=nn(8);
        rt->r->r->r=nn(9);
        
        struct BT *head=b2dll(rt);
        printf("\n");
        printdll(head);
        printf("\n");
    
    
    
    }
    
 struct BT *b2dll1(struct BT *root)
    {
        if(!root)
            return NULL;
            
         if(root->l)
                {
                    struct BT *left=b2dll1(root->l);
                    for(;left->r;left=left->r);
                    left->r=root;
                    root->l=left;
                }   
          if(root->r)
            {
                struct BT *right=b2dll1(root->r);
                for(;right->l;right=right->l);
                root->r=right;
                right->l=root;
            
            } 
            
            return root; 
    
    
    }   
    
 struct BT *b2dll(struct BT *root)
    {
        root=b2dll1(root);
        
        
        while(root->l)
            root=root->l;
    
        return root;
    }   
    
 void printdll(struct BT *h)
    {
    
        printf("NULL<-");
        while(h)
            {
                printf("-[%d]-",h->data);
                h=h->r;
            
            
            }
        printf("->NULL");
    
    }   
    
struct BT *nn(int d)
    {
    
        struct BT *temp=(struct BT *)malloc(sizeof(struct BT ));
        temp->data=d;
        temp->l=NULL;
        temp->r=NULL;
        
        return temp;
    
    
    }    
