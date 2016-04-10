/*to check pair exist or not */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100


struct BST
    {
        struct BST *l;
        struct BST *r;
        int data;
    
    };

struct S
    {
        int size;
        int top;
        struct BST *a[];
    
    
    };
struct BST *nn(int );
struct BST *insert(struct BST *,int);


struct S *createS(int s);
int isEmpty(struct S *);
int isFull(struct S *);
void push(struct S *,struct BST *);
struct BST *pop(struct S *);

void haspair(struct BST *,int);


main()
    {
        struct BST *rt=NULL;
        
        rt=insert(rt,6);
        insert(rt,7);
        insert(rt,1);
        insert(rt,2);
        insert(rt,3);
        insert(rt,4);
        insert(rt,7);
        insert(rt,8);
        insert(rt,9);
        insert(rt,10);
        insert(rt,12);
        insert(rt,13);
        int n;
        printf("\nEnter n:");
        scanf("%d",&n);
        haspair(rt,n);
          
    
    
    
    }
    
struct BST *insert(struct BST *root,int d)
    {
        if(!root)
            return(nn(d));
            
            if(root->data>d)
                root->l=insert(root->l,d);
             if(root->data<d)
                root->r=insert(root->r,d);
                
          return root;         
    
    
    }
struct BST *nn(int d)
    {
        struct BST *root=(struct BST *)malloc(sizeof(struct BST));
        root->data=d;
        root->l=root->r=NULL;
        return root;
    
    
    
    }  
    
 void haspair(struct BST *root,int x)
    {
        if(!root)
            return;
            
          struct BST *r1=root;
          struct BST *r2=root;
          
          int v1,v2;
          struct S *s1=createS(MAX);
          struct S *s2=createS(MAX);
          
          int d1=0,d2=0;
          while(1)
            {
            
                    while(!d1)
                        {
                            if(r1)
                              {
                                 push(s1,r1);
                                 r1=r1->l;
                              }  
                              
                              else
                                {
                                    if(isEmpty(s1))
                                       d1=1;
                                        
                                    r1=pop(s1);
                                    v1=r1->data;
                                   
                                       d1=1; 
                                
                                
                                }
                        
                        
                        }
                        
                      while(!d2)
                        {
                            if(r2)
                                {
                                    push(s2,r2);
                                    r2=r2->r;
                                    
                                
                                }
                                
                             else
                                {
                                    if(isEmpty(s2))
                                        d2=1;
                                        
                                        r2=pop(s2);
                                        v2=r2->data;
                                        
                                        d2=1;
                                
                                }   
                        
                        
                        
                        }  
            
                    if(v1+v2==x && r1!=r2)
                        {
                            printf("pair %d + %d\n",v1,v2);
                            return;
                        
                        
                        }
                     else if(v1+v2>x)
                        {
                            d2=0;
                            r2=r2->l;
                        
                        }
                      else 
                           { 
                           
                           d1=0;
                           r1=r1->r;
                           
                           } 
                        
                if((r1==NULL && isEmpty(s1))|| (r2==NULL && isEmpty(s2)) )
                    {
                         printf("pair doesnt exist");
                         return;
            
                    }
            
            }  
    
    
    
    
    }    
    
 struct S *createS(s)
    {
    
        struct S *stack=(struct S *)malloc(sizeof(struct S ));
            stack->top=-1;
            stack->size=s;
           *stack->a=(struct BST **)malloc(stack->size*sizeof(struct BST *));
            
            
         return stack;   
    }    
        
    
void push(struct S *stack,struct BST *root)
    {
       if(isFull(stack))
            return;
            
        stack->a[++stack->top]=root;    
    }
        
  int isFull(struct S *stack)
    { 
    
    return (stack->top==stack->size-1);
            
     } 
     
struct BST *pop(struct S *stack)
    
    {
        if(isEmpty(stack))
            return NULL;
            
         return stack->a[stack->top--];   
    
    
    }     
    
int isEmpty(struct S *stack)
    {
    
        return (stack->top==-1);
    
    }    
    
