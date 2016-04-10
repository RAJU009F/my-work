//  * multiple inheritance      *  //

#include<iostream>

using namespace std;

class poly
    {
    
       protected:
        int w,h;
       public:
        void set_values(int ,int); 
    
    
    
    };

void poly::set_values(int a,int b)
    {
        w=a;
        h=b;        
    }
    
class out
    {
        public:
        void output(int );
    
    };    
    
void out::output(int o)
    {
        cout<<"Result is:"<<o<<endl;
    
    
    }    
class rect:public poly,public out
    {
        public:
       int area()
        {
            return w*h;
        
        
        }
    
    
    
    };  
    
 class tri:public poly,public out
    {
        public:
            int area()
                {
                
                    return (w*h)/2;
                }
    
    };
int main()
    {
        rect r;
        r.set_values(4,5);
        
        tri t;
        t.set_values(6,7);
        
        t.output(t.area());
        r.output(r.area());    
    
    
    }    
       
    
      
    
    
