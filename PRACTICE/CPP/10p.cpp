#include<iostream>
using namespace std;
void swap(int& ,int&);
int main()
	{
		
	int a,b;
	cout<<"Enter two numbers:";
	cin>>a>>b;
	cout<<"\nBefore a="<<a<<"b="<<b;
	swap(a,b);
	cout<<"\nAfter a="<<a<<"b="<<b;
	
	
	
	}	
	
void swap(int& x,int& y)
	{
		x=x^y;
		y=y^x;
		x=x^y;
		
	
	
	}	
