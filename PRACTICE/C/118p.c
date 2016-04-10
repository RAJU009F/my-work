#include<stdio.h>
#include<stdlib.h>


struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    };
    
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
        root->l=root->r=NULL;
        root->data=d;
               
    
    } 
void getmaxleaf(struct BT *root,struct BT **ref,int cur,int *m)
    {
       if(!root)
            return;
            
          cur=cur+root->data;  
       
        if(!root->l&& !root->r)
           {
            if(cur>*m)
            {
                     *ref=root;
                     *m=cur;
            }
           }
           
           getmaxleaf(root->l,ref,cur,m);
           getmaxleaf(root->r,ref,cur,m);
    
    
    }    
int printpath(struct BT *root,struct BT *leaf)
    {
        if(!root)
            return 0;
            
            if(root==leaf || printpath(root->l,leaf)||printpath(root->r,leaf))
                {
                    printf("[%d]\t",root->data);
                    return 1;
                
                }
    
        return 0;
    
    }     
    
int getmax(struct BT *root)
        
    {
        if(!root)
            return 0;
            
         struct BT *maxleaf;
         int maxsum=0;
         getmaxleaf(root,&maxleaf,0,&maxsum);
         
         printpath(root,maxleaf);
         
         return maxsum;
                
    
    
    }    
main()
    {
    
        struct BT *rt=nn(7);
        rt->l=nn(34);
        rt->l->r=nn(-2);
        rt->l->l=nn(67);
        rt->r=nn(12);
        rt->r->r=nn(34);
        rt->r->l=nn(23);                           
        
       int max=getmax(rt);
       
       printf("max sum:: %d \n\n\n",max);
       
        
    
    
    
    
    
    }    
    
    
