#include<iostream>
using namespace std;

class Test
    {
     private :
     int x;
     int y;
     public:
        Test(int x=0,int y=0)
            {
                this->x=x;
                this->y=y;
             }   
        void change(Test *t)    
            {
                this->x=t->x;
            
            }
            
        Test setx(int a)
            {
                x=a;
                return *this;     
            
            }    
             Test sety(int b)
            {
                y=b;
                return *this;     
            
            }       
          void print()
            {
            
                cout<<"x="<<x<<endl;
                cout<<"y="<<y<<endl;
            
            } 
        static void fun1()
            {
                cout<<"fun1 called\n";
            } 
        static void fun2()
            {
                cout<<"inside fun2 \n";
                fun1();
            }        
        void destroy()
            {
                delete this;
            }    
    };
main()
    {
        Test obj(5);
        Test *ptr=new Test(10);
        obj.change(ptr);
        obj.print();
        Test o;
        o.fun2();
        
        Test::fun1();
        
      Test o2;
      o2.setx(10);
      o2.sety(10);
      o2.print();  
      o2.destroy();
    }
