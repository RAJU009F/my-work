/*   CHECKING FOLDABLE AND PRINTING ASCENDING ORDER OF bst LEVEL ORDER AND    */
/*anceSTOR*/

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
    
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
        root->data=d;
        root->l=root->r=NULL;
        
        return root;
    
    }   
    
int isfoldable(struct BT *root)
    {
        if(!root)
            return true;
            
        return (isfold(root->l,root->r));    
    
    } 
    
int isfold(struct BT *a,struct BT *b)
    {
        if(!a&&!b)
            return true;
            
        if(!a|| !b)
            return  false;
            
        return isfold(a->l,b->r)&&isfold(a->r,b->l);    
               
    
    
    }
    
void printsort(int a[],int i,int n)
    {
        if(i<=n)
            {
                printsort(a,2*i+1,n);
                printf("%d\t",a[i]);
                printsort(a,2*i+2,n);
            
            
            }
    
    
    }
    
    
    struct BT *minv(struct BT *root)
    {
        struct BT *c=root;
        
        while(root->l)
            {
                root=root->l;
            }
        return root;
    
    }  
        
    
struct BT *successor(struct BT *root,struct BT *node)   
    {
        if(node->r)
            return minv(node->r);
        
                struct BT *s=NULL;
                while(root)
                    {
                        if(node->data<root->data)   
                            {
                                s=root;
                                root=root->l;    
                            
                            }
                         else if(node->data>root->data)
                            root=root->r;
                            
                           else
                            break;    
                    
                    }
            
            
            
            
            return s;    
    
    
    
    }   
    
   
    
main()
    {
    
        struct BT *rt=nn(4);
        rt->l=nn(3);
        rt->l->r=nn(3);
        rt->r=nn(54);
        rt->r->l=nn(50);
    if(isfoldable(rt))
        printf("\nyes Fold\n");
        
        
       else
        printf("\nNot\n\n\n"); 
        
      int a[]={4,2,5,1,3};
      
       int s=sizeof(a)/sizeof(a[1]);
       
       printsort(a,0,s-1);
       printf("\n\n");
       
       struct BT *t=successor(rt,rt->l->r);
       
       printf("succ[%d]\n\n",t->data);
    
    }            
