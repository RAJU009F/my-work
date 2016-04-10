#include<iostream>
    
    
using namespace std;


class square
    {
        int s;
        
        public:
            void set_value(int);
            int area();
            friend class rect;
    
    
    };

class rect
    {
    int x,y;
    public:
        void set_values(int,int);
        void convert(square);
        int area();
    
    
    
    };

void square::set_value(int a)
    {
    
    s=a;
    
    }
    
int square::area()
    {
    
        return s*s; 
    }    
void rect::set_values(int a,int b)
    {
    
        x=a;
        y=b;
    
    }
 int rect::area()
    {
    
        return x*y;
    }   
void rect::convert(square ss)
    {
        x=ss.s;
        y=ss.s;
    
    
    }
    int main()
        {
            rect r1,r2,r3;
            square s1,s2;
            s1.set_value(10);
            r1.set_values(2,4);
            cout<<"square "<<s1.area()<<"  rect  "<<r1.area()<<endl;
        r2.convert(s1);
               cout<<"square "<<s1.area()<<"  rect  "<<r2.area()<<endl;
        
        
        }
