/*stack implementation */


#include<stdio.h>
#include<stdlib.h>

#define MAX 50

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
    
    
struct S *createS(int );
void push(struct S *,struct BT *);
int isFull(struct S *);
int isEmpty(struct S *);
struct BT *pop(struct S *);
struct BT *Top(struct S *);

struct BT *nn(int);
void  postorder(struct BT *);
void  inorder(struct BT *);
void  preorder(struct BT *);
void post(struct BT *);

main()  
    {
        struct BT *rt=nn(45);
        rt->l=nn(43);
        rt->r=nn(23);
        rt->r->l=nn(34);
        
        rt->r->r=nn(46);
        rt->l->l=nn(454);
        rt->l->r=nn(4543);
        rt->l->r->l=nn(54);
        
        
     printf("\nInoredr:\n\n"); 
       
     inorder(rt);
     printf("\nPreorder:\n\n");
     preorder(rt);
     
     printf("\nPostorder:\n\n");
     post(rt);
     
    printf("\n\n\n");
    
    }

struct S *createS(int s)
    {
        struct S *stack=(struct S *)malloc(sizeof(struct S));
        stack->size=s;
        stack->top=-1;
        *stack->a=(struct BT **)malloc(s*sizeof(struct BT *));
        
        return stack;
    
    
    }
    
void push(struct S *stack,struct BT *root)
    {
    
        if(isFull(stack))
            return;
            
         stack->a[++stack->top]=root;   
    
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
        return (s->top==s->size-1);
    
    }   
    
struct BT *Top(struct S *s)
    {
        if(isEmpty(s))
            return NULL;
            
         return s->a[s->top];   
    
    
    }    
    
 struct BT *nn(int d)       
    {
    
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
        root->data=d;
        root->l=root->r=NULL;
        
        return root;
    
    }
    
void inorder(struct BT *root)
    {
        
          if(!root)
            return;
            
            struct S *s=createS(MAX);
         
            
            while(1)
                {
                    while(root)
                        {
                            
                            push(s,root);
                            root=root->l;
                            
                            
                    
                        
                        }
                            if(isEmpty(s))
                                break;
                            
                            root=pop(s);
                            printf("[%d]\t",root->data);
                            root=root->r;
                            
                
                }
                
        
    
    
    
    }    
    
    
 void preorder(struct BT *root)
    {
        if(!root)
            return;
            
            struct S *s1=createS(MAX);
            while(1)
                {
                    while(root)
                        {
                            printf("[%d]\t",root->data);
                            
                            push(s1,root);
                            root=root->l;
                        
                        }  
                     if(isEmpty(s1)) 
                             break;
                        
                     root=pop(s1);
                     root=root->r;                   
                
                }
    }   
 
void postorder(struct BT *root)
    {
        if(!root)
            return;
            
         struct S *s2=createS(MAX);
         
         while(1)
            {
            
                if(root)
                    {
                        push(s2,root);
                        root=root->l;
                    
                    
                    }
                    
                    else
                        {
                            if(isEmpty(s2))
                                break;
                            
                            else 
                            if(Top(s2)->r==NULL)
                        
                                 {
                                    root=pop(s2);
                                    printf("[%d]\t",root->data);
                                    
                                    if(root->r==Top(s2))
                                        {
                                            printf("[%d]\t",Top(s2)->data);
                                            pop(s2);
                                        
                                        
                                        }
                                
                                
                                }
                        
                        
                            if(!isEmpty(s2))
                                root=root->r;
                              else
                                root=NULL;  
                                
                        
                        
                        }            
            }   
       
    }    
   
   
void post(struct BT *root)
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
                      
                      if(root->r && Top(s)==root->r)
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
