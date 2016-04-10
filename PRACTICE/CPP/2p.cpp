#include<iostream>
using namespace  std;

int main()

	{
	
		int N=5;
		
		for(int i=0;i<=2*N;i++)
			{
				for(int j=0;j<=2*N;j++)
					{
						if(i<=N)
						{	if(j<N-i || j>N+i)
								cout<<" " ;
							
							else
								cout<<"*";	
						
					
						}
						else
							{
								if(j<i-N || j>3*N-i)
									cout<<" ";
								else
									cout<<"*";	
							
							
							
							}
						
							
					}
				cout<<"\n";	
			
			}
	
	
	
	
	}

