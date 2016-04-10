#include<iostream>

using namespace std;


class A
	{
		int x;
		public:
			A()
				{
					x=0;
				}
				
		void show();		
	
	};
class B : public A
	{
		int y;
		public:
			B()
				{
					y=0;
				}
			
		
	
	};
void A:: show()
	{
		B b;
		cout<<b.x<<endl;
	
	
	
	}	
	
	
	main()
		{
			show();
			
			
			
		
		}
