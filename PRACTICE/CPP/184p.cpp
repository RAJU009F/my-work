#include<iostream>
using namespace std;

int &fun()
    {
        int x=56;
        
        return x;
    
    }
 int main()
    {
        int i=453;
        fun()=76;
        cout<<fun()<<endl;
        
    int *ptr=NULL;
    int &p=*ptr;
    cout<<p<<"\n";
    
    }   
