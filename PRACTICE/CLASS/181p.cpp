#include<iostream>

using namespace std;

class A
    {
       public:
        A()
            {
                cout<<"A Nax:\n";
            
            }
         ~A()
            {
            
                cout<<"A D\n";     
            
            }   
            
    
    };
 class B
    {
        public:
            B()
                {
                    cout<<"B Nax\n";
                
                }
             ~B()
                {
                    cout<<"B Des\n";
                }   
    
    };   
 class C:  A,   B
    {
        public:
        C()
            {
                cout<<"C Nax\n";
            }
        ~C()
            {
            
                cout<<"C D\n";
            }
    }; 
    
 main()
    {
        C c;
        
    }     
