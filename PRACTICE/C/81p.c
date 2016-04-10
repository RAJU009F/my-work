#include<stdio.h>
#include<stdlib.h>

struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };
    
struct BT *nn(int);
void printarray(int *,int);
void printpath(struct BT *,int *,int);
struct BT *lca(struct BT *,struct BT *,struct BT *);

void  printlevel(struct BT *,int);    

main()
    {
        struct BT *rt=NULL;
        rt=nn(4);
        rt->l=nn(5);
        rt->r=nn(8);
        rt->l->l=nn(10);
        rt->r->l=nn(11);
        rt->l->r=nn(65);
        rt->r->r=nn(5656);
        
        rt->l->l->l=nn(67);
        rt->l->l->r=nn(167);
        rt->r->r->l=nn(454);
        
        int path[1000];
        
        printpath(rt,path,0);
        int i=0;
        for(i=0;i<8;i++)
            {printlevel(rt,i);
            printf("\n");
            }
    
    struct BT *t=lca(rt,rt->r->r->l,rt->r->l);
    printf("LCA is:[%d]\n",t->data);
    
    
    }
   
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        return root;
    
    }
    
    
 void printpath(struct BT *root,int p[],int level)
    {
        if(!root)
            return;
            
           p[level]=root->data;
           level++; 
            
         if(!root->l && !root->r)
            printarray(p,level);  
            
          else
            {
                printpath(root->l,p,level);
                printpath(root->r,p,level);
            
            }   
    
    
    
    
    
    }   
    
void printarray(int p[],int n)
    {
    
        int i;
        for(i=0;i<n;i++)
            {
                printf("[%d]\t",p[i]);
            
            
            }
            
            printf("\n");
    
    }       
    
void printlevel(struct BT  *root, int level)
    {
    
        if(!root)
        
            return;
            
         if(level==0)   
            printf("[%d]\t",root->data);
            
          else if(level%2==0)
              {  printlevel(root->l,level-1);
                printlevel(root->r,level-1);
               }          
               
           else 
            {
                printlevel(root->r,level-1);
                printlevel(root->l,level-1);
            
            
            }    
    
    }
    
struct BT *lca(struct BT *root,struct BT *f,struct BT *s)
    {
        if(!root)
            return;
            
         if(root==f || root==s)   
                return root;
                
          struct BT *left=(root->l,f,s);
          struct BT *right=(root->r,f,s);      
        if(left&&right)
            return root;
         else if(left)
            return left;
          else if(right)
            return right;  
        else
          return NULL;            
    
    
    }    
    
    

