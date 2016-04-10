#include<iostream>



using namespace std;

class complex 
	{
		private:
		
			int real;
			int imag;
		
		public:
		
			complex()
				{
					real=0;
					imag=0;
				
				}
			complex(int x,int y);
			void set_c(int x,int y);	
			void display();
			complex operator +(complex);
			complex operator -(complex);
			complex operator *(complex);

		};
		
		
complex::complex(int x,int y)
	{
		real=x;
		imag=y;
	
	}		
	
complex complex::operator +(complex c)
	{
		complex t;
		t.real=real+c.real;
		t.imag=imag+c.imag;
		
		return t;
	
	
	}	
complex complex::operator -(complex c)
	{
		complex t;
		t.real=real+c.real;
		t.imag=imag+c.imag;
		
		return t;
	
	
	
	}	
complex complex::operator *(complex c)
	{
		complex t;
		t.real=real*c.real-imag*c.imag;
		t.imag=real*c.imag+imag*c.real;
		return t;
	
	
	}	
void complex::set_c(int x,int y)
	{
	
		real=x;
		imag=y;
	
	}	
void complex::display()
	{
		cout<<"\n"<<real<<" "<<imag<<"i"<<"\n\n";
	
	
	
	}	
	
	
main()
	{
	
		complex c1;
		complex c2(20,40);
		
		c1.set_c(40,70);
		
		complex c =c1+c2;
		
		c=c+c-c1*c2;
		
		c.display();
	
	
	
	
	}
