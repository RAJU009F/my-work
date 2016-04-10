//  *   polymorphism    *//

#include<iostream>

using namespace std;

class poly
    {
        protected:
            int w,h;
        public:
            void set_values(int ,int);
          virtual  int area()
                {
                    return 0;
                }
         
            
    
    };
 void poly::set_values(int a,int b)
    {
        w=a;
        h=b;        
    }   
class tri:public poly
    {
        public:
            int area()
                {
                    return w*h/2;
                }
    
    };
class rect:public poly
    {
        public:
            int area()
                {
                    return w*h;
                
                }
    
    };    
int main()
    {
        rect r;
        tri t;
        poly *p1=&r;
        poly *p2=&t;
        p1->set_values(3,4);
        p2->set_values(4,6);
        cout<<p1->area()<<endl;
        cout<<p2->area()<<endl;
                
    
    
    }    
    
    
