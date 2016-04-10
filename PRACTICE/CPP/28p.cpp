#include<iostream>


using namespace std;

int op(int ,int);

int main()
    {
        int (*p) (int ,int);
        
        int a=4,b=9;
        p=op;
        cout<<p(a,b)<<endl;
        cout<<(p)(a,b); 
    
    }


int op(int x,int y)
    {
        return x*y;
    
    
    
    }


