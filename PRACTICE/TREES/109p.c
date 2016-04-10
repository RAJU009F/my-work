/*finding  floor and ceil */

#include<stdio.h>
#include<stdlib.h>

struct BST 
    {
        struct BST *l;
        struct BST *r;
        int data;
    
    
    };
    
struct BST *nn(int);
struct BST *insert(struct BST *,int);

int Ceil(struct BST *,int);
int Floor(struct BST *,int);

void printinorder(struct BST *);

void addsum(struct BST *,int *);
main()
    {
    struct BST *rt=NULL;
    
        rt=insert(rt,5);
        insert(rt,64);
        insert(rt,23);
        insert(rt,2);
        insert(rt,3);
        insert(rt,4);
        
        int i=0;
        printf("INPUT\tFLOOR\tCEIL\n");
        for(i=0;i<=34;i++)
            {
                int c=Ceil(rt,i);
                int f=Floor(rt,i);
                 printf(" [%d]\t[%d]\t[%d]\n",i,f,c);   
            
            }
        
    
    printf("\nInoredr:\n");
    printinorder(rt);
    int sum=0;
    addsum(rt,&sum);
    printf("\nInoredr:\n");
    printinorder(rt);
    printf("\n");
    }
    
    
 struct BST *nn(int d)
    {
        struct BST *root=(struct BST *)malloc(sizeof(struct BST));
        root->data=d;
        root->l=root->r=NULL;
        
        return root;
    
    
    }   
struct BST *insert(struct BST *root,int d)
    {
        if(!root)
            return nn(d);
         if(root->data>d)
            root->l=insert(root->l,d);
               
          else
            root->r=insert(root->r,d);
            
            
            return root;   
    } 
    
int Ceil(struct BST *root,int input)
    {
        if(!root)
            return -1;
            
         if(root->data==input)
            return root->data;
            
         if(root->data<input)
            return Ceil(root->r,input);
            
          int c=Ceil(root->l,input);
          return c>=input?c:root->data;        
    
    
    
    
    }    
   
int Floor(struct BST *root,int input)
    {
        if(!root)
            return -1;
            
            if(root->data==input)
                return root->data;
                
             if(root->data>input)
                return Floor(root->l,input);
                
             int f=Floor(root->r,input);
             return f>=input?f:root->data;      
    
    
    
    }   
    
void addsum(struct BST *root,int *s)
    {
    
    
    
        if(root)
            {
            
                addsum(root->r,s);
                
                *s=*s+root->data;
                root->data=*s;
                addsum(root->l,s);
            
            
            
            
            }    
    }    
       
void printinorder(struct BST *root)
    {
    
        if(root)
            {
               printf("[%d]\t",root->data);
                printinorder(root->l);                
                printinorder(root->r);
            
            
            }
    
    
    
    
    }    
