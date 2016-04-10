/*CORRECTING THE SWAPPED bst  boundary of the tree*/
/* TO CHECK COMPLETE BINARY TREE */


#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct BST 
    {
        struct BST *l;
        struct BST *r;
        int data;
    
    };
    
struct Q
    {
        int size,rr,fr;
        struct BST *a[];
    };    
    
struct BST *nn(int d)
    {
        struct BST *root=(struct BST *)malloc(sizeof(struct BST));
        
        root->data=d;
        root->l=NULL;
        root->r=NULL;
    
    }   
    
 struct BST *insert(struct BST *root,int d)
    {
        if(!root)
            return nn(d);
            
        if(root->data>d)
            root->l=insert(root->l,d);
        if(root->data<d)
            root->r=insert(root->r,d);
            
          return root;  
                    
    
    
    
    }  
void correct(struct BST *root,struct BST **prev,struct BST **first,struct BST **middle,struct BST **last) 

    {
        if(root)
            {
                correct(root->l,prev,first,middle,last);
                    if(*prev && root->data < (*prev)->data)
                            {
                            
                                if(!*first)
                                    {
                                        *first=*prev;
                                        *middle=root;
                                    
                                    }
                                  else
                                    *last=root;  
                                    
                            
                            }  
                            
                           *prev= root;        
                    correct(root->r,prev,first,middle,last);
            
            }    
    }   
void printinorder(struct BST *root)
    {
        if(root)
            {
                printinorder(root->l);
                printf("[%d]\t",root->data);
                printinorder(root->r);
            
            
            }
    
    
    }    
 
 void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    
    }
void printleft(struct BST *root)
    {
        if(root->l)
            {
                printf("[%d]\t",root->data);
                printleft(root->l);
            
            }
          else if(root->r)
            {
                printf("[%d]\t",root->data);
                printleft(root->r);
            
            }  
    
    
    }
    
 void printright(struct BST *root)
    {
        if(root->r) 
            {
                printright(root->r);
                printf("[%d]\t",root->data);
            
            }
         else if(root->l)
            {
                printright(root->l);
                printf("[%d]\t",root->data);
                
            }   
    
    
    }  
    
void printleaves(struct BST *root)
    {
        if(root)
        {  
            printleaves(root->l); 
          if(!root->l && !root->r)
                printf("[%d]\t",root->data); 
            printleaves(root->r);     
            
       }   
    
   } 


 
 void printboundary(struct BST *root)
    {
        if(root)
            {
                printf("[%d]\t",root->data);
                printleft(root->l);
                
                printleaves(root->l);
                printleaves(root->r);
                
                printright(root->r);
            
            }
    
    
    
    }

struct Q *createQ(int si)
    {
        struct Q *q=(struct Q *)malloc(sizeof(struct Q));
        q->size=si;
        q->fr=q->rr=-1;
        *q->a=(struct BST **)malloc(sizeof(struct BST)*si);
        return q;
    
    }
struct BST  *dq(struct Q *q)
    {
        if(isEmpty(q))
            return NULL;
          struct BST *t=q->a[q->fr];
          if(q->fr==q->rr)
            q->fr=q->rr=-1;
           else
            ++q->fr; 
         return t;    
    
    }
    
void nq(struct Q *q,struct BST *root)
    {
        if(q->rr==q->size-1)
            return;
            
        q->a[++q->rr]=root;
        
        if(q->fr==-1)
            ++q->fr;    
    }
    
int isEmpty(struct Q *q)
    {
    
        return q->fr==-1;
    }        

    
int iscomplete(struct BST *root)
    {
        if(!root)
            return 1;
            
          struct Q *q=createQ(MAX);
          
          nq(q,root);
          int f=0;
          while(!isEmpty(q))
            {
                root=dq(q);
                if(root->l)
                    {
                        if(f)
                            return 0;
                              
                        
                    nq(q,root->l);
                    }
                    
                  else  
                    f=1;
                 if(root->r)
                    {
                        if(f)
                            return 0;
                    
                        nq(q,root->r);
                    }     
                  else
                    f=1;  
            
            
            } 
            return 1;     
    }


    
    
 
 main()
    {
        struct BST *rt=NULL;
            rt=insert(rt,5);
            insert(rt,59);
            insert(rt,3);
            /* insert(rt,4);
           insert(rt,20);
            insert(rt,2);
           insert(rt,12);
           insert(rt,67);
            insert(rt,334);
            insert(rt,44);
            insert(rt,454);
            insert(rt,54);
            insert(rt,0);
            insert(rt,1);
            insert(rt,50);*/
            printinorder(rt);
            printf("\n\n");
            struct BST *prev,*first,*middle,*last;
            prev=first=middle=last=NULL;
            correct(rt,&prev,&first,&middle,&last);
            
            if(first && last)
                swap(&(first->data),&(last->data));
                
            if(first && middle)
                swap(&(first->data),&(middle->data));    
            
            printinorder(rt);
            printf("\n\n");
            
         printf("\n\nBoundary Elements:\n\n"); 
         printboundary(rt);  
         
        if(iscomplete(rt))
            printf("Complete");
         else
            printf("NON complete");    

     }    
    
