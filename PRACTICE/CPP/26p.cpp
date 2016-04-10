#include<iostream>

using namespace std;

void cv(int ,int);
void cr(int *,int *);

int main()
    {
        int a=4,b=2;
        
        cout<<"initial values:"<<a<<"\t"<<b<<endl;
        cv(a,b);
        cout<<"after cv call:"<<a<<"\t"<<b<<endl;
        cr(&a,&b);
        cout<<"after cr call:"<<a<<"\t"<<b<<endl;
    
    
    
    }
    
   void cv(int x,int y)
    {
        x=x^y;
        y=x^y;
        x=x^y;
    
    
    
    
    } 
    
void cr(int *x,int *y)
    {
        *x=*x^*y;
        *y=*x^*y;
        *x=*x^*y;
    
    
    
    
    } 
