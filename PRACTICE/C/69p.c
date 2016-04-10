#include<stdio.h>

#include<stdlib.h>
#define MAX 100
int front,rear;

struct BT 
    {
    
    struct BT *l;
    struct BT *r;
    int data;
    
    
    };
    
struct BT *nn(int );    
void printlevelorder(struct BT *,int);

struct BT **createQ();
void nQ(struct BT **,struct BT * );
struct BT *dQ(struct BT **);
void printlevel(struct BT *);


void printarray(int * ,int);
void printpath(struct BT *,int *,int);



main()
    {
    
    
        struct BT *rt=NULL;
        rt=nn(95);
        rt->l=nn(90);
        rt->r=nn(99);
        rt->l->l=nn(91);
        rt->l->r=nn(92);
        rt->r->l=nn(98);
        rt->r->r=nn(97);
        rt->r->l->l=nn(96);
        rt->r->r->l=nn(100);
        rt->l->r->l=nn(1);
       
       
       
       int i;
       
        for(i=0;i<10;i++)
            {
                printlevelorder(rt,i);
                printf("\n");
            }    
            
      // printlevel(rt);
      int path[1000]; 
    printpath(rt,path,0);
    }
    
struct BT *nn(int d) 
    {
    
        struct BT *root=(struct BT *)malloc(sizeof(struct BT));
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        
        return root;       
        
        
    }   
 
void printlevelorder(struct BT *root,int level)
    {
        if(!root)
            return;
        if(level==0)
            printf("[%d]\t",root->data);
         else
            printlevelorder(root->l,level-1);
            printlevelorder(root->r,level-1);   
                
    }    
    
    
void printlevel(struct BT *root)
    {
        if(!root)
            return;
         struct BT **Q=createQ();
        printf("\n\n");
        nQ(Q,root);
         while(root)
            {
                 root=dQ(Q); 
                printf("[%d]\t",root->data);
                if(root->l)
                   { nQ(Q,root->l);}
                if(root->r)
                    nQ(Q,root->r);
                    
                      
            
            
            
            }   
          printf("\n\n");  
    
    
    
    }    
    
struct BT **createQ()
    {
    
        struct BT **q=(struct BT **)malloc(sizeof(struct BT *) * MAX);
        rear=0;
        front=0;
        return q;
    }    
void nQ(struct BT **q,struct BT *root)
    {
        
        q[rear]=root;
        rear++;
    
    
    }    
    
struct BT *dQ(struct BT **q)
    {
        
        struct BT *temp=q[front];
        
        front++;
        free( q[front]);
        return temp;
    
    
    } 
    
void printpath(struct BT *root,int p[],int level)
    {
        if(!root)
            return;
            
            p[level]=root->data;
            level++;
            if(!root->l&&!root->r)
                printarray(p,level);
                
             else
                {
                    printpath(root->l,p,level);
                    printpath(root->r,p,level);
                
                
                }   
    
    
    
    }   
    
 void printarray(int p[],int level)
    {
        printf("\n");
        int i=0;
        for(i=0;i<level;i++)
            {
                printf("[%d]\t",p[i]);
                
            
            
            }
         printf("\n");   
    
    
    }    
    
