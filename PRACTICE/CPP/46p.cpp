#include<iostream>


using namespace std;

class D
    {
    
    public:
    float i,j; 
    
    
    };

class A
    {
        int x,y;
        
        public:
            A(int a,int b)
                {x=a;
                   y=b;}
            int add()
                {
                    
                    return x+y;
                
                }
    
    };


int main()
    {
        D d;
        A *a=(A*) &d;
        cout<<a->add()<<endl;
    
    
    
    }
