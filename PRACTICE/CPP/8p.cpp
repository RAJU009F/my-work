#include<iostream>
using namespace std;

int main()
	{
		int N=10;
		for(int i=0;i<=2*N;i++)
			{
				for(int j=0;j<=2*N;j++)
					{
						if(i==j || j==2*N-i)
							cout<<"*";
							
						else
							cout<<" ";	
					
					
					}
				cout<<"\n";
			
			
			}
	
	
	
	
	
	}	
