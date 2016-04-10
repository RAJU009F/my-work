#include<iostream>

using namespace std;

class D
    {
    public:
        int ist(D&);
    
    };
    
  int D::ist(D& p)
    {
        if(this==&p)
            return 1;
          else
            return 0;  
    
    
    }  

int main()
    {
        
    D a;
    D* b=&a;
    if(b->ist(a))
        cout<<"yes \n";
    
    
    
    }
