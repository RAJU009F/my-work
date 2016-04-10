#include<iostream>

using namespace std;


class op
    {
        
        public:
        int x,y;
        op(){x=0;y=0;}
        op(int ,int);
        op operator + (op);
    
    
    };
    
  op::op(int a, int b)
    {
    x=a;
    y=b;
    
    
    }  
    
   op op::operator+ (op param)
    {
        op temp;
        temp.x=x+param.x;
        temp.y=y+param.y;
        return(temp);
    
    
    } 
    
 int main()
 
    {
    
    op p(1,5);
    op p1(4,0);
    op p2;
    p2=p+p1;
    
        cout<<": p2.x="<<p2.x<<"p2.y="<<p2.y<<endl;
   op p3;
    p2=p+p3;
    cout<<"2: p2.x="<<p2.x<<"p2.y="<<p2.y<<endl;
    op p4;
    p4=p;
    cout<<"3:p2.x="<<p4.x<<"p2.y="<<p4.y<<endl;
    
    }   
