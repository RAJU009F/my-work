#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void swap(char *a, char *b)
    {
        
        char t=  *a;
        *a = *b;
        *b = t;
        
    }
void printNextGreaterN(char num[])
    {
        int n = strlen(num)-1;
        
        int i, j;
        
        for(i=n; i>0; i--)
            {
                if(num[i]>num[i-1])
                    break;
                
            }
        if(i==0)
            {
                cout<<"not possible";
                return;
            }
        int smallest = i;    
        for(j=i+1; j<=n; j++)
            {
                if(num[i-1]<num[j] && num[j]<num[smallest])
                        smallest = j;
                
            }
        swap(&num[i-1], &num[smallest]);
        
        sort(num+i, num+n+1);        

        cout<<num;
        
    }
int main() {
	int T;
	cin>>T;
	char num[50];
	while(T>0)
	{
	   cin>>num;
	   printNextGreaterN(num);
	   cout<<endl;
	    
	    T--;
	}
	
	return 0;
}
