#include<iostream>
#include<iomanip>
using namespace std;

const int R=3,C=3;
struct M
	{
		int A[R][C];
	
	
	};
M operator +(M,M);
M operator -(M,M);
M operator *(M,M);	
void print(M); 
	
main()
	{
		M a={34,56,343,67,232,687,23,55,121};
		M b={45,677,878,43,78,232,232,887,6};
	
		
		M c,d,e,f;
		
		c=a+b;
		
		print(a);
		cout<<"\n\n";
		
		print(b);
		cout<<"\n\n";
		d=a-b;
		print(c);
		cout<<"\n\n";
		
	
	
	
	
	}	
M operator +(M a,M b)
	{
		int i,j;
		M c;
		
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				{
					c.A[i][j]=a.A[i][j]+b.A[i][j];
				
				
				}
	
	
		return c;
	}	
M operator -(M a,M b)	
	{
		int i,j;
		M c;
			
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				{
					c.A[i][j]=a.A[i][j]-b.A[i][j];
				
				
				}
	
	
		return c;
	
	
	
	}
M operator *(M a,M b)
	{
		int i,j,k;
		M c;
		
		for(i=0;i<R;i++)
			{
				for(j=0;j<C;j++)
					{
						c.A[i][j]=0;
						
						for(k=0;k<R;k++)
							c.A[i][j]+=a.A[i][k]*b.A[k][j];
					
					
					
					}
			
			
			
			}
	
		return c;	
	
	}	
	
void print(M a)
	{
		for(int i=0;i<R;i++)
		
			{	
				cout<<endl;
				for(int j=0;j<C;j++)
					{
						cout<<"\t"<<a.A[i][j];
					
					
					
					}
			
			}
	
	
	
	}
