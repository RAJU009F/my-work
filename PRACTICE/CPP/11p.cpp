#include<iostream>
using namespace std;
int rev(int );
int sum(int);

int main()
	{
		int n;
		cout<<"Enter a number";
		cin>>n;
		cout<<"\nSum is:"<<sum(n);
		cout<<"\nRev is:"<<rev(n);
		cout<<"\n";
	
	
	
	
	}	
	
int rev(int x)
	{
		int r=0;
		while(x>0)
			{
			r=r*10+x%10;
			x=x/10;

			}
			
		return r;	
	
	
	
	
	}	
	
int sum(int x)
	{
		int sum=0;
		while(x>0)
			{
				sum=sum+x%10;
				x=x/10;
			
			}
		return sum;
	
	
	
	
	}	
