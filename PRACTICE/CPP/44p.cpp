#include<iostream>

using namespace std;


template <class T>
   T getmax(T a, T b)
        {
            T r;
            r=a>b?a:b;
            return r;
        
      
        
        }


int main()
    {
        int i=6,j=9;
        long k=454,l=565;
        cout<<"max int :"<<getmax<int>(i,j)<<endl;
        cout<<"max long:"<<getmax<long>(656,56464363643)<<endl;
        cout<<"max char:"<<getmax<char>('r','R')<<endl;
        cout<<"max string:"<<getmax<string>("indian","hitler")<<endl;
    
    
    }
