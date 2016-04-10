
/*        To ISOMORPHIC OR NOT  */  


#include<stdio.h>
#include<stdlib.h>

struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    };

struct BT *nn(int);

int isomorphic(struct BT *,struct BT *);


main()
    {
    
        struct BT *rt1=nn(5);
        rt1->l=nn(4);
        rt1->r=nn(6);
        rt1->l->l=nn(3);
        rt1->l->r=nn(2);
        rt1->r->l=nn(7);
        rt1->r->r=nn(8);
        
        struct BT *rt2=nn(5);
         rt2->r=nn(4);
        rt2->l=nn(6);
        rt2->r->r=nn(3);
        rt2->r->l=nn(2);
        rt2->l->r=nn(7);
        rt2->l->l=nn(8);
        
        if(isomorphic(rt1,rt2))
            printf("\nIsomorphic\n");
            
         else
            printf("\nNon Isomorphic\n");       
    }
struct BT *nn(int d)
    {
    
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        
        
        return root;
        
  
    }
    
 int isomorphic(struct BT *n1,struct BT *n2)
    {
        if(!n1 && !n2)
            return 1;
            
         if((!n1&&n2) ||(n1&&!n2))
            return 0;
           if(n1->data!=n2->data)
            return 0; 
            
           return((isomorphic(n1->l,n2->l)&&isomorphic(n1->r,n2->r))||(isomorphic(n1->l,n2->r)&&isomorphic(n1->r,n2->l)));    
    
    
    
    }   
    
    
