/*finding height of the tree*/

#include<iostream>

#include<queue>

using namespace std;

struct BT 
    {
        struct BT *l;
        struct BT *r;
        int data;
    };
struct BT *nn(int) ;

int height(struct BT *);
   
    
    

int main()
    {
        
    struct  BT *rt=nn(6);
        rt->l=nn(7);
        rt->r=nn(8);
        rt->r->l=nn(9);
        rt->r->r=nn(877);
        rt->r->r->r=nn(454);
        
        cout<<height(rt)<<endl;
        
    
    
    
    }
    
struct BT *nn(int d)
    {
        struct BT *root=new BT;
        root->data=d;
        root->l=root->r=NULL;
        return root;
    
    
    
    }    
    
    
 int height(struct BT *root)
    {
        if(!root)
            return 0;
            
          queue<BT *>Q;
          Q.push(root);
            int h=0;
            
            while(1)
                    {
                        int nodecount=Q.size();
                        if(nodecount<=0)
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
