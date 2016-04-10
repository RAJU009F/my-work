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
        int top;
        int size;
        struct BST *a[]; 
    
    
    };
    
struct S *createS(int si)
    {
    
        struct S *s=(struct S *)malloc(sizeof(struct S));
        s->size=si;
        s->top=-1;
        *s->a=(struct BST *)malloc(sizeof(struct BST  )*si);
        
        return s;
    
    }    
    
 int isEmpty(struct S *s)
 
    {
       return s->top==-1;
    }
    
 int isFull(struct S *s)
    {
    
     return s->top==s->size-1;
     
    }   
 
 void push(struct S *s,struct BST *root)       

    
    {
        if(isFull(s))
            return;
            
         s->a[++s->top]=root;   
    
    
    
    }
    
struct BST *pop(struct S *s)    
    {
        if(isEmpty(s))
            return NULL;
            
         else
            return s->a[s->top--];   
    
    
    }
    
void  inorder(struct BST *root)
    {
        if(root)    
            {
                inorder(root->l);
                
                printf("[%d]\t",root->data);
                inorder(root->r);
            
            
            }
    
    }    
    
void merge(struct BST *root1 , struct BST *root2)    
        {
            struct S *s1=createS(MAX);
            struct S *s2=createS(MAX);
            
          
            if(!root2)
               {
                    inorder(root1);
                    return;
                }    
                
             if(!root1)   
                 {
                    inorder(root2);
                    return;
                 }       
             while(root1 || root2|| !isEmpty(s1)|| !isEmpty(s2))
                {
                
                    if(root1 || root2)  
                        {
                        
                            if(root1)
                                {
                                    push(s1,root1);
                                    root1=root1->l;
                                
                                }
                            if(root2)
                                {
                                    push(s2,root2);
                                    root2=root2->l;
                                }    
                        
                        
                        }
                     else
                        {
                        
                            if(isEmpty(s1))
                                {
                                    while(!isEmpty(s2))
                                        {
                                            root2=pop(s2);
                                            root2->l=NULL;
                                            inorder(root2);
                                        
                                        
                                        }
                                      return;  
                                
                                }
                                if(isEmpty(s2))
                                    {
                                        while(!isEmpty(s1))
                                            {
                                                root1=pop(s1);
                                                root1->l=NULL;
                                                inorder(root1);
                                            
                                            }
                                          return;  
                                    
                                    
                                    }
                                    
                                root1=pop(s1);
                                root2=pop(s2);
                                
                                if(root1->data<root2->data)
                                    {
                                        printf("[%d]\t",root1->data);
                                        root1=root1->r;
                                        push(s2,root2);
                                        root2=NULL;
                                    
                                    
                                    }
                                   else
                                    {
                                        printf("[%d]\t",root2->data);
                                        root2=root2->r;
                                        push(s1,root1);
                                        root1=NULL;    
                                    
                                    }     
                        
                        }                   
                }   
        
        
        } 
 
struct BST *nn(int d)
    {
        struct BST *root=(struct BST *)malloc(sizeof(struct BST ));
        root->l=root->r=NULL;
        root->data=d;
        
        return root;
    
    } 
        
 main()
    {
        struct BST *rt1=nn(5);
        rt1->l=nn(2);
        rt1->l->l=nn(1);
        rt1->l->r=nn(4);
        
        rt1->r=nn(8);
        rt1->r->l=nn(6);
        rt1->r->r=nn(12);
     struct BST *rt2=nn(15);
        rt2->l=nn(12);
        rt2->l->l=nn(3);
        rt2->l->r=nn(14);
        
        rt2->r=nn(18);
        rt2->r->l=nn(16);
        rt2->r->r=nn(120);
    
        merge(rt1,rt2);
    
    
    }  
    
         
