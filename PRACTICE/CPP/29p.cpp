#include<iostream>

using namespace std;


class rect
    {
        int x,y;
        public:
            void set_values(int ,int );
            int area();
    
    
    };
    
    
void rect::set_values(int a,int b)
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
        rect r;
        int a1,b1;
        cout<<"Enter the values for a and b:";
        cin>>a1>>b1;
        r.set_values(a1,b1);
        cout<<"\nArea of the rect:"<<r.area()<<endl;
        
        rect r2(r);
        cout<<"\nArea of the rect2:"<<r2.area()<<endl;
        
        
    
    
    } 
