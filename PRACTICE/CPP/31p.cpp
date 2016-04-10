#include<iostream>


using namespace std;

class rect
    {
    int x,y;
    public:
        rect(int , int);
        ~rect();
        int area();
    
    
    
    };
 rect::~rect()
    {
    
    
    }
       
rect::rect(int a,int b)
    {
        x=a;
        y=b;        
    }
int rect::area()
    {
        return x*y;
    
    
    }    


int main()
    {
        int a1,b1;
       
        cout<<"Enter values for a and b:";
        cin>>a1>>b1;
        rect r(a1,b1);
       cout<<"area is:"<<r.area()<<endl;
    }
