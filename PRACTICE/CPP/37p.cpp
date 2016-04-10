#include<iostream>

using namespace std;

class R
    {
    int w,h;
    public:
        friend R dup(R);
        void set_values(int,int);
        int area();
            
    };

R dup(R r)
    {
    R t;
    t.w=r.w*2;
    t.h=r.h*2;
    return t;       
    }
    
void R::set_values(int a,int b)
    {
        w=a;
        h=b;
    
    }  
     
 int R::area()
    {
        return w*h;
    
    }    


int main()
    {
        R rr;
        rr.set_values(6,7);
        cout<<rr.area()<<endl;
        R rrr;
        rrr=dup(rr);
        cout<<rrr.area()<<endl;
        
    
    
    }    
