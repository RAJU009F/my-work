#include<iostream>
using namespace std;

int main()
	{
		const int N=6;
		int i,j;
		
		for(i=0;i<2*N;i++)
			{
				for(j=0;j<2*N;j++)
					{
						if(i<=N)
							{
							
								if(j<N-i||j>N+i)
									cout<<"  ";
								else
									cout<<" * ";
										
							
							}
						if(i>N)
							{
							
								if(j<i-N||j<3*N-i)
									cout<<"  ";
								else
									cout<<" * ";	
							
							
							}	
						
					
					
					}
					
			
			
			}
		
	
	
	
	
	}
