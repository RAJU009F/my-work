/*Q iplemetation */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;
    };
    
 struct Q
    {
        int fr,rr;
        int size;
        struct BT *a[];
    
    
    };   
    
struct Q *createQ( int );    
struct BT *dq(struct Q *);
void nq(struct Q *,struct BT *);
int isFull(struct Q *);
int isEmpty(struct Q *);
int hassingle(struct Q *);

struct BT *get(struct Q *);
int hasdouble(struct BT *);

struct BT *nn(int);
void insert(struct BT **,struct Q *,int);

void printlevel(struct BT *);

main()
    {
    
        struct Q *queue=createQ(MAX);
    
        struct BT *rt=NULL;
        
        int i;
        for(i=0;i<10;i++)
            insert(&rt,queue,i);
            
            
    
        printlevel(rt);
        printf("\n");
    
    
    
    
    } 
    
struct Q *createQ(int s)
    {
        struct Q *q=(struct Q *)malloc(sizeof(struct Q));
        q->size=s;
        q->fr=q->rr=-1;
        *q->a=(struct BT **)malloc(sizeof(struct BT *)*s);
        int i=0;
        for(i;i<s;i++)
            {
                q->a[i]=NULL;
            
            }
            
         return q;   
        
    } 
    
void nq(struct Q *q,struct BT *root)
    {
        if(isFull(q))
            return;
         q->a[++q->rr]=root;
         
         if(q->fr==-1)
            ++q->fr;   
            
    
    
    }     
    
struct BT *dq(struct Q *q)
    {
        if(isEmpty(q))
            return;
            
         struct BT *t=q->a[q->fr];
         
         if(q->rr==q->fr)
            q->rr=q->fr=-1;
          else
            ++q->fr;
            
          return t;       
    
    
    
    }  
    
int isEmpty(struct Q *q)
    {
    
        return q->fr==-1;
    }
    
 int isFull(struct Q *q)
    {
        return q->rr==q->size-1;
    
    }   
    
int hassingle(struct Q *q)
    {
    
        return (q->fr==q->rr);
    
    }
    
struct BT *get(struct Q *q)
    {
        if(isEmpty(q))
            return NULL;
            
        return q->a[q->fr];
    
    
    }    
    
  
  
void insert(struct BT **root,struct Q *q,int d)
    {
        struct BT *temp=nn(d);
        
        if(!*root)
            *root=temp;
            
         else
            {
                struct BT *front=get(q);
                
                if(!front->l)
                    front->l=temp;
               else  if(!front->r)
                    front->r=temp;  
                     
                if(hasdouble(front))
                    dq(q);
            
            }
            
           nq(q,temp);    
     
    } 
    
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->data=d;
        root->l=root->r=NULL;
        return root;
    
    
    } 
    
 int hasdouble(struct BT *root)
    {
    
        return (root && root->l && root->r);
    
    }  
    
void printlevel(struct BT *root)
    {
    
        if(!root)
            return;
            
          struct Q *q=createQ(MAX);
          nq(q,root);
          
          while(!isEmpty(q))
            {
                root=dq(q);
                printf("[%d]\t",root->data);
                
                if(root->l)
                    nq(q,root->l);
                if(root->r)
                    nq(q,root->r);    
            }   
    }                           
