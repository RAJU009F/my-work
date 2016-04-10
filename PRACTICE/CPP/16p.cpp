#include<iostream>

using namespace std;

int s(int);
int main()
	{
		int n;
		cout<<"Enter n :\n";
		cin>>n;
		cout<<"Sum is:"<<s(n)<<endl;
	
	
	
	
	}	
	
int s(int n)
	{
		if(n==0)
			return 0;
		return n*n+s(n-1);	
	
	
	
	}	
