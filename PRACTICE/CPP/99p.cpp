/* revesre level order printing  */

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct BT
    {
        struct BT *l;
        struct BT *r;
        int data;
    
    };
struct BT *nn(int );
void rev_levelorder(struct BT *);
void levelorder(struct BT *,int);
int height(struct BT *);


int main()
    {
    
        struct BT *rt=nn(6);
        rt->l=nn(2);
        rt->l->l=nn(3);
        rt->l->r=nn(1);
        rt->r=nn(9);
        rt->r->l=nn(7);
        rt->r->r=nn(8);
    rev_levelorder(rt);
    
    cout<<"\n\n";
    for (int i=0;i<3;i++)
        levelorder(rt,i);
       cout<<"\n\n";    
    for(int i=2;i>-1;i--)
        levelorder(rt,i);    
    
    cout<<"Height:"<<height(rt)<<endl;
    }
    
 struct BT *nn(int d)
    {
        struct BT *root=new BT;
        root->data=d;
        root->l=root->r=NULL;
        
        return root;
    
    
    }   
    
void rev_levelorder(struct BT *root)    

    {
    
        if(!root)
            return;
            
        queue<BT *>Q;
        stack<BT *>S;    
           Q.push(root);
           
           while(Q.empty()==false)
            
            {
                root=Q.front();
                Q.pop();
               S.push(root);
                
               
                 if(root->r)
                    Q.push(root->r);   
                 
                 if(root->l)
                    Q.push(root->l);
            
            
            } 
            
         while(S.empty()==false)
            {
                root=S.top();
                cout<<"["<<root->data<<"]\t";
                S.pop();
            
            } 
    
    
    }
    
 void levelorder(struct  BT *root,int level) 
    {
        if(!root)
            return;
            
          if(level==0)
            cout<<"["<<root->data<<"]\t";
          
          levelorder(root->l,level-1);
          levelorder(root->r,level-1);  
    
    
    
    }  
    
int height(struct BT *root)
    {
        if(!root)
            return 0;
            
            
          queue<BT *>q;
          q.push(root);
          q.push(NULL);
          int level=0;
          
          while(!q.empty())
            {
                root=q.front();
                q.pop();
                if(root==NULL)
                    {
                        if(!q.empty())
                            q.push(NULL);
                        level++;   
                    }
                    
                 else
                 {      
                 if(root->l)
                    q.push(root->l);
                  if(root->r)
                    q.push(root->r);     
            
                }
            }
          
          
          return level;  
    
    
    
    
    }


