#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct T
    {
        struct T *l;
        struct T *r;
        int data;
    
    };

struct T *nn(int );
int h(struct T *);
void print(struct T *);
void printlevel(struct T *,int);

struct T** createQ(int *,int *);
void nQ(struct T **,int *,struct T *);
struct T *dQ(struct T **,int *);

void printlevelorder(struct T *);

void printa(int *,int);
void printpath(struct T * );
void printpathr(struct T *,int *,int);



main()
    {
    
       struct T *rt=NULL;
       printf("\nEnter size:");
       rt=nn(4);
       rt->l=nn(6);
       rt->r=nn(7);
       rt->l->l=nn(8);
       rt->l->r=nn(9); 
       rt->r->l=nn(18);
       rt->r->r=nn(19); 
       int l=h(rt->r);
       printf("\nHeight:%d\n\n",l);
       
       int i=0;
       //for(i=0;i<7;i++)        
            printlevel(rt,2);
            
         printf("\n");   
     // printlevelorder(rt);
     printpath(rt);
      printf("\n");      
    
    }
 struct T *nn(int d)
    {
        struct T *root=(struct T *)malloc(sizeof(struct T ));
        root->data=d;
        root->l=NULL;
        root->r=NULL;
    
    
        return root;
    
    
    }   
    
 void print(struct T *root)
    {
        if(root)
            {
                printf("[%d]",root->data);
                print(root->l);
                print(root->r);
            
            
            }
    
    }   
    
int h(struct T *root)
    {
        if(!root)
            return 0;
            
           int left=h(root->l);
           int right=h(root->r);
           
           if(left>right)
                return left+1;
            else
                return right+1;         
    }    
    
void printlevel(struct T *root,int lev)
    {
        if(!root)
            return;
        if(lev==0)
            printf("[%d]\t",root->data);
            
         else
            printlevel(root->l,lev-1);
            printlevel(root->r,lev-1);   
    
    }    
    
    
 void printlevelorder(struct T *root)
    {
        if(!root)
            return;
            int fr,rr;
        struct T **Q=createQ(&fr,&rr);
        struct T *temp=root;
        //nQ(temp);
        while(temp)
            {
                printf("[%d]\t",temp->data);
                if(temp->l)                    
                    nQ(Q,&rr,temp->l);
                 if(temp->r)
                    nQ(Q,&rr,temp->r);
                    
                 temp=dQ(Q,&fr);      
            
            
            
            }                              
    }   
    
    
 struct T** createQ(int *fr,int *rr)
    {
        *fr=*rr=0;
        struct T **Q=(struct T **)malloc(sizeof(struct T *)*MAX);
        return Q;
    
    
    }   
void nQ(struct T **Q,int *rr,struct T *node) 
    {
        Q[*rr]=node;
        (*rr)++;
    
    }   
struct T *dQ(struct T **Q,int *fr)
    {
       
        return Q[*fr]; 
         (*fr)++;
    
    
    }    
    
void printpath(struct T *root)
    {
        int path[1000];
        printpathr(root,path,0);
    
    
    }    
    
void printpathr(struct T *root,int path[],int plen)
    {
    
        if(root==NULL)
            return;
            
         path[plen]=root->data;
         plen++;
         if(!root->l&&!root->r)
            printa(path,plen);
         else
            {
                printpathr(root->l,path,plen);
                printpathr(root->r,path,plen);
            
            }   
            
    
    
    }    
    
 void printa(int path[],int len)
    {
        int i=0;
        
        for(i=0;i<len;i++)
            printf("[%d]\t",path[i]);
            
         printf("\n\n");   
    
    
    }   
    
