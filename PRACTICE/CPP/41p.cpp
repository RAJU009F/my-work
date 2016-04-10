#include<iostream>

using namespace std;


class mother
    {
    
        public:
        mother()
            {
                cout<<"mother:: no paprameters"<<endl;
               
            }
        mother(int a)
            {
            
            cout<<"Mother: int paprameter"<<endl;
           
            
            }
    
    
    
    };
    
    
class son:public mother
    {
        public:
             son(int a):mother( a)
                {
                    cout<<"son: int parameter"<<endl;
                  
                
                }
        
    
    
    };    
    
  class daughter:public mother
    {
        public:
             daughter(int a)
                {
                
                    cout<<"daughter: int parameter"<<endl;
                    
                }
    
    };  
    
    
   int main()
    {
        son nax(0);
        daughter(0);
    
    
    } 
