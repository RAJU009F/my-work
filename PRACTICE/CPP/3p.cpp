#include<iostream>
using namespace std;


int main()
	{
	
		int N=4;
		for(int i=0;i<=2*N;i++)
			{
				for(int j=0;j<2*N;j++)
					{
						if(j==i)
							cout<<"*";
						else if(j==2*N-i)
							cout<<"*";
							
						else
							cout<<" ";	
					
					
					
					}	
			 	cout<<"\n";
			
			}
	
	
	
	
	}


