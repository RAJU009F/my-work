/* is BT is  BST or not */

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
    
struct S *createS(int si)
    {
        struct S *s=(struct S *)malloc(sizeof(struct S ));
        
        s->top=-1;
        s->size=si;
        *s->a=(struct BT **)malloc(sizeof(struct BT *)*si);
        
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
    
 struct BT *Top(struct S *s)
    {
        if(isEmpty(s))
            return NULL;
    
        return s->a[s->top];
    
    }
    
struct BT *nn(int d)
    {
        struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
            root->l=root->r=NULL;
            root->data=d;
            
            return root;
    
        
    } 
    
 void delete(struct BT *root)
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
    
void printarray(int a[],int n)
    {
        int i;
        printf("\n");
        for(i=0;i<n;i++)
            {
                printf("[%d]\t",a[i]);
            }
        printf("\n");
    }    
    
 void printpath(struct BT *root,int p[],int level) 
    {
        if(!root)
            return;
            
            p[level]=root->data;
            ++level;
            
            if(!root->l && !root->r)
                printarray(p,level);
                
            printpath(root->l,p,level);
            printpath(root->r,p,level);    
            
    
    }  
    
    
int countleafs(struct BT *root)
    {
    
        if(!root)
            return 0;
         if(!root->l &&!root->r )
            return 1;
            
       return   countleafs(root->l)+
          countleafs(root->r);     
            
  
    }   
    
int isBST(struct BT *root,int min,int max) 
    {
        if(!root)
             return 1;
             
          if(root->data<min || root->data>max)
                return 0;
                
           //if(root->data>min && root->data<max)               
                //return max;
                
            return (isBST(root->l,min,root->data-1)&&isBST(root->r,root->data+1,max));    
    
    }    
    
    
int  isbst(struct BT *root)
    {
    
        struct BT *prev=NULL;
        if(root)
            {
            
                    if(!isbst(root->l))
                        return 0;
                        
                     if(prev && root->data<=prev->data)
                        return 0;
                      prev=root;
                       return isbst(root->r);   
            
            
            
            }
    
    
    
    
    
    
        return 1;
    }  
    
void print(struct BT *root ,int level,int b)
    {
        if(!root)
            return;
            
            if(level==0)
                printf("[%d]\t",root->data);
             if(b)
                {
                    print(root->l,level-1,b);
                    print(root->r,level-1,b);
                
                }   
             else
                {
                    print(root->r,level-1,b);
                    print(root->r,level-1,b);
                
                }   
    
    
    }     
        
 main()
    {
        struct BT *rt=nn(5);
        rt->l=nn(4);
        rt->r=nn(6);
        rt->l->r=nn(35);
        rt->l->l=nn(45);
        rt->l->l->l=nn(453);
        
        rt->r->l=nn(32);
        rt->r->r=nn(4553);
        rt->r->l->l=nn(545234);
    
        delete(rt);
        
       int path[1000];
       int level=0;
            printpath(rt,path,level);
            
       printf("\n") ;
       
       int l=countleafs(rt);
       printf("%d\n",l);    
    
        if(isBST(rt,-1,600000))
            printf("bst\n");
         else
            printf("not BST\n"); 
            
        if(isbst(rt))
                printf("bst\n");
         else
            printf("not BST\n");  
            int i,b=0;
          for(i=0;i<4;i++)
                {
                    print(rt,i,b);
                    printf("\n\n\n");
                    
                    b=~b;
                }      
            
    }          
