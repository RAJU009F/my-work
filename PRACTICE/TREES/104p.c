/*construction of tree from its pre and post and in orders*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };
    
struct S
    {
        
        int size;
        int top;
        struct BT *a[];
    
    };    
    
struct BT *nn(int );
struct BT *build(int * ,int *,int ,int);
int search(int *,int ,int,int);


void printpre(struct BT *);
void printin(struct BT *);
void printpost(struct BT *);


struct S *createS(int);
void push(struct S *,struct BT *);
struct BT *pop(struct S *);
int isEmpty(struct S *);
int isFull(struct S *);
struct BT *Top(struct S *);

struct BT *buildBT(int *,int *,int,int);

main()
    {
    
        int post[]={8, 9, 4, 5, 2, 6, 3, 1,7};
        int pre[]={1, 2, 4, 8, 9, 5, 7,3, 6};
        int in[]={1,2,3,4,5,6,7,8,9};
        
    
        struct BT *rt=build(in,pre,0,9);
        
       printpre(rt);
        printf("\n\nInorder:\n");
        
       printin(rt);
       printf("\n\nPostorder:\n");
       printpost(rt);
       printf("\n"); 
        
        struct BT *r=buildBT(in,post,0,8);
        
       printpre(r);
        printf("\n\nInorder:\n");
        
       printin(r);
       printf("\n\nPostorder:\n");
       printpost(r);
       printf("\n"); 
    
    
    }  
    
 struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
        root->data=d;
        root->l=root->r=NULL;
        return root;
    
    
    }   
    
 struct BT *build(int in[],int pr[],int start,int end)
    {
       
               static int prein=0;
               if(start>=end)
                    return NULL;
              
               struct BT *root=nn(pr[prein]);
               ++prein;
               
               if(start==end)
                    return root;
                
                
                int inin=search(in,start,end,root->data);
                
                root->l=build(in,pr,start,inin-1);
                root->r=build(in,pr,inin+1,end);
                    
                
            
            return root;
            
           
    
    
    
    
    }     
    
 int search(int a[],int i,int n,int x)
    {
        int k;
        for(k=i;k<=n;k++)
            {
            
                if(a[k]==x)
                    return k;
            
            }
    
    
    }   
    
void printpre(struct BT *root)
    {
        if(!root)
            return;
            
        struct S *s=createS(MAX);
        
        while(1)
            {
                while(root)
                    {
                        push(s,root);
                        printf("[%d]\t",root->data);
                        root=root->l;
                    
                    }
                    
                    if(isEmpty(s))
                        break;
                    root=pop(s);
                    root=root->r;
                    
                    
            
            }
    
    }  
    
struct S *createS(int si)
    {
        struct S *s=(struct S *)malloc(sizeof(struct S));
        s->size=si;
        s->top=-1;
        *s->a=(struct BT **)malloc(sizeof(struct BT *)*si);
        return s;
    
    } 
    
 void push(struct S *s,struct BT *root)
    {
        if(isFull(s))
            return;
            
         s->a[++s->top]=root;   
    
    
    }  
struct BT *pop(struct S *s)
    {
        if(isEmpty(s))
            return NULL;
            
         return s->a[s->top--];   
        
    }    
    
 int isEmpty(struct S *s)
    {
        return s->top==-1;
    
    }   
    
 int isFull(struct S *s) 
    {
        return s->top==s->size-1;
    
    }  
          
  struct BT *Top(struct S *s)        
    {
        if(isEmpty(s))
            return NULL;
        else
            return s->a[s->top];   
    
    }
    
    
void printin(struct BT *root)   

    {
        if(!root)
            return;
            
            struct S *s=createS(MAX);
            while(1)
                {
                    if(root)
                        {
                            push(s,root);
                            root=root->l;
                        
                        }
                      else
                        {
                            if(isEmpty(s))
                                break;
                                
                             root=pop(s);
                             printf("[%d]\t",root->data);
                             root=root->r;   
                        
                        }  
                }
            
    
    }
    
void printpost(struct BT *root)
    {
        if(!root)
            return;
            
         struct S *s=createS(MAX); 
         
         do
            {
                while(root)
                    {
                        if(root->r)
                            push(s,root->r);
                        push(s,root);
                        
                        root=root->l;    
                            
                        
                    }
                root=pop(s);
                    
                    if(root->r&& Top(s)==root->r)
                        
                    {
                        pop(s);
                        push(s,root);
                        root=root->r;
                    
                    
                    }
                    
                    else
                        {
                            printf("[%d]\t",root->data);
                            root=NULL;
                        
                        }
                
                
            
            }while(!isEmpty(s));
              
    
    
    
    } 
    
struct BT *buildBT(int in[],int p[],int start,int end)
    {
        if(start>end)
            return NULL;
            
            static int pin=0;
            
            struct BT *root=nn(p[pin]);
            pin;
            
            if(start==end)
                return root;
                
            int inin=(in,start,end,root->data);
            
            root->l=buildBT(in,p,start,inin-1);
            root->r=buildBT(in,p,inin+1,end);
            
            return root;    
    
    
    
    
    
    }           
