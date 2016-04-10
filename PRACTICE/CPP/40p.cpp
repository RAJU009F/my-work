#include<iostream>

using namespace std;

class poly
    {
       public:
        int w,h;
        public:
           void  set_values(int ,int);
    
    
    };
    
class rect:public poly
    {
        public:
            int area();
    
    
    };    
    
class tri:public poly
    {
        public:
            int area();
    
    };    
    
    
int rect::area()
    {
    
    return w*h;
    
    }   
    
int tri::area()
    {
        
        return (w*h)/2;
    
    }   
void poly::set_values(int a,int b)
    {
        w=a;
        h=b;
    
    
    }    
    
    
   int main()
    {
    
        rect r;
        tri t;
        r.set_values(3,4);
        t.set_values(3,4);
        cout<<"rect "<<r.area()<<"triangle: "<<t.area()<<endl;
    
    
    
    } 
