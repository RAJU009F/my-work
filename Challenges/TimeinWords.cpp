#include <iostream>
using namespace std;

int main() {
	
	int H, M;
	char const* Voice[20] = {"one", "two", "three", "four", "five", "six", "seven", 
	"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter",
	"sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

	cin>>H;
	cin>>M;
	if (H<1 || H>11 || M<0 || M>60)
	    return 0;
    if(M == 0)
        {
            cout<<Voice[H-1]<<" o' clock"<<endl;
            
        }
    else if(M>30)
        {
            if(M == 45)
                {
                    cout<<"quarter to "<<Voice[H];
                }
            else
            {
                int diff = 60-M;
                if(diff ==1)
                    {
                        cout << Voice[diff-1]<<" minute to " <<Voice[H];
                    }else if(diff == 10 )
                    {
                        
                        cout << Voice[diff-1]<<" minutes to " <<Voice[H];
                    }
                else if(diff>20)    
            
                    {
                        cout<< Voice[diff-diff%10]<<" "<< Voice[diff%10] <<" minutes to "<<Voice[H];
                        
                    }
                else
                {
                    cout<<Voice[diff-1]<< " minutes to "<<Voice[H];
                }
                
            }
            
        }
        else if(M ==30)
         {
                    cout << "half past "<<Voice[H-1]; 
                    
                }else
                
        {
           // if(M == 30)
               
            if(M == 15 )
                {
                    
                    cout << Voice[M-1] << " past " << Voice[H-1];
                }
            else if(M <=20)
                {
                    if(M==1)
                        {
                              cout << Voice[M-1] << " minute past " << Voice[H-1];
                        }
                    else
                    {
                        cout << Voice[M-1] << " minutes past " << Voice[H-1];
                    }
                    
                }else
                {
                    cout<<Voice[M-M%10] <<" " <<Voice[M%10-1]<< " minutes past "<<Voice[H];
                }
            
            
            
        }
	    
	
	return 0;
}