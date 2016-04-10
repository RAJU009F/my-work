#include<iostream>
#include<stdlib.h>

using namespace std;

struct complex
	{
		int real,imag;
	
	};
void xxx(int a);
void xxx(const int);
	
	
complex set_c(int,int );
complex operator +(complex,complex);
complex operator -(complex,complex);
void print_c(complex); 
main()
	{
		int a=90;
		int b=20;
		complex C1=set_c(a,b);
		print_c(C1);
		a=67;
		b=45;
		complex C2=set_c(a,b);
		print_c(C2);
		C2=C1+C2;
		
		print_c(C2);
		C2=C2-C1;
		print_c(C2);
		int i=10;
		int const j=90;
	xxx(i);
	xxx(j);
	}
complex set_c(int r,int i)
	{
		complex T;
		T.real=r;
		T.imag=i;
		
		return T;
	
	
	}	
	
complex add_c(complex a,complex b)
	{
	
		complex T;
		
		T.real=a.real+b.imag;
		T.imag=a.imag+b.imag;
		
		return T;
	
	
	}
void print_c(complex C)
	{
	
		cout<<C.real<<"+i"<<C.imag<<endl;
	
	}	
	
complex operator +(complex a,complex b)
	{
		complex T;
		T.real=a.real+b.real;
		T.imag=a.imag+b.imag;
		
		return T;
	
	
	}	
void xxx(int a)
	{
		cout<<a<<endl;
		
	
	}	
void xxx( const int b)
	{
	
		cout<<b<<endl;
	}	
	
	
complex operator -(complex a,complex b)
	{
		complex T;
		T.real=a.real-b.real;
		T.imag=a.imag-b.imag;
		
		return T;
	
	
	}	
		
