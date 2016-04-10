#include<iostream>
#include<queue>
using namespace std;

struct SLL
    {
        struct SLL *next;
        int data;    
    };
struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    };
void insert(struct  SLL **,int );
void buildBT(struct BT **,struct SLL *);

struct BT *nn(int );

void printinorder(struct BT *);

int height(struct BT *);


main()
    {
        struct SLL *h=NULL;
        insert(&h,9);
        insert(&h,8);
        insert(&h,7);
        insert(&h,6);
        insert(&h,5);
        insert(&h,4);
        insert(&h,3);
        insert(&h,2);
        insert(&h,1);
        
        struct BT *rt;
        
        buildBT(&rt, h);
        
        printinorder(rt);
        
       cout<<"\n"<<height(rt)<<endl;
    
    
    }
    
 void insert(struct SLL **head,int d)
    {
        struct SLL *t=new SLL;
        t->data=d;
        t->next=*head;
        *head=t;
    
    
    }   
struct BT *nn(int d)
    {
        struct BT *root=new BT;
        
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        
        return root;
    
    
    
    }
void buildBT(struct BT **root,struct SLL *head)

    {
    
        if(!head)
    
            {
                *root=NULL;
                return;
            
            }
            
         *root=nn(head->data);
         
         head=head->next;
         queue<BT *>Q;
         
         Q.push(*root);
         
         while(head)
            
            {
                struct BT *p=Q.front();
                Q.pop();
                
                struct BT *left=NULL,*right=NULL;
                left=nn(head->data);
                Q.push(left);
                head=head->next;
                if(head)
                    {
                        right=nn(head->data);
                        Q.push(right);
                        head=head->next;
                    
                    }
                p->l=left;
                p->r=right;      
            }
            
    }
    
void printinorder(struct BT *root) 
    {
        if(root)
            {
               cout<<"\t"<<root->data;
                printinorder(root->l);
             
                printinorder(root->r);
            
            
            }
    
    
    }   
    
int height(struct BT *root)
    
    {
    
        if(!root)
            return 0;
            
            
            int h=0;
            queue<BT *>q;
            q.push(root);
            
           while(1)
            {
                int nodecount=q.size();
                if(nodecount==0)
                    return h;
                 h++;
                 
                 while(nodecount>0)
                    {
                        struct BT *temp=q.front();
                        q.pop();
                        
                        if(temp->l)
                                q.push(temp->l);
                        if(temp->r) 
                                q.push(temp->r);
                                
                         nodecount--;              
                        
                    
                    }   
            
            
            
            
            
            }
    
    
    
    
    
    
    
    
    
    }
