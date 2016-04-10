/*construction of tree from its pre and post and in orders*/

#include<stdio.h>
#include<stdlib.h>

struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };
    
    
struct BT *nn(int);
struct BT *buildTree(int *,int * ,int );   
struct BT *build(int *,int *,int * ,int ,int ,int); 
    
void printpost(struct BT *);
void printpre(struct BT *);
    
main()
    {
        int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
         int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
        struct BT *rt=buildTree(pre,post,10);
        
    printpost(rt);
    printf("\n\n\n");
    printpre(rt);
    printf("\n\n");
    
    
    
    }
    
struct BT *build(int pr[],int po[],int* in,int l,int s,int end)
    {
        if(s>=end || l>=s)
            return NULL;
            
            
         struct BT *root=nn(po[*in]);
         ++*in;
         
         if(l==s)
            return root;
            
            int i=l;
            for(i;i<=s;i++)
                {
                    if(po[i]==root->data)
                        break;
                }
                
               root->l=build(pr,po,in,l,i,end);
               root->r=build(pr,po,in,i+1,s,end);
               
               return root; 
            
    
    }  
    
 struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        
            root->data=d;
            root->l=root->r=NULL;
            return root;
    
    
    }  
    
void printpost(struct BT *root)
    {
        if(root)
            {
                printpost(root->l);
                printpost(root->r);
                printf("[%d]\t",root->data);
            
            
            }
    
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
    
 struct BT *buildTree(int pre[],int post[],int s)
    {
        int prein=0;
        
        return build(pre,post,&prein,0,s-1,s);
    
    }     
