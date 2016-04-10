/* zigzag printing of level by level and children sum property and convert to children sum property*/
/*diameter*/
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
        
        int top,size;
        struct BT *a[];
    
    
    };
    
struct S *createS(int si)
    {
        struct S *s=(struct S *)malloc(sizeof(struct S ));
        s->size=s;
        s->top=-1;
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
        else
            return  s->a[s->top];
    
    }        
    
 struct BT *nn(int d)
    {
        struct BT *root=(struct  BT *)malloc(sizeof(struct BT ));
        root->data=d;
        root->l=root->r=NULL;
        
        return root;
    
    
    }   
    
void zigzagr(struct BT *root,int level,int b)
    {
        if(!root)
            return;
            
           if(level==0)
                printf("[%d]\t",root->data);
            if(b)
                {
                
                    zigzagr(root->l,level-1,b);
                    zigzagr(root->r,level-1,b);
                    
                
                }     
            else
                {
                    zigzagr(root->r,level-1,b);
                    zigzagr(root->l,level-1,b);
                
                }
    
    
    
    }    
    
void swap(struct S *s1,struct S *s2)
    
    {
        struct S *s3=s1;
        s1=s2;
        s2=s3;
    
    
    }

    
 void zigzag(struct BT *root)
    {
    
        if(!root)
            return;
            
         struct S *s1=createS(MAX);
         struct S *s2=createS(MAX);
         int right=1 ;  
            push(s1,root);
            while(!isEmpty(s1))
                {
                
                    root=pop(s1);
                    printf("[%d]\t",root->data);
                   
                   if(root)
                    {
                    if(right)
                        {
                            if(root->l)
                                push(s2,root->l);
                            if(root->r)
                                push(s2,root->r);    
                        
                        
                        }
                      else
                        {
                            if(root->r)
                                push(s2,root->r);
                            if(root->l)
                                push(s2,root->l);     
                        
                        }  
                }
                
                if(isEmpty(s1))

                    {
                        right=1-right;
                       struct S *s3=s1;
                       s1=s2;
                       s2=s3;
                        printf("\n");
                    
                    }                
                
                }
    
    
    } 
    
int hassumproperty(struct BT *root)
    {
        int left=0,right=0;
        
        if(!root || (!root->l&&!root->r))
            return 1;
            
         else
            {
                if(root->l)
                  left=root->l->data;
                if(root->r)
                  right=root->r->data;
                if((root->data==  right+left)&&hassumproperty(root->r)&&hassumproperty(root->r))
                    return 1;         
                else
                    return 0;            
            }       
    } 
    
 void increment(struct BT *root,int d)  
    {
        if(root->l)
            {
                root->l->data=root->l->data+d;
                increment(root->l,d);
            
            }
            
         else
            {
                root->r->data=root->r->data+d;
                increment(root->r,d);
            
            
            }   
    
    
    }   
    
void convert(struct BT *root)
    {
        if(!root ||(!root->l && !root->r))
            return;
           
           else
           { convert(root->l);
            convert(root->r);
            int left=0,right=0;
            if(root->l)
                left=root->l->data;
             if(root->r)
                right=root->r->data;
            int diff=left+right-root->data;
            if(diff>0)
                root->data=root->data+diff;
            
            if(diff<0)
                {
                    increment(root,-diff);
                }       
    
         }
    } 
int diameter(struct BT *root,int *prev)
    {
        if(!root)
            return 0;
            
        int left=diameter(root->l,prev);
        int right=diameter(root->r,prev);
        
        if(left+right>*prev)
            *prev=left+right;
            
         return max(left,right)+1;   
    
    } 
    
 int max(int a,int b)
    {
    
    
    return a>=b?a:b;
    
    }            
    
main()
    {
    
        struct BT *rt=nn(4);
        rt->l=nn(5);
        rt->r=nn(89);
        rt->l->r=nn(77);
        rt->l->l=nn(55);
        rt->r->r=nn(44);
        rt->r->l=nn(22);
        rt->l->l->l=nn(30);
        rt->l->l->r=nn(43);
        int i,b=0;
        for(i=0;i<4;i++)
            {
             zigzagr(rt,i,b); 
             printf("\n\n");
             b=~b;
            }
            
       printf("\n\n\n\n");
       
       zigzag(rt);  
       
       printf("\n\n");
       
       if(hassumproperty(rt))
            printf("it has children sum property\n\n");
        else
            printf("it has no childeren sum  property\n\n");  
            
      // convert(rt);   
       
            if(hassumproperty(rt))
            printf("it has children sum property\n\n");
        else
            printf("it has no childeren sum  property\n\n"); 
           int p=0; 
           int d= diameter(rt,&p);
           printf("Diameter %d\n",d);
                  
    }      
    
