#include<iostream>

using namespace std;

class S
    {
        public:
            static int n;
            
            S()
                {
                    n++;                               
                }  
                
             ~S()
                {
                    n--;
                
                }   
    
    
    
    };

int S::n=0;


int main()
    {
        S s;
        S s1[9];
        S *c=new S;
        cout<<S::n<<endl;
        delete c;
        cout<<s.n<<endl;
    
    
    }
    
