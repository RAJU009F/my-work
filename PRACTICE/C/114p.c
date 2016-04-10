/*  finding sum path and checking balanced and  DOUBLE TREE , MAX Width*/

#include<stdio.h>
#include<stdlib.h>


struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;        
    };
    
int height(struct BT *root)
    {
        if(!root)
            return 0;
         else
            return max(height(root->l),height(root->r))+1;   
    
    }    
    
int max(int a,int b)
    {
    
    return a>=b?a:b;
    
    }
int balanced(struct BT *root)
    {
        if(!root)
            return 1;
        int lh=height(root->l);
        int rh=height(root->r);
        if(abs(lh-rh)<=1 && balanced(root->l) && balanced(root->r))
            return 1;
    
      return 0;       
    
    
    
    }
    
void getmaxw(struct BT *root)
    {
        if(!root)
            return;
            
          int h=height(root);
          int i;
          int maxw=0;
          for(i=0;i<h;i++)
            {
                int w=getwidth(root,i);
                if(maxw<w)
                    maxw=w;
            }  
           printf("\n\nmaxwidth:%d\n\n",maxw); 
    
    }    
   int getwidth(struct BT *root,int level)
    {
        if(!root)
            return 0;
            
        if(level==0)
            return 1;
         return getwidth(root->l,level-1)+getwidth(root->r,level-1);
                
    
    
    } 
int isbalanced(struct BT *root,int *h)
    {
        int lh=0,rh=0;
        int le=0,re=0;
        
        if(!root)
           { *h=0;
            return 1;}
            
           le=isbalanced(root->l,&lh);
           re=isbalanced(root->r,&rh);
           
           *h=(lh>rh?lh:rh)+1;
           if(lh-rh>=2||rh-lh>=2)
                return 0;
            else
                return le&&re;    
            
    
    
    } 
    
       
    
int hassum(struct BT *root,int sum)
    {
        if(!root)
            return(sum==0);
        int remsum=sum-root->data;
     return (hassum(root->l,remsum)||hassum(root->r,remsum));
                    
    
    
    } 
    struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->l= NULL;
        root->r=NULL;
        root->data=d;
        
        return root;
    
    } 
    
void doubletree(struct BT *root)
    {
        if(!root)
            return;
            
         doubletree(root->l);
         doubletree(root->r);   
            
         struct BT *oldleft=root->l;
         root->l=nn(root->data);
         root->l->l=oldleft;
         
         struct BT *oldright=root->r;
         root->r=nn(root->data);
         root->r->r=oldright;   
    
    
    }  
    
void printinorder(struct BT *root)
    {
        if(root)    
        {
            printinorder(root->l);
            printf("[%d]\t",root->data);
            printinorder(root->r);
            
        
        
        }
    
    
    }         
    

    
main()
    {
    
        struct BT *rt=nn(5);
        rt->l=nn(9);
        rt->r=nn(4);
        rt->l->l=nn(6);
        //rt->l->r=nn(3);
        //rt->l->r->l=nn(5);
        //rt->r->l=nn(4);
        //rt->r->r=nn(454);
       
        //rt->l->r->l->r=nn(454);
       // rt->l->r->r=nn(454);        
        if(balanced) 
            printf("Balanced\n\n");
        else
            printf("not Balanced\n\n"); 
            
            if(isbalanced) 
            printf("Balanced\n\n");
        else
            printf("not Balanced\n\n");  
            
         if(hassum(rt,11))
            printf("has pathsum\n\n\n");
         else
            printf("no pathsum\n\n\n\n"); 
           
        printinorder(rt);
        printf("\n\n");     
        doubletree(rt);
        
        printinorder(rt);
        printf("\n\n");
        
      getmaxw(rt);
        //printf("%d",)                     
    }    
       
    
        
        
