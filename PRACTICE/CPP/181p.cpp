/*Diomond problem of inheritance*/
#include<iostream>

using namespace std;

class A
    {
       public:
        A(int x)
            {
                cout<<"A Nax:\n";
            
            }
         A()
            {
                cout<<"A default C\n";
            
            }   
         ~A()
            {
            
                cout<<"A D\n";     
            
            }   
            
    
    };
 class B:virtual public A
    {
        public:
            B(int x):A(x)
                {
                    cout<<"B Nax\n";
                
                }
             ~B()
                {
                    cout<<"B Des\n";
                }   
    
    };   
 class C: virtual public A
    {
        public:
        C(int x):A(x)
            {
                cout<<"C Nax x\n";
            }
            
        ~C()
            {
            
                cout<<"C D\n";
            }
    }; 
 class D:B,C
 {
        public:
            D(int x):B(x),C(x),A(x)
                {
                
                    cout<<"D Nax\n";
                }
            ~D()
                {
                
                    cout<<"D Des\n";
                }    
 
 
 };   
 main()
    {
        D d(56);
        
    }     
