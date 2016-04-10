#include<iostream>

using namespace std;


class T
    {
        public:
            static int a;
            
           T()
            {
                cout<<a++<<"\t";
            } 
    
    
    }
int T::a=0;

main()
    {
    
        int N=100;
        
        T t[N];
    
    }    
    
