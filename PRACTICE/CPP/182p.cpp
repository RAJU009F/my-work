#include<iostream>
using namespace std;

class A
    {
    int x;
    public:
        void setx(int i)
        {
            x=i;
        }
        void print()
            {
            
                cout<<x<<endl;
            }
    };
    
class B:virtual public A
    {
        
        public:
          B()
            {
                setx(67);
            }      
        
    
    } ;
    
 class C:virtual public A
    {
        public:
           C()
            {
                setx(23);
            }
    };   
class D:public C,public B
    {
    
            
    };    
    
 int main()
    {
        D d;
        d.print();
    
        return 0;
    }   
