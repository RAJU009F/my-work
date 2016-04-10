#include<iostream>
using namespace std;
int b(int ,int);
int p(int,int);
int c(int,int);

int main()
	{
	int n;
	cout<<"Enter the n value:\n";
	cin>>n;
	
	for(int k=0;k<=n;k++)
		cout<<b(n,k)<<"\t";
	
	cout<<"\n"<<p(n,3)<<"\n";
	cout<<"\n"<<c(n,3)<<"\n";
	
	
	
	
	
	}
	
int b(int n,int k)
	{
		if(k==0 || k==n)
			return 1;
		return b(n-1,k-1)+b(n-1,k);	
	
	}	
	
int p(int n,int k)
	{
		int p=1;
		for(int i=0;i<k;i++)
			p*=(n-i);
		return p;	

	}
		
int c(int n,int k)
	{
		int c=1;
		for(int i=1;i<=k;i++)
			c*=(n-i+1)/i;
			
		return c;	
	
	
	
	}		
		
