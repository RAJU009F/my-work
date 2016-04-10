#include<iostream>

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
					return index(x);
				
				}	
		void dispaly()
			{
			
				cout<<"x="<<x<<endl;
			
			}
	
	
	};
main()
	{
	
		index c,a,b;
		
		index d=c++;
		d.dispaly();
		c.display();
			
		
	
	
	}
