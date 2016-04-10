#include<stdio.h>
#include<stdlib.h>

struct BST
    {
        struct BST *l;
        struct BST *r;
        int data;
    
    };

struct BST *nn(int);
struct BST *insert(struct BST *,int );
void printpre(struct BST *);

int min(struct BST *);


main()
    {
    
    struct BST *rt=NULL;
    int N;
    
    printf("\nEnter size of BST:");
    scanf("%d",&N);
    int i=0;
    rt=insert(rt,16);
    for(i=5;i<=5*N;i+=5)   
        insert(rt,i);
    
    printpre(rt);
    printf("\n\n");
    
    int m=min(rt);
    printf("\t\t\tmin:[%d]",m);
    printf("\n\n");
    
    
    
    }
    
    
 struct BST *nn(int d)   
    
        {
        struct BST *t=(struct BST *)malloc(sizeof(struct BST));
        t->data=d;
        t->l=NULL;
        t->r=NULL;
        
        }
 struct BST *insert(struct BST *root,int d)
    {
        if(!root)
            return(nn(d));
            
         if(root->data>=d)
            root->l=insert(root->l,d);  
         else
            root->r=insert(root->r,d);    
    
        return root;
    
    }
    
 void printpre(struct BST *root)
    {
        if(root)
            {
                printf("[%d]\t",root->data);
                printpre(root->l);
                printpre(root->r);
            
            
            
            }
    
    }   
    
int min(struct BST *root)

    {
        if(!root)
            return 0;
            
         while(root->l)
            root=root->l;   
    
        return root->data;
    
    }    
