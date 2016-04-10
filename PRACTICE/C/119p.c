#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BT
    {
        struct BT *r;
        struct BT *l;
        int data;
    
    };
    
    
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->l=NULL;
        root->r=NULL;
        root->data=d;
        
        return root;
        
    }
    
bool areidentical(struct BT *root1,struct BT *root2)
    {
        if(!root1&& !root2)
            return true;
            
         if(root1->data==root2->data&&areidentical(root1->l,root2->l)&&areidentical(root1->r,root2->r))
            return true;   
        else
            return false;
    
    }        

bool issubtree(struct BT *T ,struct BT *R)
    {
        if(!T&&!R)
            return true;
            
         if(!T && R)
            return false;   
        if(areidentical(T,R))
            return true;
        
        return (issubtree(T->l,R)||issubtree(T->r));
            
    }    
    
    
 main()
    {
    
        struct BT *rt=nn(5);
        rt->l=nn(4);
        rt->r=nn(7);
        rt->l->l=nn(8);
        rt->l->r=nn(10);
        rt->r=nn(12);
        rt->r->l=nn(13);
        rt->r->l->l=nn(14);
        rt->r->r=nn(15);
        rt->r->r->l=nn(16);
        rt->r->l->r=nn(18);
        
        
        struct  BT *rt1=nn(12);
        rt1->l=nn(13);
        rt1->l->l=nn(14);
        rt1->l->r=nn(18);
        rt1->r=nn(15);
        rt1->r->l=nn(16);
        
        if(issubtree(rt,rt1))
            printf("Yes\n\n");
        else
            printf("No\n");    
    
    }
