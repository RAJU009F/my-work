#include<iostream>
using namespace std;
class index
	{
		int x;
		
		public:
		
			index(int i)
				{
					x=i;
				}
			index()
				{
					x=0;
				
				}
			index operator ++()
				{
					++x;
					return index(x);
					
				}		
				
			index operator ++(int)
				{
					x++;
					//return index(x);
					return *this;
				                   
				}	
		void display()
			{
			
				cout<<"x="<<x<<endl;
			
			}
	
	
	};
main()
	{ 
	
		index c,a,b;
		
		index d=c++;
		d.display();
		c.display();
			
		
	
	
	}
