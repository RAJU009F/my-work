#include<iostream>
#include<queue>
using namespace std;

struct BT 
    {
        struct BT *l;
        struct BT *r;
        
        int data;
    };
    
struct BT *nn(int d);
        
 int Height(struct BT *);   
    
  main()
    {
        struct BT *rt=NULL;
        
        rt=nn(4);
        rt->l=nn(5);
        rt->r=nn(7);
        rt->l->r=nn(9);
        rt->r->l=nn(10);
        rt->r->r=nn(11);
        rt->l->r=nn(12);
        rt->r->r->l=nn(45);
        rt->r->l->l=nn(110);
       cout<<"\nHeight::"<<Height(rt)<<endl;
    
    }  
    
 struct BT *nn(int d)
    {
    
        struct BT *root=new BT;
        root->data=d;
        root->l=NULL;
        root->r=NULL;
        
        return root;
    
    }   
    
    
 int Height(struct BT *root)
    {
    
        if(!root)
            return 0;
            
         int h=0;
         queue<BT *>Q;
         Q.push(root);
         while(1)
            {
                int nodecount=Q.size();
                if(nodecount==0)
                    return h;
                h++;
                
                
                while(nodecount>0)
                    {
                    
                        struct BT *temp=Q.front();
                        Q.pop();
                        if(temp->l)
                            Q.push(temp->l);
                        if(temp->r)
                            Q.push(temp->r);
                           
                         nodecount--;       
                    
                    }             
            }    
    }   
