/*populating next pointer*/

#include<stdio.h>
#include<stdlib.h>

struct BT
    {
        struct BT *l;
        struct BT *r;
        struct BT *next;
        int data;
        
    };
    
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        
        root->data=d;
        root->next=NULL;
        root->r=root->l=NULL;
        
        
        return root; 
    
    
    }    

void populate(struct BT *root)
    {
         static struct BT *n=NULL;
        if(root)
            {
            
           
            populate(root->r);
            root->next=n;
            n=root;
            populate(root->l);
                        
            }
    }

    
main()
    {
        struct BT *rt=nn(6);
        rt->l=nn(53);
        rt->r=nn(67);
        rt->l->l=nn(656);
        rt->l->r=nn(44);
        
        populate(rt);
        
        struct BT *t=rt->l->r;
        
        while(t)
            {
                printf("next of [%d] is [%d]\n\n",t->data,t->next?t->next->data:0);
                t=t->next;
            
            }
    
    
    
    
    }    
