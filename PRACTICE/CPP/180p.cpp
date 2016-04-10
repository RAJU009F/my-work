
#include<iostream>

using namespace std;

class T
    {
        int *ptr;
       public:
        T(int i=0){ptr=new int(i);} 
       T & operator=(const T &t);
         
       
        void setv(int i)
            {
                *ptr=i;
            }
        void print()
            {
                cout<<*ptr<<endl;
            }
    
    };

T & T::operator=(const T &t)
    {
     if(this!=&t)
            *ptr=*(t.ptr);
      return *this;
    } 

main()
    {
        T t1(5);
        T t2;
        t2=t1;
        t1.setv(7);
        t2.print();
    
    
    }
