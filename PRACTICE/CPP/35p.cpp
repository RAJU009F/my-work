#include<iostream>

using namespace std;

class E
    {
    public:
    int x,y;
    
    E(){x=0;y=0;}
    E(int , int);
    E(E&);
    
    E operator + (E);
    
    };
 E::E(int a,int b)
    {
        x=a;
        y=b;  
    }   
  E::E(E& p)
    {
    x=p.x;
    y=p.y;
    
    }  
    
   E E::operator+(E p)
    {
        E t;
        t.x=x+p.x;
        t.y=y+p.y;
        return t;
        
    } 
    
    


int main()
    {
    
    E e1(5,5);
    E e2(6,6);
    E e;
    e=e1+e2;
    
    cout<<" e.x= "<<e.x<<" e.y= "<<e.y<<endl;
    E e3;
    e3=e1;
    E e4;
    e4=e+e3;
     cout<<" e.x= "<<e4.x<<" e.y= "<<e4.y<<endl;
     
     E e5(e2);
      cout<<" e.x= "<<e5.x<<" e.y= "<<e5.y<<endl;
     
    }
