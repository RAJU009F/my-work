/*  tree construction from linked list*/

#include<iostream>
#include<queue>


using namespace std;

struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    
    };

struct SLL
    {
        struct SLL *next;
        int data;
    
    };

void insert(struct SLL **,int);
struct BT *nn(int );
void build(struct BT **,struct SLL *);
void inorder(struct BT *);

int main()
    {
        struct SLL *h=NULL;
        insert(&h,5);
        insert(&h,6);
        insert(&h,98);
        insert(&h,456);
        insert(&h,90);
        insert(&h,78);
        
        struct BT *rt;
        build(&rt,h);
    
        inorder(rt);
    
    
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
void build(struct BT **root,struct SLL *head)
    {
        if(!head)
            {
                *root=NULL;
                return;
            
            }
            
            queue<BT *>Q;
            *root=nn(head->data);
            head=head->next;
            Q.push(*root);
            
            while(head)
                {
                   struct BT *p=Q.front();
                    Q.pop();
                    struct BT *left=NULL;
                    left=nn(head->data);
                    struct BT *right=NULL;
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
void inorder(struct BT *root)
    {
        if(root)
            {
            
                inorder(root->l);
                cout<<root->data<<"\t";
                inorder(root->r);
            
            }
    
    
    }    
    
    
